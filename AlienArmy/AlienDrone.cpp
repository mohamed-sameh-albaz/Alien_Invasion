#include "AlienDrone.h"

AlienDrone::AlienDrone(game* master) : unit(master)
{
	set_type(AD);
	initialHealth = joinTime = health = power = attackCap = id = 0;
}

void AlienDrone::attack()
{
}
