#include"AlienSoldier.h"
#include "../game.h"
#include "../tempList.h"
AlienSoldier::AlienSoldier(game* master) : unit(master)
{
	set_type(AS);
	initialHealth = joinTime = health = power = attackCap = id = 0;
}

void AlienSoldier::attack()
{
	EarthArmy * e  = g->getEarthArmy();
	unit* u = nullptr;
	tempList tmp;
	for (int i = 0; i < attackCap; i++) {
		if (!e->pickSoldier(u)) break;
		else {
			this->set_attackpower(u);
			u->set_health(u->get_health() - this->get_attackpower());
			if (u->get_health() <= 0)
			{
				g->insertKilled(u);
				g->insertKilledEarth(u);

			}
			else if ((u->get_health() * 100 / u->get_initial_health()) <= 20){

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
