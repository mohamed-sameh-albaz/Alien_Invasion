#pragma once
#include "../unit.h"
class monster : public unit
{
public:
	monster() {
		set_type("monster");
		initialHealth = joinTime = health = power = attackCap = id = 0;
	}
	
	void attack() {}
};

