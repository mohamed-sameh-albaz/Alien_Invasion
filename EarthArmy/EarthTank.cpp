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
	int armySolsPerc = (attackingArmy->getListCnt(ES) * 100) / (attackedArmy->getListCnt(AS));
	bool ASremain = true;//army still have AS
	bool AMremain = true;//army still have AM

	if (armySolsPerc <= 30)
		attackAS = true;
	if (attackAS)
	{
		if (armySolsPerc >= 80)
			attackAS = false;
	}
	unit* attackedUnit = nullptr;
	tempList tmp;
	if (!attackAS and AMremain) {//Not considering it until ES becomes 80%

		for (int i = 0; i < attackCap; i++)
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
	else if (attackAS)
	{
		if(AMremain)
		{
			for (int i = 0; i < attackCap / 2; i++)//pick 50% of the list monsters
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

		for (int i = 0; i < attackCap - tmp.getCount(); i++)//pick 50% of the list AS
		{
			attackedArmy->pickSoldier(attackedUnit);
			if (attackedUnit)
				tmp.insert(attackedUnit);
			else
			{
				ASremain = false;
				break;
			}
			attackedUnit = nullptr;
		}

		if (!AMremain)//if monsters in the army is empty complete the list with AS
		{
			for (int i = 0; i < attackCap - tmp.getCount(); i++)
			{
				attackedArmy->pickSoldier(attackedUnit);
				if (attackedUnit)
					tmp.insert(attackedUnit);
				else
				{
					ASremain = false;
					break;
				}
				attackedUnit = nullptr;
			}
		}

		else if (!ASremain and AMremain)//if AS army is empty complete the list with AM
		{
			for (int i = 0; i < attackCap - tmp.getCount(); i++)
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
	}
	
	tmp.print(get_type(), id);

	for (int i = 0; i < tmp.getCount(); i++)
	{
		tmp.remove(attackedUnit);
		this->set_attackpower(attackedUnit);
		attackedUnit->set_health(attackedUnit->get_health() - this->get_attackpower());
		if (attackedUnit->get_health() <= 0)
			g->insertKilled(attackedUnit);
		else
			tmp.insert(attackedUnit);
	}
	//{
		/*this->set_attackpower(attackedUnit);
				attackedUnit->set_health(attackedUnit->get_health() - this->get_attackpower());
				if (attackedUnit->get_health() <= 0)
					g->insertKilled(attackedUnit);
				else
					tmp.insert(attackedUnit);*/
			/*attackAS = true;
			if (!attackedArmy->pickSoldier(attackedUnit))
			{
				break;
				ASremain = false;
			}
			else if (ASremain)
			{
				this->set_attackpower(attackedUnit);
				attackedUnit->set_health(attackedUnit->get_health() - this->get_attackpower());
				if (attackedUnit->get_health() <= 0)
					g->insertKilled(attackedUnit);
				else
					tmp.insert(attackedUnit);
			}
			if (!ASremain)
				attackAS = false;*/
	//}

	while (tmp.remove(attackedUnit))
		attackedArmy->addUnit(attackedUnit);
}

