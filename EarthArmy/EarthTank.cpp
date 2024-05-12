#include "EarthTank.h"
#include"../game.h"
#include"../tempList.h"
using namespace std;



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
	int ASCnt = attackedArmy->getListCnt(AS);
	int armySolsPerc = 0;
	if(ASCnt)
		armySolsPerc = (attackingArmy->getListCnt(ES) * 100) / ASCnt;
	bool ASremain = true;//army still have AS
	//bool AMremain = true;//army still have AM
	int attackedCnt=0;

	if (armySolsPerc <= 30)
		attackAS = true;
	if (attackAS)
	{
		if (armySolsPerc >= 80)
			attackAS = false;
	}
	unit* attackedUnit = nullptr;
	tempList tmp;
	if (!attackAS) {//Not considering it until ES becomes 80%

		for (int i = 0; i < attackCap; i++)
		{
			attackedArmy->pickMonster(attackedUnit);
			if (attackedUnit)
				tmp.insert(attackedUnit);
			else
			{
				//AMremain = false;
				break;
			}
			attackedUnit = nullptr;
		}
	}
	else
	{
		for (int i = 0; i < attackCap / 2; i++)//pick 50% of the list monsters
		{
			attackedArmy->pickMonster(attackedUnit);
			if (attackedUnit)
				tmp.insert(attackedUnit);
			else
			{
				//AMremain = false;
				break;
			}
			attackedUnit = nullptr;
		}
		attackedCnt = tmp.getCount();
		for (int i = 0; i < attackCap - attackedCnt; i++)//pick 50% of the list AS
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
		attackedCnt = tmp.getCount();
		//if (!AMremain and attackedCnt != attackCap)//if monsters in the army is empty complete the list with AS
		//{
		//	for (int i = 0; i < attackCap -attackedCnt; i++)
		//	{
		//		attackedArmy->pickSoldier(attackedUnit);
		//		if (attackedUnit)
		//		{
		//			tmp.insert(attackedUnit);
		//		}
		//		else
		//		{
		//			ASremain = false;
		//			break;
		//		}
		//		attackedUnit = nullptr;
		//	}
		//}
		if (!ASremain and attackedCnt != attackCap)//if AS army is empty complete the list with AM
		{
			for (int i = 0; i < attackCap -attackedCnt; i++)
			{
				attackedArmy->pickMonster(attackedUnit);
				if (attackedUnit)
					tmp.insert(attackedUnit);
				else
				{
					//AMremain = false;
					break;
				}
				attackedUnit = nullptr;
			}
		}
	}
	attackedCnt = tmp.getCount();
	if (g->get_mode() == 1)
		tmp.print(get_type(), id);
	for (int i = 0; i < attackedCnt; i++)
	{
		tmp.remove(attackedUnit);
		if (attackedUnit->get_Noofattacked() == 0) {
			attackedUnit->set_atackedTime(g->getCurrTimeStep());
			attackedUnit->set_Noofattacked(1);
		}
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

