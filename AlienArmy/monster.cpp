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
	unit* u = nullptr;
	tempList tmp;
	for (int i = 0; i < attackCap; i++) {
		if (!e->pickTank(u)) break;
		else {
			this->set_attackpower(u);
			u->set_health(u->get_health() - this->get_attackpower());
			if (u->get_health() <= 0)
			{
				g->insertKilled(u);
				u->set_distructionTime(g->getCurrTimeStep());

			}
			else if ((u->get_health() * 100 / u->get_initial_health()) <= 100) {

				g->insertUml(u);
			}
			else {

				tmp.insert(u);
			}
		}
	}

	while (tmp.remove(u)) {
		e->addUnit(u);
	}
}
