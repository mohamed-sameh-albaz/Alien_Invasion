#pragma once
#include "../unit.h"
class AlienDrone : public unit
{
public:
	AlienDrone() {
		set_type("soldier");
		initialHealth = joinTime = health = power = attackCap = id = 100;

	}
 void 	attack(){}
};

