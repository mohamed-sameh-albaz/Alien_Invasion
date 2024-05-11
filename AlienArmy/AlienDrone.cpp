#include "AlienDrone.h"
#include"../tempList.h"
#include"../EarthArmy/EarthArmy.h"
#include"../game.h"
AlienDrone::AlienDrone(game* master) : unit(master)
{
	set_type(AD);
	initialHealth = joinTime = health = power = attackCap = id = 0;
}

void AlienDrone::attack()
{
	EarthArmy* e = g->getEarthArmy();
	unit* attackedTank = nullptr;
	unit* attackedgunnery = nullptr;
	unit* removedFromTmplst = nullptr;
	tempList tmp;

	for (int i = 0; i < attackCap / 2; i++) {
		if (!e->pickTank(attackedTank)) break;
		else {
			this->set_attackpower(attackedTank);
			attackedTank->set_health(attackedTank->get_health() - this->get_attackpower());
			if (attackedTank->get_health() <= 0)
			{
				g->insertKilled(attackedTank);
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
	for (int i = 0; i < attackCap / 2 + attackCap % 2; i++) {
		if (!e->pickSoldier(attackedgunnery)) break;
		else {
			this->set_attackpower(attackedgunnery);
			attackedgunnery->set_health(attackedgunnery->get_health() - this->get_attackpower());
			if (attackedgunnery->get_health() <= 0)
			{
				g->insertKilled(attackedgunnery);

				attackedgunnery->set_distructionTime(g->getCurrTimeStep());

			}
			else {

				tmp.insert(attackedgunnery);
			}
		}
	}

	while (tmp.remove(removedFromTmplst)) {
		e->addUnit(removedFromTmplst);
	}
}



