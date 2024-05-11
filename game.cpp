#include "game.h"

game::game() {
	RG = new randGen(this);
	earthCount = 1;
	alienCount = 2000;
	inputFn();
	uml = new UML;
	aArmy = new AlienArmy;
	eArmy = new EarthArmy;
	dead = new killedList;
	timestep = 0;
}

void game::simulate(int mode)
{
	if(mode==1)
	{
		srand(time(0));
		int mainColor = 7, messageColor = 6;
		inputFn();


		//Test ES attack
		fillArmies();
		unit* as = NULL;
		LinkedQueue<unit*>h;
		while (aArmy->pickSoldier(as)) {
			as->disp();
			cout << "==============";
			h.enqueue(as);
		}
		while (h.dequeue(as))
			aArmy->addUnit(as);
		cout << "=========================" << endl;
		cout << "=========================" << endl;
		cout << "=========================" << endl;
		EarthSoldier* es = new EarthSoldier(this);
		es->set_power(500);
		es->set_attackCap(100);
		es->set_health(100);
		es->disp();
		es->attack();

		cout << "=========================" << endl;
		cout << "=========================" << endl;
		cout << "=========================" << endl;

		while (aArmy->pickSoldier(as))
		{
			as->disp();
			cout << "=====================" << endl;
			h.enqueue(as);
		}
		while (h.dequeue(as))
			aArmy->addUnit(as);
		aArmy->print();
		eArmy->print();
		dead->print();
		/*
		// Test AS Attack

		unit* u = nullptr;
		while (eArmy->pickTank(u)) {
			uml->insert(u);
		}
		cout << "=========================" << endl;
		cout << "=========================" << endl;
		cout << "=========================" << endl;

		t1->disp();
		t2->disp();
		t3->disp();


		uml->print();
		dead->print();

		cout << "=========================" << endl;
		cout << "=========================" << endl;
		cout << "=========================" << endl;


		Healer* hu = new Healer(this);
		hu->set_power(20);
		hu->set_attackCap(4);
		hu->set_health(100);
		hu->disp();
		hu->attack();
		cout << "=========================" << endl;
		cout << "=========================" << endl;
		cout << "=========================" << endl;

		t1->disp();
		t2->disp();
		t3->disp();

		uml->print();
		dead->print();

		fillArmies();
		unit* et = nullptr;
		unit* es = nullptr;
		ArrayStack<unit*> h;
		LinkedQueue<unit*> h2;
		while (eArmy->pickSoldier(es)) {
			es->disp();
			cout << "=========================" << endl;
			h2.enqueue(es);
		}
		while (eArmy->pickTank(et)) {
			et->disp();
			cout << "=========================" << endl;
			h.push(et);
		}
		uml->print();
		dead->print();


		while (!h.isEmpty()) {
			h.pop(et);
			eArmy->addUnit(et);
		}
		while (!h2.isEmpty()) {
			h2.dequeue(es);
			eArmy->addUnit(es);
		}
		cout << "=========================" << endl;
		cout << "=========================" << endl;
		cout << "=========================" << endl;

		monster* am = new monster(this);
		am->set_power(250);
		am->set_attackCap(4);
		am->set_health(200);
		am->disp();
		am->attack();
		AlienSoldier* as = new AlienSoldier(this);
		as->set_power(300);
		as->set_attackCap(4);
		as->set_health(200);
		as->disp();
		as->attack();

		cout << "=========================" << endl;
		cout << "=========================" << endl;
		cout << "=========================" << endl;

		while (eArmy->pickSoldier(es)) {
			es->disp();
			cout << "=========================" << endl;
			h2.enqueue(es);
		}
		while (eArmy->pickTank(et)) {
			et->disp();
			cout << "=========================" << endl;
			h.push(et);
		}

		while (!h.isEmpty()) {
			h.pop(et);
			eArmy->addUnit(et);
		}
		while (!h2.isEmpty()) {
			h2.dequeue(es);
			eArmy->addUnit(es);
		}

		uml->print();
		dead->print();

		cout << "========================= Testing Healer ============================" << endl;
		Healer* hu = new Healer(this);
		hu->set_power(20);
		hu->set_attackCap(1);
		hu->set_health(100);
		hu->disp();
		hu->attack();


		cout << "=========================" << endl;
		cout << "=========================" << endl;
		cout << "=========================" << endl;

		while (eArmy->pickSoldier(es)) {
			es->disp();
			cout << "=========================" << endl;
			h2.enqueue(es);
		}
		while (eArmy->pickTank(et)) {
			et->disp();
			cout << "=========================" << endl;
			h.push(et);
		}

		while (!h.isEmpty()) {
			h.pop(et);
			eArmy->addUnit(et);
		}
		while (!h2.isEmpty()) {
			h2.dequeue(es);
			eArmy->addUnit(es);
		}

		uml->print();
		dead->print();
		/*
		for (int i = 1; i <= 50; i++) {


			changeColor(12);
			cout << endl << "Current Timestep: " << i << endl;
			changeColor(messageColor);
			cout << endl << "Before Generating Units:" << endl;
			changeColor(mainColor);
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


		*/
	}
	else
		{
			cout << "Silent mode\n";
			cout << "Simulation starts...\n";
			cout << "Simulation ends,Output fileis created...\n";

		}
}

void game::fight()
{
	
}

void game::inputFn()
{
	ifstream in_file("input_file.text");
	in_file>> N >> Es >> Et >> Eg  >> Hu >> As >> Am >> Ad >> Prob >> epower1 >> epower2 >> ehealth1 >> ehealth2 >> eattackcap1
		>> eattackcap2 >> apower1 >> apower2 >> ahealth1 >> ahealth2 >> aattackcap1 >> aattackcap2;
	ehealth2 = -1 * ehealth2;
	ahealth2 = -1 * ahealth2;
	epower2 = -1 * epower2;
	apower2 = -1 * apower2;
	eattackcap2 = -1 * eattackcap2;
	aattackcap2 = -1 * aattackcap2;
	RG->setParams(Es, Et, Eg, Hu, As, Am, Ad, Prob, 
		epower1, epower2, ehealth1, ehealth2, eattackcap1, eattackcap2,
		apower1, apower2, ahealth1, ahealth2, aattackcap1, aattackcap2
		,N);
}

void game::outputFn()
{
	ofstream out_file("output_file.text");
	unit* killedunit;
	unit* alliveunit;

	int deadET,deadES, deadEG;
	int ET, ES, EG;
	int df=0, dd=0, db=0;
	ET = ES = EG = deadEG = deadES= deadET =0;
	while (deadEarth->remove(killedunit)) {
		if (killedunit->get_type() == 2)
			deadES++;
		else if (killedunit->get_type() == 1)
			deadET++;
		else if (killedunit->get_type() == 0)
			deadEG++;
		df = df + killedunit->get_df();
		dd = dd + killedunit->get_dd();
		db = db + killedunit->get_db();
		out_file << killedunit->get_td() << "  " << killedunit->get_id() <<
			killedunit->get_tj() << "  " << killedunit->get_df() << "  " <<
			killedunit->get_dd() << "  " << killedunit->get_db() << "  \n";
	}
	while (eArmy->get_soldierList()->remove(alliveunit)) {
		
			ES++;
		
	}
	while (eArmy->get_tankList()->remove(alliveunit)) {

		ET++;

	}
	int pir;
	while (eArmy->get_GunneryList()->remove(alliveunit,pir)) {

		EG++;

	}
	out_file << "Earth army:-\n";
	out_file << "No of dead ES= " << deadES << "\n" << " No of dead ET= " << deadET << "\n" << " No of dead EG= " << deadEG << "\n";
	out_file << "Precentage of dead ES relative to their total= " << float(deadES / (deadES + ES)) * 100 << "%\n"
		<< "Precentage of dead ET relative to their total= " << float(deadET / (deadET + ET)) * 100 << "%\n"
		<< "Precentage of dead EG relative to their total= " << float(deadEG / (deadEG + EG)) * 100 << "%\n";
	out_file << "Precentage of total earth destrcted unit relative to their total= " <<
		float((deadES + deadET + deadEG) / (deadET + ES + deadET + ET + deadEG + EG)) * 100 << "%\n";
	out_file << "Average Df= " << float(df / (deadES + deadET + deadEG)) << "\n "
		"Average Dd= " << float(dd / (deadES + deadET + deadEG)) << "\n " <<
		"Average Db= " << float(db / (deadES + deadET + deadEG)) << "\n";
	out_file << "Df/Db%= " << float(df / db) * 100 << "%\n" << "Dd/Db%= " << float(dd / db) * 100 << "%\n";
	int deadAS, deadAM, deadAD;
	int AS, AM, AD;
	int AS = 0, AM = 0, AD = 0;
	AS = AM = AD = deadAS = deadAM = deadAD = 0;
	df =  dd =db = 0;
	while (deadAliens->remove(killedunit)) {
		if (killedunit->get_type() == 4)
			deadAS++;
		else if (killedunit->get_type() == 5)
			deadAM++;
		else if (killedunit->get_type() == 6)
			deadAD++;
		df = df + killedunit->get_df();
		dd = dd + killedunit->get_dd();
		db = db + killedunit->get_db();
		out_file << killedunit->get_td() << "  " << killedunit->get_id() <<
			killedunit->get_tj() << "  " << killedunit->get_df() << "  " <<
			killedunit->get_dd() << "  " << killedunit->get_db() << "  \n";
	}
	out_file << "Batle result: ";
	if (result == 1)
		out_file << "Win \n";
	if (result == 0)
		out_file << "Drawn\n";
	if (result == -1)
		out_file << "Loss \n";
	while (aArmy->get_soldierList()->remove(alliveunit)) {
		
			AS++;
		
	}
	while (aArmy->get_monsterList()->remove(alliveunit)) {

		AM++;

	}
	while (aArmy->get_droneList()->removeFront(alliveunit)) {

		AD++;

	}
	out_file << "Alien army:-\n";
	out_file << "No of dead AS= " << deadAS<<"\n" << " No of dead AM= " << deadAM << "\n" << " No of dead AD= " << deadAD << "\n";
	out_file <<"Precentage of dead AS relative to their total= " << float(deadAS / (deadAS + AS)) * 100 << "%\n" 
		<< "Precentage of dead AM relative to their total= " << float(deadAM / (deadAM + AM)) * 100 << "%\n" 
		<<"Precentage of dead AD relative to their total= "<<float(deadAD / (deadAD + AD)) * 100 << "%\n";
	out_file << "Precentage of total alien destrcted unit relative to their total= "<<
		float((deadAS + deadAM + deadAD) / (deadAM + AS + deadAM + AM + deadAD + AD)) * 100 << "%\n";
	out_file <<"Average Df= " << float(df / (deadAS + deadAM + deadAD)) << "\n "
		"Average Dd= " << float(dd / (deadAS + deadAM + deadAD)) << "\n " <<
		"Average Db= " <<float(db / (deadAS + deadAM + deadAD)) << "\n";
	out_file <<"Df/Db%= " << float(df / db) * 100 << "%\n"<<"Dd/Db%= " << float(dd / db) * 100 << "%\n";
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

UML* game::getUML()
{
	return uml;
}

bool game::insertKilled(unit* u)
{
	if (u) {
		return deadAliens->insert(u);
	}
	else return false;
}

bool game::insertKilledAlien(unit* u)
{
	if (u) {
		return deadAliens->insert(u);
	}
	else return false;
}

bool game::insertKilledEarth(unit* u)
{
	if (u) {
		return deadEarth->insert(u);
	}
	else return false;
}

void game::printKilled()
{
	deadAliens->print();
	deadEarth->print();
}

void game::changeColor(int desiredColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

bool game::insertUml(unit* u)
{
	return (uml->insert(u));
}

bool game::pickUml(unit* u)
{
	return uml->remove(u);
}

int game::getCurrTimeStep()
{
	return timestep;
}

game::~game()
{
	delete aArmy;
	delete eArmy;
	delete deadAliens;
	delete deadEarth;
	delete dead;

	delete RG;
	delete uml;
	dead = nullptr;
	uml = nullptr;
	aArmy = nullptr;
	eArmy = nullptr;
	deadAliens = nullptr;
	deadEarth = nullptr;

	RG = nullptr;
}

int game::getEArmyCnt()
{
	return earthCount;
}

int game::getAArmyCnt()
{
	return alienCount;
}

