#include "monster.h"

monster::monster(game* master) : unit(master)
{
	set_type(AM);
	initialHealth = joinTime = health = power = attackCap = id = 0;
}

void monster::attack()
{
}
