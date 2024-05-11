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
	int earthCount, alienCount, timestep;
	killedList* deadAliens;
	killedList* dead;

	killedList* deadEarth;

	UML* uml;
public:
	game();
	void simulate(int mode);
	void fight();
	void inputFn();
	void outputFn();
	void fillArmies();
	AlienArmy* getAlienArmy();
	EarthArmy* getEarthArmy();
	UML* getUML();
	bool insertKilled(unit* u);

	bool insertKilledAlien(unit* u);
	bool insertKilledEarth(unit* u);
	void printKilled();
	void changeColor(int desiredColor);		//console display colors
	bool insertUml(unit* u);
	bool pickUml(unit* u);
	int getCurrTimeStep();
	~game();
	int getEArmyCnt();
	int getAArmyCnt();
};

