#pragma once
#include <iostream>
#include"../unit.h"
#include "../EarthArmy/EarthArmy.h"
#include "../EarthArmy/EarthSoldier.h"
#include "../EarthArmy/EarthTank.h"
#include "../EarthArmy/EarthGun.h"
#include "../EarthArmy/Healer.h"
#include "../EarthArmy/SU.h"
#include "../AlienArmy/AlienArmy.h"
#include "../AlienArmy/AlienDrone.h"
#include "../AlienArmy/AlienSoldier.h"
class game;
using namespace std;

class randGen
{
	int Es, Et, Eg, SaverCount,As, Am, Ad, InfectionProb,Prob,
		epower1, epower2, ehealth1, ehealth2, eattackcap1, eattackcap2,N,Hu,
		apower1, apower2, ahealth1, ahealth2, aattackcap1, aattackcap2,threshold;
	game* g;
	int SaverID;
public:
	void setParams(int Es0, int Et0, int Eg0, int Hu0, int SaverCount0, int threshold, int As0, int Am0, int Ad0, int InfectionProb, int Prob0,
		int epower10, int epower20, int ehealth10, int ehealth20, int eattackcap10, int eattackcap20,
		int apower10, int apower20, int ahealth10, int ahealth20, int aattackcap10, int aattackcap20, int N0);
	unit* generateEarthUnit(int id, int B);
	unit* generateAlienUnit(int id, int B);
	int get_threshold();
	bool fillEarthArmy(EarthArmy* army, int& count); 
	bool fillAlienArmy(AlienArmy* army, int& count);
	bool genAlliedArmy(EarthArmy* army);
    randGen(game* master) { g = master; }
};

