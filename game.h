#pragma once
#include<iostream>
#include"randGen.h"
#include"EarthArmy/EarthArmy.h"
#include"AlienArmy/AlienArmy.h"
#include "killedList.h"
#include<fstream>
using namespace std;

class game
{
	AlienArmy* aArmy;
	EarthArmy* eArmy;
	int Es, Et, Eg, As,N, Am, Ad, Prob,Hu,
		epower1, epower2, ehealth1, ehealth2, eattackcap1, eattackcap2,
		apower1, apower2, ahealth1, ahealth2, aattackcap1, aattackcap2;
	randGen *RG;
	int earthCount, alienCount;
	killedList* dead;
public:
	game();
	void simulate();
	void fight();
	void inputFn();
	void fillArmies();
	AlienArmy* getAlienArmy();
	EarthArmy* getEarthArmy();
	bool insertKilled(unit* u);
	void printKilled();
	void changeColor(int desiredColor);		//console display colors
	~game();
};

