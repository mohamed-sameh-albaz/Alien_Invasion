#include "game.h"

game::game() {
	RG = new randGen;
	earthCount = 1;
	alienCount = 2000;
	inputFn();
	aArmy = new AlienArmy;
	eArmy = new EarthArmy;
	dead = new killedList;
}

void game::simulate()
{
	srand(time(0));
	int mainColor = 7, messageColor = 6;
	inputFn();
	AlienArmy* aArmy = getAlienArmy();
	EarthArmy* eArmy = getEarthArmy();
	for (int i = 1; i <= 50; i++) {


		changeColor(12);
		cout << endl << "Current Timestep: " << i << endl;
		changeColor(7);
		cout << endl << "Before Generating Units:" << endl;
		eArmy->print();
		aArmy->print();
		printKilled();

		fillArmies();

		changeColor(messageColor);
		cout << endl << "After Generating Units:" << endl;
		changeColor(mainColor);
		eArmy->print();
		aArmy->print();
		printKilled();


		int X = (rand() % 100) + 1;
		unit* u = nullptr;
		if (X > 0 && X <= 10) {
			changeColor(messageColor);
			cout << endl << "X = " << X << " You Will Pick An Earth Soldier And Add it Again" << endl;
			changeColor(mainColor);
			eArmy->pickSoldier(u);
			eArmy->addUnit(u);
		}
		else if (X > 10 && X <= 20) {
			changeColor(messageColor);
			cout << endl << "X = " << X << " You Will Pick A Tank And Add it To Killed List" << endl;
			changeColor(mainColor);
			eArmy->pickTank(u);
			insertKilled(u);
		}
		else if (X > 20 && X <= 30) {
			changeColor(messageColor);
			cout << endl << "X = " << X << " You Will Pick A Gunnery, Decrease His Health And Insert Him Again" << endl;
			changeColor(mainColor);
			int pri;
			if (eArmy->pickGun(u, pri))
			{
				u->set_health(0.5 * u->get_health());
			}
			eArmy->addUnit(u);
		}
		else if (X > 30 && X <= 40) {
			changeColor(messageColor);
			cout << endl << "X = " << X << " You Will Pick 5 AS, Decrease Their Health, Put Them in Temp List and Put back Again" << endl;
			changeColor(mainColor);
			unit* s1 = nullptr, * s2 = nullptr, * s3 = nullptr, * s4 = nullptr, * s5 = nullptr;

			if (aArmy->pickSoldier(s1))
				s1->set_health(0.5 * s1->get_health());

			if (aArmy->pickSoldier(s2))
				s2->set_health(0.5 * s2->get_health());

			if (aArmy->pickSoldier(s3))
				s3->set_health(0.5 * s3->get_health());

			if (aArmy->pickSoldier(s4))
				s4->set_health(0.5 * s4->get_health());

			if (aArmy->pickSoldier(s5))
				s5->set_health(0.5 * s5->get_health());

			aArmy->insertTemp(s1);
			aArmy->insertTemp(s2);
			aArmy->insertTemp(s3);
			aArmy->insertTemp(s4);
			aArmy->insertTemp(s5);

			aArmy->removeTemp(s1);
			aArmy->removeTemp(s2);
			aArmy->removeTemp(s3);
			aArmy->removeTemp(s4);
			aArmy->removeTemp(s5);

			aArmy->addUnit(s1);
			aArmy->addUnit(s2);
			aArmy->addUnit(s3);
			aArmy->addUnit(s4);
			aArmy->addUnit(s5);
		}
		else if (X > 40 && X <= 50) {
			changeColor(messageColor);
			cout << endl << "X = " << X << " You Will Pick 5 Monsters And Insert Them Again" << endl;
			changeColor(mainColor);
			unit* m1 = nullptr, * m2 = nullptr, * m3 = nullptr, * m4 = nullptr, * m5 = nullptr;
			aArmy->pickMonster(m1);
			aArmy->pickMonster(m2);
			aArmy->pickMonster(m3);
			aArmy->pickMonster(m4);
			aArmy->pickMonster(m5);

			aArmy->addUnit(m1);
			aArmy->addUnit(m2);
			aArmy->addUnit(m3);
			aArmy->addUnit(m4);
			aArmy->addUnit(m5);
		}
		else if (X > 50 && X <= 60) {
			changeColor(messageColor);
			cout << endl << "X = " << X << " You Will Pick 6 Drones And Put Them In Killed List" << endl;
			changeColor(mainColor);
			unit* d1 = nullptr, * d2 = nullptr, * d3 = nullptr, * d4 = nullptr, * d5 = nullptr, * d6 = nullptr;

			aArmy->pickFrontDrone(d1);
			aArmy->pickFrontDrone(d2);
			aArmy->pickFrontDrone(d3);

			aArmy->pickEndDrone(d4);
			aArmy->pickEndDrone(d5);
			aArmy->pickEndDrone(d6);

			insertKilled(d1);
			insertKilled(d2);
			insertKilled(d3);

			insertKilled(d4);
			insertKilled(d5);
			insertKilled(d6);

		}
		else {
			changeColor(messageColor);
			cout << endl << "X = " << X << " Nothing Will Change" << endl;
			changeColor(mainColor);
		}

		eArmy->print();
		aArmy->print();
		printKilled();
		changeColor(9);
		cout << endl << "Press Enter To Continue" << endl;
		cin.get(); // Wait for user to press enter
		system("cls");
	}

	changeColor(5);
	cout << endl << "Simulation Ended" << endl;
}

void game::fight()
{
}

void game::inputFn()
{
	ifstream f("in1.text");
	f >> N >> Es >> Et >> Eg  >> As >> Am >> Ad >> Prob >> epower1 >> epower2 >> ehealth1 >> ehealth2 >> eattackcap1
		>> eattackcap2 >> apower1 >> apower2 >> ahealth1 >> ahealth2 >> aattackcap1 >> aattackcap2;
	ehealth2 = -1 * ehealth2;
	ahealth2 = -1 * ahealth2;
	epower2 = -1 * epower2;
	apower2 = -1 * apower2;
	eattackcap2 = -1 * eattackcap2;
	aattackcap2 = -1 * aattackcap2;
	RG->setParams(Es, Et, Eg, As, Am, Ad, Prob, 
		epower1, epower2, ehealth1, ehealth2, eattackcap1, eattackcap2,
		apower1, apower2, ahealth1, ahealth2, aattackcap1, aattackcap2
		,N);
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

bool game::insertKilled(unit* u)
{
	if (u) {
		return dead->insert(u);
	}
	else return false;
}

void game::printKilled()
{
	dead->print();
}

void game::changeColor(int desiredColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

game::~game()
{
	delete aArmy;
	delete eArmy;
	delete dead;
	aArmy = nullptr;
	eArmy = nullptr;
	dead = nullptr;

}