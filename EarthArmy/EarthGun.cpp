#include "EarthGun.h"
#include"../Game/game.h"
EarthGun::EarthGun(game* master) : unit(master)
{
	set_type(EG);
}

void EarthGun::attack()
{
	
	AlienArmy* attackedArmy = g->getAlienArmy();
	unit* attackedUnit = nullptr;
	tempList tmp;
	int attackedCnt = 0;
	bool AMremain = true;
	bool ADremain = true;
	for (int i = 0; i < attackCap/2; i++)
	{
		attackedArmy->pickMonster(attackedUnit);
		if (attackedUnit)
			tmp.insert(attackedUnit);
		else
		{
			AMremain = false;
			break;
		}
		attackedUnit = nullptr;
	}
	attackedCnt = tmp.getCount();
	for (int i = 0; i < (attackCap - attackedCnt); i++)
	{
		if (i % 2 == 0)
			attackedArmy->pickFrontDrone(attackedUnit);
		else
			attackedArmy->pickEndDrone(attackedUnit);
		if (attackedUnit)
			tmp.insert(attackedUnit);
		else
		{
			ADremain = false;
			break;
		}
		attackedUnit = nullptr;
	}
	attackedCnt = tmp.getCount();
	if (attackedCnt != attackCap and !ADremain)
	{
		for (int i = 0; i < attackCap -attackedCnt; i++)
		{
			attackedArmy->pickMonster(attackedUnit);
			if (attackedUnit)
				tmp.insert(attackedUnit);
			else
			{
				AMremain = false;
				break;
			}
			attackedUnit = nullptr;
		}
	}
	else if (attackedCnt != attackCap and !AMremain)
	{
		for (int i = 0; i < (attackCap - attackedCnt); i++)
		{
			if (i % 2 == 0)
				attackedArmy->pickEndDrone(attackedUnit);
			else
				attackedArmy->pickFrontDrone(attackedUnit);
			if (attackedUnit)
				tmp.insert(attackedUnit);
			else
			{
				ADremain = false;
				break;
			}
			attackedUnit = nullptr;
		}
	}
	attackedCnt = tmp.getCount();
	if (g->get_mode() == 1)
		tmp.print(this);

	for (int i = 0; i < attackedCnt; i++)
	{
		tmp.remove(attackedUnit);
		if (attackedUnit->get_Noofattacked() == 0) {
			attackedUnit->set_atackedTime(g->getCurrTimeStep());
		}
			attackedUnit->set_Noofattacked(1 + attackedUnit->get_Noofattacked());
		this->set_attackpower(attackedUnit);
		attackedUnit->set_health(attackedUnit->get_health() - this->get_attackpower());
		if (attackedUnit->get_health() <= 0)
		{
			g->insertKilled(attackedUnit);
			attackedUnit->set_distructionTime(g->getCurrTimeStep());
		}
		else
			tmp.insert(attackedUnit);
	}
	while (tmp.remove(attackedUnit))
		attackedArmy->addUnit(attackedUnit);
}
