#pragma once
#include<iostream>
#include"randGen.h"
#include"EarthArmy/EarthArmy.h"
#include"AlienArmy/AlienArmy.h"
#include<fstream>
using namespace std;

class game
{
	AlienArmy* aArmy;
	EarthArmy* eArmy;
	int Es, Et, Eg,SaverCount,InfectionProb, As,N, Am, Ad, Prob,Hu,
		epower1, epower2, ehealth1, ehealth2, eattackcap1, eattackcap2,
		apower1, threshold, apower2, ahealth1, ahealth2, aattackcap1, aattackcap2;
	randGen *RG;
	int earthCount, alienCount, timestep;
	QueueList* dead;
	int result;
	int m;//mode
	UML* uml;
public:
	game();
	void set_mode(int a);
	int get_mode();

	void simulate(int mode);
	void fight (int mode);
	void inputFn();
	void outputFn();
	void fillArmies();
	AlienArmy* getAlienArmy();
	EarthArmy* getEarthArmy();
	UML* getUML();
	bool insertKilled(unit* u);
	int getInfectionProb();
	void printKilled();
	void changeColor(int desiredColor);		//console display colors
	bool insertUml(unit* u);
	bool pickUml(unit* u);
	int getCurrTimeStep();
	~game();
	int getEArmyCnt();
	int getAArmyCnt();
	bool alienIsEmpty();
	bool earthIsEmpty();

};

