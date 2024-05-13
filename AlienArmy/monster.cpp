#include "monster.h"
#include "../game.h"
#include "../tempList.h"

monster::monster(game* master) : unit(master)
{
	set_type(AM);
	initialHealth = joinTime = health = power = attackCap = id = 0;
}

void monster::attack()
{
	
	EarthArmy* e = g->getEarthArmy();
	tempList tmp, tmp2;
	unit* attackedUnit = nullptr;
	int attackedcnt = 0;

	bool EGremain = true;//army still have AS
	bool ETremain = true;//army still have AM
	int attackedCnt = 0;
	for (int i = 0; i < ((attackCap / 2) + (attackCap % 2)); i++)
	{
		e->pickTank(attackedUnit);
		if (attackedUnit)
			tmp.insert(attackedUnit);
		else
			break;
		attackedUnit = nullptr;
	}

	for (int i = 0; i < (attackCap / 2); i++)
	{
		e->pickSoldier(attackedUnit);
		if (attackedUnit)
			tmp.insert(attackedUnit);
		else
			break;
		attackedUnit = nullptr;
	}
	if (!EGremain && ETremain) {
		attackedCnt = tmp.getCount();
		attackedUnit = nullptr;
		for (int i = 0; i < attackCap - attackedCnt; i++) {
			e->pickTank(attackedUnit);
			if (attackedUnit)
				tmp.insert(attackedUnit);
			else
			{
				ETremain = false;
				break;
			}
			attackedUnit = nullptr;
		}
	}
	if (EGremain && !ETremain) {
		attackedCnt = tmp.getCount();
		attackedUnit = nullptr;
		for (int i = 0; i < attackCap - attackedCnt; i++) {
			e->pickSoldier(attackedUnit);
			if (attackedUnit)
				tmp.insert(attackedUnit);
			else
			{
				EGremain = false;
				break;
			}
			attackedUnit = nullptr;
		}
	}

	if (g->get_mode() == 1)
	tmp.print(get_type(), id);


	for (int i = 0; i < attackCap; i++) {
		if (!tmp.remove(attackedUnit)) break;
		else {
			if (attackedUnit->get_Noofattacked() == 0) {
				attackedUnit->set_atackedTime(g->getCurrTimeStep());
				attackedUnit->set_Noofattacked(1);
			}
			this->set_attackpower(attackedUnit);
			attackedUnit->set_health(attackedUnit->get_health() - this->get_attackpower());
			if (attackedUnit->get_health() <= 0)
			{
				attackedUnit->set_distructionTime(g->getCurrTimeStep());
				g->insertKilled(attackedUnit);

			}
			else if ((attackedUnit->get_health() * 100 / attackedUnit->get_initial_health()) <= 20) {

				g->insertUml(attackedUnit);
				attackedUnit->setUMLtime(g->getCurrTimeStep());
			}
			else {

				tmp2.insert(attackedUnit);
			}
		}
		attackedUnit = nullptr;
	}

	while (tmp2.remove(attackedUnit)) {
		e->addUnit(attackedUnit);
	}
	
}


