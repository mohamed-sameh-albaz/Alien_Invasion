#include "randGen.h"
#include"game.h"
void randGen::setParams(int Es0, int Et0, int Eg0,int Hu0,int SaverCount0,int threshold ,int As0, int Am0, int Ad0,int InfectionProb0, int Prob0,
	int epower10, int epower20, int ehealth10, int ehealth20, int eattackcap10, int eattackcap20,
	int apower10, int apower20, int ahealth10, int ahealth20, int aattackcap10, int aattackcap20, int N0) {
	Es = Es0;
	Et = Et0;
	Eg = Eg0;
	Hu = Hu0;
	SaverCount = SaverCount0;
	As = As0;
	Am = Am0;
	Ad = Ad0;
	InfectionProb = InfectionProb0;
	Prob = Prob0;
	epower1 = epower10;
	epower2 = epower20;
	ehealth1 = ehealth10;
	ehealth2 = ehealth20;
	eattackcap1 = eattackcap10;
	eattackcap2 = eattackcap20;
	apower1 = apower10;
	apower2 = apower20;
	ahealth1 = ahealth10;
	ahealth2 = ahealth20;
	aattackcap1 = aattackcap10;
	aattackcap2 = aattackcap20;
	N = N0;
	SaverID = 1001;
}


unit* randGen::generateEarthUnit(int id, int B) {
	if (B <= Es) {
		EarthSoldier* myEarthSoldier = new EarthSoldier(g);
		myEarthSoldier->set_id(id);
		myEarthSoldier->set_health((rand() % (ehealth2 - ehealth1 + 1)) + ehealth1);
		myEarthSoldier->set_power((rand() % (epower2 - epower1 + 1)) + epower1);
		myEarthSoldier->set_attackCap((rand() % (eattackcap2 - eattackcap1 + 1)) + eattackcap1);
		myEarthSoldier->set_joinTime(g->getCurrTimeStep());
		return myEarthSoldier;
	}
	else if (B <= Es + Et) {
		EarthTank* myEarthTank = new EarthTank(g);
		myEarthTank->set_id(id);
		myEarthTank->set_health((rand() % (ehealth2 - ehealth1 + 1)) + ehealth1);
		myEarthTank->set_power((rand() % (epower2 - epower1 + 1)) + epower1);
		myEarthTank->set_attackCap((rand() % (eattackcap2 - eattackcap1 + 1)) + eattackcap1);
		myEarthTank->set_joinTime(g->getCurrTimeStep());
		return myEarthTank;
	}
	else if (B <= Es + Et + Eg) {
		EarthGun* myEarthGun = new EarthGun(g);
		myEarthGun->set_id(id);
		myEarthGun->set_health((rand() % (ehealth2 - ehealth1 + 1)) + ehealth1);
		myEarthGun->set_power((rand() % (epower2 - epower1 + 1)) + epower1);
		myEarthGun->set_attackCap((rand() % (eattackcap2 - eattackcap1 + 1)) + eattackcap1);
		myEarthGun->set_joinTime(g->getCurrTimeStep());
		return myEarthGun;
	}
	else {
		Healer* myHealer = new Healer(g);
		myHealer->set_id(id);
		myHealer->set_health((rand() % (ehealth2 - ehealth1 + 1)) + ehealth1);
		myHealer->set_power((rand() % (epower2 - epower1 + 1)) + epower1);
		myHealer->set_attackCap((rand() % (eattackcap2 - eattackcap1 + 1)) + eattackcap1);
		myHealer->set_joinTime(g->getCurrTimeStep());
		return myHealer;
	}
}

unit* randGen::generateAlienUnit(int id, int B) {
	if (B <= As) {
		AlienSoldier* myAlienSoldier = new AlienSoldier(g);
		myAlienSoldier->set_id(id);
		myAlienSoldier->set_health((rand() % (ahealth2 - ahealth1 + 1)) + ahealth1);
		myAlienSoldier->set_power((rand() % (apower2 - apower1 + 1)) + apower1);
		myAlienSoldier->set_attackCap((rand() % (aattackcap2 - aattackcap1 + 1)) + aattackcap1);
		myAlienSoldier->set_joinTime(g->getCurrTimeStep());
		return myAlienSoldier;
	}
	else if (B <= As + Am) {
		monster* myMonster = new monster(g);
		myMonster->set_id(id);
		myMonster->set_health((rand() % (ahealth2 - ahealth1 + 1)) + ahealth1);
		myMonster->set_power((rand() % (apower2 - apower1 + 1)) + apower1);
		myMonster->set_attackCap((rand() % (aattackcap2 - aattackcap1 + 1)) + aattackcap1);
		myMonster->set_joinTime(g->getCurrTimeStep());
		return myMonster;
	}
	else {
		AlienDrone* myAlienDrone = new AlienDrone(g);
		myAlienDrone->set_id(id);
		myAlienDrone->set_health((rand() % (ahealth2 - ahealth1 + 1)) + ahealth1);
		myAlienDrone->set_power((rand() % (apower2 - apower1 + 1)) + apower1);
		myAlienDrone->set_attackCap((rand() % (aattackcap2 - aattackcap1 + 1)) + aattackcap1);
		myAlienDrone->set_joinTime(g->getCurrTimeStep());
		return myAlienDrone;
	}
}

int randGen::get_threshold()
{
	return threshold;
}

bool randGen::fillEarthArmy(EarthArmy* army, int& count) {
	int A = (rand() % 100) + 1;
	if (A <= Prob) {
		for (int i = 1; i <= N; i++) {
			if (count > 999)
			{
				if (g->get_mode() == 1)
				cout << "\nNo IDs are available\n";
				return true;
			}
			int B = (rand() % 100) + 1;
			unit* u = generateEarthUnit(count, B);
			count++;
			army->addUnit(u);
		}
		return true;
	}
	else return false;
}

bool randGen::fillAlienArmy(AlienArmy* army, int& count) {
	int A = (rand() % 100) + 1;
	if (A<=Prob) {
		for (int i = 1; i <= N; i++) {
			if (count > 2999)
			{
				if (g->get_mode() == 1)
				cout << "\nNo IDs are available\n";
				return true;
			}
			int B = (rand() % 100) + 1;
			unit* u = generateAlienUnit(count, B);
			count++;
			army->addUnit(u);
		}
		return true;
	}
	else return false;
}

bool randGen::genAlliedArmy(EarthArmy* army)
{
	if (SaverID < 2000) {

		for (int i = 1; i <= SaverCount && SaverID < 2000; i++) {
			SU* saver1 = new SU(g);
			saver1->set_id(SaverID++);
			saver1->set_health((rand() % (ehealth2 - ehealth1 + 1)) + ehealth1);
			saver1->set_power((rand() % (epower2 - epower1 + 1)) + epower1);
			saver1->set_attackCap((rand() % (eattackcap2 - eattackcap1 + 1)) + eattackcap1);
			saver1->set_joinTime(g->getCurrTimeStep());
			unit* u = saver1;
			army->addUnit(saver1);
		}
		return true;
	}
	else return false;
}
