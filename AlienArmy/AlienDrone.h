#pragma once
#include "../unit.h"
class AlienDrone : public unit
{
public:
	AlienDrone() {
		set_type("alienDrone");
		initialHealth = joinTime = health = power = attackCap = id = 0;
	}
 void 	attack(){}
};

