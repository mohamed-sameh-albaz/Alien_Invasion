#include "EarthTank.h"

EarthTank::EarthTank(game* master) : unit(master)
{
	set_type(ET);
	initialHealth = joinTime = health = power = attackCap = id = 0;
}
void EarthTank::attack()
{
}

