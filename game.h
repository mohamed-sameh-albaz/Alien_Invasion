#pragma once
#include"randGen.h"
class game
{
	AlienArmy* aArmy;
	EarthArmy* eArmy;
	int Es, Et, Eg, As,N, Am, Ad, Prob,Hu,
		epower1, epower2, ehealth1, ehealth2, eattackcap1, eattackcap2,
		apower1, apower2, ahealth1, ahealth2, aattackcap1, aattackcap2;
	randGen *RG;
	int earthCount, alienCount;
public:
	game();
	void inputFn();
	void fillArmies();
	AlienArmy* getAlienArmy();
	EarthArmy* getEarthArmy();
	~game();
};

