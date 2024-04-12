#pragma once
#include"../unit.h"
#include"../DS/LinkedQueue.h"
class AlienSoldier : public unit
{

public:

	AlienSoldier() {
		set_type("alienSoldier");
		initialHealth = joinTime = health = power = attackCap = id = 0;
	}
	
	void attack() {}
};

