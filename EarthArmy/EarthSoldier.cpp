#include "EarthSoldier.h"

EarthSoldier::EarthSoldier(game* master) : unit(master)
{
	set_type(ES);
	initialHealth = joinTime = health = power = attackCap = id = 0;
}

void EarthSoldier::attack()
{
}
