#include "Healer.h"

Healer::Healer()
{
	set_type("healer");
	initialHealth = joinTime = health = power = attackCap = id = 0;
}

void Healer::attack()
{
}
