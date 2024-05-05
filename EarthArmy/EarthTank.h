#pragma once
#include "../unit.h"
class EarthTank : public unit
{
	static bool attackAS;
public:
	EarthTank(game* master);
	void attack();
};

