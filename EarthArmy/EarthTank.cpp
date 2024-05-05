#include "EarthTank.h"
#include"../game.h"
#include"../tempList.h"

bool EarthTank::attackAS = false;

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
	int armySolsPerc =  (attackingArmy->getListCnt(ES) * 100) / (attackedArmy->getListCnt(AS));
	bool ASremain = true;//army still have AS
	bool AMremain = true;//army still have AM

	if (armySolsPerc < 30)
		attackAS = true;
	if (attackAS)
	{
		if (armySolsPerc > 80)
			attackAS = false;
	}
	unit* attackedUnit = nullptr;
	tempList tmp;
	for (int i = 0; i < attackCap; i++) {
		if (!attackAS and AMremain ){//Not considering it until ES becomes 80%
			if (!attackedArmy->pickMonster(attackedUnit))
			{
				AMremain = false;
				break;
			}
			else 
			{
				this->set_attackpower(attackedUnit);
				attackedUnit->set_health(attackedUnit->get_health() - this->get_attackpower());
				if (attackedUnit->get_health() <= 0)
					g->insertKilled(attackedUnit);
				else
					tmp.insert(attackedUnit);
			}
		}
		else
		{
			attackAS = true;
			if (!attackedArmy->pickSoldier(attackedUnit))
			{
				break;
				ASremain = false;
			}
			else if(ASremain)
			{
				this->set_attackpower(attackedUnit);
				attackedUnit->set_health(attackedUnit->get_health() - this->get_attackpower());
				if (attackedUnit->get_health() <= 0)
					g->insertKilled(attackedUnit);
				else
					tmp.insert(attackedUnit);
			}
			if (!ASremain)
				attackAS = false;
		}
	}
	while (tmp.remove(attackedUnit))
		attackedArmy->addUnit(attackedUnit);
}

