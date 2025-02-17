#pragma once
#include<iostream>
#include <Windows.h>
#include"../EarthArmy/EarthArmy.h"
#include"../AlienArmy/AlienArmy.h"
#include"../ADTs/tempList.h"
#include"../ADTs/QueueList.h"
#include<fstream>
#include"randGen.h"
using namespace std;
enum mode {InterActive = 1,Silent};
enum selector { strong_moderete = 1, strong_strong, strong_weak,weak_moderete,weak_strong,weak_weak};

enum Winner {Earth,ALien,drawn};
class game
{
	AlienArmy* aArmy;
	EarthArmy* eArmy;
	int Es, Et, Eg, SaverCount, InfectionProb, As, N, Am, Ad, Prob, Hu,
		epower1, epower2, threshold, ehealth1, ehealth2, eattackcap1, eattackcap2,
		apower1, apower2, ahealth1, ahealth2, aattackcap1, aattackcap2;
	int earthCount, alienCount, timestep;
	QueueList* dead;
	mode GameMode;
	selector file_mode;
	Winner battleHero;
	UML* uml;
	randGen *RG;
public:
	game();
	void set_mode(mode GameMode);
	mode get_mode();
	void set_file_mode(selector s);
	void simulate(int mode);
	void fight (mode CurMode,selector s);
	void inputFn(selector s);
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
	bool Drawn();
};

