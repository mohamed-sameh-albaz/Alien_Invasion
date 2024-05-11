#pragma once
#include "../unit.h"

class EarthSoldier : public unit
{
public:
	EarthSoldier(game* master);
	void attack(); 
};

