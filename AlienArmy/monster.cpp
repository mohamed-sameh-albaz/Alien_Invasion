#include "monster.h"

monster::monster()
{
	set_type(AM);
	initialHealth = joinTime = health = power = attackCap = id = 0;
}

void monster::attack()
{
}
