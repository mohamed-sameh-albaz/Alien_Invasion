#include "EarthGun.h"

EarthGun::EarthGun(game* master) : unit(master)
{
	set_type(EG);
	initialHealth = joinTime = health = power = attackCap = id = 0 ;
}

void EarthGun::attack()
{
}
