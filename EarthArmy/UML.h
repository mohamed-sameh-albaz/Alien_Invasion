#pragma once
#include "../DS/priQueue.h"
#include "../DS/LinkedQueue.h"
#include "EarthSoldier.h"
#include "EarthTank.h"

class UML
{
	priQueue<unit*> soldiersToHeal;
	LinkedQueue<unit*> tanksToHeal;
public:
	bool add(unit* u) {
		if (u->get_type() == "soldier") {
			soldiersToHeal.enqueue(u, -1 * (u->get_health() / u->get_initial_health() * 100));
			return true;
		}
		else if (u->get_type() == "tank") {
			tanksToHeal.enqueue(u);
			return true;
		}
		else return false;
	}

	unit* pick() {
		if (!soldiersToHeal.isEmpty()) {
			unit* solid;
			int i;
			soldiersToHeal.dequeue(solid,i);
			return solid;
		}
		else if (!tanksToHeal.isEmpty()) {
			unit* tank;
			tanksToHeal.dequeue(tank);
			return tank;
		}
	}
};

