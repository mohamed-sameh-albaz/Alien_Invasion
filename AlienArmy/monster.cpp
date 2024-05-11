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
	tmp.print(get_type(), id);


	for (int i = 0; i < attackCap; i++) {
		if (!tmp.remove(attackedUnit)) break;
		else {
			this->set_attackpower(attackedUnit);
			attackedUnit->set_health(attackedUnit->get_health() - this->get_attackpower());
			if (attackedUnit->get_health() <= 0)
			{
				g->insertKilled(attackedUnit);
				attackedUnit->set_distructionTime(g->getCurrTimeStep());

			}
			else if ((attackedUnit->get_health() * 100 / attackedUnit->get_initial_health()) <= 20) {

				g->insertUml(attackedUnit);
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
