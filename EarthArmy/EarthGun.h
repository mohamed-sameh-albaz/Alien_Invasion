#pragma once
#include "../unit.h"
class EarthGun : public unit
{
public:
	EarthGun()
	{
		set_type("Gunnery");
		initialHealth = joinTime = health = power = attackCap = id = 9;
	}
	void attack() {}
};

