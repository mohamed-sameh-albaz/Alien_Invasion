#include "AlienDrone.h"

AlienDrone::AlienDrone()
{
	set_type(AD);
	initialHealth = joinTime = health = power = attackCap = id = 0;
}

void AlienDrone::attack()
{
}
