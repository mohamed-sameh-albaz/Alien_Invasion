#include"AlienSoldier.h"
#include "../game.h"
AlienSoldier::AlienSoldier(game* master) : unit(master)
{
	set_type(AS);
	initialHealth = joinTime = health = power = attackCap = id = 0;
}

void AlienSoldier::attack()
{
	EarthArmy * e  = g->getEarthArmy();
	unit* u = nullptr;
	LinkedQueue<unit*> h;
	for (int i = 0; i < attackCap; ) {
		if (!e->pickSoldier(u)) break;
		else {
			this->set_attackpower(u);
			u->set_health(u->get_health() - this->get_attackpower());
			h.enqueue(u);
		}
	}

	while (!h.isEmpty()) {
		h.dequeue(u);
		e->addUnit(u);
	}
}

void AlienSoldier::testAttack(unit* u)
{
}
