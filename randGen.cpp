#include "randGen.h"

void randGen::setParams(int Es0, int Et0, int Eg0, int As0, int Am0, int Ad0, int Prob0,
	int epower10, int epower20, int ehealth10, int ehealth20, int eattackcap10, int eattackcap20,
	int apower10, int apower20, int ahealth10, int ahealth20, int aattackcap10, int aattackcap20, int N0) {
	Es = Es0;
	Et = Et0;
	Eg = Eg0;
	As = As0;
	Am = Am0;
	Ad = Ad0;
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
}


unit* randGen::generateEarthUnit(int id, int B) {
	if (B <= Es) {
		EarthSoldier* myEarthSoldier = new EarthSoldier;
		myEarthSoldier->set_id(id);
		myEarthSoldier->set_health((rand() % (ehealth2 - ehealth1 + 1)) + ehealth1);
		myEarthSoldier->set_power((rand() % (epower2 - epower1 + 1)) + epower1);
		myEarthSoldier->set_attackCap((rand() % (eattackcap2 - eattackcap1 + 1)) + eattackcap1);
		return myEarthSoldier;
	}
	else if (B <= Es + Et) {
		EarthTank* myEarthTank = new EarthTank;
		myEarthTank->set_id(id);
		myEarthTank->set_health((rand() % (ehealth2 - ehealth1 + 1)) + ehealth1);
		myEarthTank->set_power((rand() % (epower2 - epower1 + 1)) + epower1);
		myEarthTank->set_attackCap((rand() % (eattackcap2 - eattackcap1 + 1)) + eattackcap1);
		return myEarthTank;
	}
	else {
		EarthGun* myEarthGun = new EarthGun;
		myEarthGun->set_id(id);
		myEarthGun->set_health((rand() % (ehealth2 - ehealth1 + 1)) + ehealth1);
		myEarthGun->set_power((rand() % (epower2 - epower1 + 1)) + epower1);
		myEarthGun->set_attackCap((rand() % (eattackcap2 - eattackcap1 + 1)) + eattackcap1);
		return myEarthGun;
	}
}

unit* randGen::generateAlienUnit(int id, int B) {
	if (B <= As) {
		AlienSoldier* myAlienSoldier = new AlienSoldier;
		myAlienSoldier->set_id(id);
		myAlienSoldier->set_health((rand() % (ahealth2 - ahealth1 + 1)) + ahealth1);
		myAlienSoldier->set_power((rand() % (apower2 - apower1 + 1)) + apower1);
		myAlienSoldier->set_attackCap((rand() % (aattackcap2 - aattackcap1 + 1)) + aattackcap1);
		return myAlienSoldier;
	}
	else if (B <= As + Am) {
		monster* myMonster = new monster;
		myMonster->set_id(id);
		myMonster->set_health((rand() % (ahealth2 - ahealth1 + 1)) + ahealth1);
		myMonster->set_power((rand() % (apower2 - apower1 + 1)) + apower1);
		myMonster->set_attackCap((rand() % (aattackcap2 - aattackcap1 + 1)) + aattackcap1);
		return myMonster;
	}
	else {
		AlienDrone* myAlienDrone = new AlienDrone;
		myAlienDrone->set_id(id);
		myAlienDrone->set_health((rand() % (ahealth2 - ahealth1 + 1)) + ahealth1);
		myAlienDrone->set_power((rand() % (apower2 - apower1 + 1)) + apower1);
		myAlienDrone->set_attackCap((rand() % (aattackcap2 - aattackcap1 + 1)) + aattackcap1);
		return myAlienDrone;
	}
}

bool randGen::fillEarthArmy(EarthArmy* army, int& count) {
	int A = (rand() % 100) + 1;
	if (A <= Prob) {
		for (int i = 1; i <= N; i++) {
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
	if (A <= Prob) {
		for (int i = 1; i <= N; i++) {
			int B = (rand() % 100) + 1;
			unit* u = generateAlienUnit(count, B);
			count++;
			army->addUnit(u);
		}
		return true;
	}
	else return false;
}
