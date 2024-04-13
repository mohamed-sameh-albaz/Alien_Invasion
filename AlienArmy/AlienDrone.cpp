#include "AlienDrone.h"

AlienDrone::AlienDrone()
{
	set_type("alienDrone");
	initialHealth = joinTime = health = power = attackCap = id = 0;
}

void AlienDrone::attack()
{
}
