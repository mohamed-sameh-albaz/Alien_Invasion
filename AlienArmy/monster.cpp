#include "monster.h"

monster::monster()
{
	set_type("monster");
	initialHealth = joinTime = health = power = attackCap = id = 0;
}

void monster::attack()
{
}
