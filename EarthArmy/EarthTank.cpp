#include "EarthTank.h"
#include"../game.h"
#include"../tempList.h"
EarthTank::EarthTank(game* master) : unit(master)
{
	set_type(ET);
	initialHealth = joinTime = health = power = attackCap = id = 0;
}
void EarthTank::attack()
{
	AlienArmy* attackedArmy = g->getAlienArmy();
	EarthArmy* attackingArmy = g->getEarthArmy();
	int armyCnt = g->getEArmyCnt();
	int enemyCnt = g->getAArmyCnt();
	int armySolsPerc = ((attackingArmy->getListCnt(ES)) / armyCnt) * 100;
	int enemySolsPerc = ((attackedArmy->getListCnt(AS)) / enemyCnt) * 100;
	unit* attackedUnit = nullptr;
	tempList tmp;
	for (int i = 0; i < attackCap; i++) {
		if (armySolsPerc > 30){//Not considering it until ES becomes 80%
			if (!attackedArmy->pickMonster(attackedUnit))
				break;
			else {
				this->set_attackpower(attackedUnit);
				attackedUnit->set_health(attackedUnit->get_health() - this->get_attackpower());
				if (attackedUnit->get_health() <= 0)
					g->insertKilled(attackedUnit);
				else
					tmp.insert(attackedUnit);
			}
		}
		else{
			if (!attackedArmy->pickSoldier(attackedUnit))
				break;
			else{
				this->set_attackpower(attackedUnit);
				attackedUnit->set_health(attackedUnit->get_health() - this->get_attackpower());
				if (attackedUnit->get_health() <= 0)
					g->insertKilled(attackedUnit);
				else
					tmp.insert(attackedUnit);
			}

		}
	}
	while (tmp.remove(attackedUnit))
		attackedArmy->addUnit(attackedUnit);
}

