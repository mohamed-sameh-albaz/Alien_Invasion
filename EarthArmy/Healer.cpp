#include "Healer.h"

Healer::Healer(game* master) : unit(master)
{
	set_type(EH);
	initialHealth = joinTime = health = power = attackCap = id = 0;
}

void Healer::attack()
{
}
