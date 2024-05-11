#include "EarthGun.h"
#include"../game.h"
#include"../tempList.h"

EarthGun::EarthGun(game* master) : unit(master)
{
	set_type(EG);
	initialHealth = joinTime = health = power = attackCap = id = 0 ;
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
			attackedCnt = tmp.getCount();
			AMremain = false;
			break;
		}
		attackedUnit = nullptr;
	}
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
			attackedCnt = tmp.getCount();
			ADremain = false;
			break;
		}
		attackedUnit = nullptr;
	}
	if (AMremain and !ADremain)
	{
		for (int i = 0; i < attackCap -attackedCnt; i++)
		{
			attackedArmy->pickMonster(attackedUnit);
			if (attackedUnit)
				tmp.insert(attackedUnit);
			else
			{
				attackedCnt = tmp.getCount();
				AMremain = false;
				break;
			}
			attackedUnit = nullptr;
		}
	}
	else if (!AMremain and ADremain)
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
				attackedCnt = tmp.getCount();
				ADremain = false;
				break;
			}
			attackedUnit = nullptr;
		}
	}
	tmp.print(get_type(), id);

	for (int i = 0; i < attackedCnt; i++)
	{
		tmp.remove(attackedUnit);
		this->set_attackpower(attackedUnit);
		attackedUnit->set_health(attackedUnit->get_health() - this->get_attackpower());
		if (attackedUnit->get_health() <= 0)
			g->insertKilled(attackedUnit);
		else
			tmp.insert(attackedUnit);
	}
	while (tmp.remove(attackedUnit))
		attackedArmy->addUnit(attackedUnit);
}
