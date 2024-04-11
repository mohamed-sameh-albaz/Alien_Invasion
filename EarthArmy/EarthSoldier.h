#pragma once
#include "../unit.h"
#include"../DS/LinkedQueue.h"
#include"../DS/Node.h"
class EarthSoldier : public unit
{
public:
	EarthSoldier() {
		set_type("soldier");
		initialHealth = joinTime = health = power = attackCap = id = 100;
	}

	void attack() {}
};

