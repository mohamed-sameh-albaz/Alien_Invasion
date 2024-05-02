#pragma once
#include"../unit.h"
class AlienSoldier : public unit
{
public:
	AlienSoldier(game* master); 
	void attack(); 
	void testAttack(unit* u);
};

