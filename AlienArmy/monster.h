#pragma once
#include "../unit.h"
class monster : public unit
{
public:
	monster(game* master);
	void attack(); 
};

