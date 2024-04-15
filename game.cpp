#include "game.h"
#include<fstream>
using namespace std;
game::game() {
	AlienArmy* aArmy = new AlienArmy;
	EarthArmy* eArmy = new EarthArmy;
	RG = new randGen;
	earthCount = 1;
	alienCount = 2000;
	inputFn();
}
void game::inputFn()
{
	ifstream f("in1.text");
	f >> N >> Prob >> Es >> Et >> Eg >> Hu >> As >> Am >> Ad >> epower1 >> epower2 >> ehealth1 >> ehealth2 >> eattackcap1
		>> eattackcap2 >> apower1 >> apower2 >> ahealth1 >> ahealth2 >> aattackcap1 >> aattackcap2;
	ehealth2 = -1 * ehealth2;
	ahealth2 = -1 * ahealth2;
	epower2 = -1 * epower2;
	apower2 = -1 * apower2;
	eattackcap2 = -1 * eattackcap2;
	aattackcap2 = -1 * aattackcap2;
	if (Hu > 5)
		Hu = 5;
	RG->setParams(Es, Et, Eg, As, Am, Ad, Prob, 
		epower1, epower2, ehealth1, ehealth2, eattackcap1, eattackcap2,
		apower1, apower2, ahealth1, ahealth2, aattackcap1, aattackcap2
		,N,Hu);
}

void game::fillArmies()
{
	RG->fillEarthArmy(eArmy, earthCount);
	RG->fillAlienArmy(aArmy, alienCount);
}


AlienArmy* game::getAlienArmy() {
	return aArmy;
}

EarthArmy* game::getEarthArmy() {
	return eArmy;
}

game::~game()
{
	delete aArmy;
	delete eArmy;
}