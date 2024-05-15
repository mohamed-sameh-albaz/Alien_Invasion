#pragma once
#include "../unit.h"

class EarthSoldier : public unit
{
	bool Infected;
	bool cured;
public:
	EarthSoldier(game* master);
	void setInfected(bool b);
	void setCured(bool b);
	bool isInfected();
	bool isCured();
	void attack(); 
};

