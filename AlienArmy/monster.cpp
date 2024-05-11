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
	unit* attackedTank = nullptr;
	unit* attackedsoldier = nullptr;
	unit* removedFromTmplst = nullptr;
	tempList tmp;
	
	for (int i = 0; i < attackCap/2; i++) {
		if (!e->pickTank(attackedTank)) break;
		else {
			this->set_attackpower(attackedTank);
			attackedTank->set_health(attackedTank->get_health() - this->get_attackpower());
			if (attackedTank->get_health() <= 0)
			{
				g->insertKilled(attackedTank);
				g->insertKilledEarth(attackedTank);

				attackedTank->set_distructionTime(g->getCurrTimeStep());

			}
			else if ((attackedTank->get_health() * 100 / attackedTank->get_initial_health()) <= 20) {

				g->insertUml(attackedTank);
			}
			else {

				tmp.insert(attackedTank);
			}
		}
	}
	for (int i = 0; i < attackCap/2+ attackCap%2; i++) {
		if (!e->pickSoldier(attackedsoldier)) break;
		else {
			this->set_attackpower(attackedsoldier);
			attackedsoldier->set_health(attackedsoldier->get_health() - this->get_attackpower());
			if (attackedsoldier->get_health() <= 0)
			{
				g->insertKilled(attackedsoldier);
				g->insertKilledEarth(attackedsoldier);
				attackedsoldier->set_distructionTime(g->getCurrTimeStep());

			}
			else if ((attackedsoldier->get_health() * 100 / attackedsoldier->get_initial_health()) <= 20) {

				g->insertUml(attackedsoldier);
			}
			else {

				tmp.insert(attackedsoldier);
			}
		}
	}
	
	while (tmp.remove(removedFromTmplst)) {
		e->addUnit(removedFromTmplst);
	}
}


