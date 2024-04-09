#pragma once
#include "../unit.h"
class Healer : public unit
{
public:
	Healer() { set_type("healer"); 
	initialHealth = joinTime = health = power = attackCap = id = 0;
	}

	void attack() {}
};
