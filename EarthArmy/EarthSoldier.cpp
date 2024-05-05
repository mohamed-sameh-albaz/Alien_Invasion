#include "EarthSoldier.h"
#include"../game.h"
#include"../tempList.h"
EarthSoldier::EarthSoldier(game* master) : unit(master)
{
	set_type(ES);
	initialHealth = joinTime = health = power = attackCap = id = 0;
}

void EarthSoldier::attack()
{
	AlienArmy* attackedArmy = g->getAlienArmy();
	unit* attackedUnit = nullptr;
	tempList tmp;
	for (int i = 0; i < attackCap; i++)
	{
		if (!attackedArmy->pickSoldier(attackedUnit))
			break;
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
	while (tmp.remove(attackedUnit))
		attackedArmy->addUnit(attackedUnit);
}
