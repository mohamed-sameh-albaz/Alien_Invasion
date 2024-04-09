#pragma once
#include "../unit.h"
class EarthTank : public unit
{
public:
	EarthTank() {
		set_type("tank");
		initialHealth = joinTime = health = power = attackCap = id = 10;
	}

	void attack() {}
};

