#include "SU.h"

SU::SU(game* g) : unit(g)
{
	set_type(saver);
	initialHealth = joinTime = health = power = attackCap = id = 0;

}
