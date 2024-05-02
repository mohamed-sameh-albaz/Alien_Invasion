#pragma once
#include "../unit.h"
class Healer : public unit
{
public:
	Healer(game* master);
	void attack(); 
};
