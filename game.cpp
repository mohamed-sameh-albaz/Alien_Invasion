#include "game.h"
#include"tempList.h"
game::game() {
	RG = new randGen(this);
	earthCount = 1;
	alienCount = 2000;
	inputFn();
	uml = new UML;
	aArmy = new AlienArmy;
	eArmy = new EarthArmy;
	dead = new QueueList;
	timestep = 1;
	m = 1;
}

void game::set_mode(int a)
{
	m =a ;
}

int game::get_mode()
{
	return m;
}

void game::simulate(int mode)
{
	if(mode==1)
	{
		srand(time(0));
		int mainColor = 7, messageColor = 6;
		inputFn();
		//testing drone

		monster* AM = new monster(this);
		AM->set_power(10);
		AM->set_attackCap(10);
		AM->set_health(100);
		AM->disp();

		EarthTank t1(this), t2(this), t3(this);
		EarthSoldier g1(this), g2(this), g3(this);

		t1.set_id(1);
		t1.set_health(100);
		t2.set_id(2);
		t2.set_health(100);
		t3.set_id(3);
		t3.set_health(100);
		g1.set_id(4);
		g1.set_health(100);
		g2.set_id(5);
		g2.set_health(100);
		g3.set_id(6);
		g3.set_health(100);

		eArmy->addUnit(&t1);
		eArmy->addUnit(&t2);
		eArmy->addUnit(&t3);
		eArmy->addUnit(&g1);
		//eArmy->addUnit(&g2);
		//eArmy->addUnit(&g3);

		eArmy->print();

		cout << "====================== Drone Attack ======================" << endl;
		AM->attack();

		cout << "After Attacking" << endl;
		eArmy->print();
	
		//while (true) {
		//	cout << endl << "Press Enter To Continue" << endl;
		//	cin.get(); // Wait for user to press enter
		//}
		//testing timeSteps
		//Healer* hu = new Healer(this);
		//hu->set_power(0);
		//hu->set_attackCap(4);
		//hu->set_health(100);
		//hu->disp();
		//EarthSoldier* ES = new EarthSoldier(this);
		//ES->set_health(100);
		//
		//ES->set_health(10);
		//uml->insert(ES);
		//ES->setUMLtime(0);
		//uml->print();
		//dead->print();
		//timestep = 11;
		//hu->attack();
		//uml->print();
		//dead->print();
		
	/*
	// Test New Monster

	fillArmies();
	unit* et = nullptr;
	unit* eg = nullptr;
	LinkedQueue<unit*> h;
	ArrayStack<unit*> h2;
	while (eArmy->pickTank(et)) {
		et->disp();
		cout << "=========================" << endl;
		h2.push(et);
	}
	while (eArmy->pickGun(eg)) {
		eg->disp();
		cout << "=========================" << endl;
		h.enqueue(eg);
	}
	uml->print();
	dead->print();


	while (!h.isEmpty()) {
		h.dequeue(eg);
		eArmy->addUnit(eg);
	}
	while (!h2.isEmpty()) {
		h2.pop(et);
		eArmy->addUnit(et);
	}

	/*monster* am = new monster(this);
	am->set_power(200);
	am->set_attackCap(4);
	am->set_health(200);
	AlienSoldier* as = new AlienSoldier(this);
	as->set_power(100);
	as->set_attackCap(4);
	as->set_health(200);

	am->attack();
	am->attack();
	am->attack();
	am->attack();
	am->attack();
	am->attack();
	am->attack();
	am->attack();
	AlienDrone* ad1 = new AlienDrone(this);
	ad1->set_power(200);
	ad1->set_attackCap(4);
	ad1->set_health(200);
	ad1->attack();
	cout << "=========================" << endl;
	cout << "=========================" << endl;
	cout << "=========================" << endl;

	while (eArmy->pickTank(et)) {
		et->disp();
		cout << "=========================" << endl;
		h2.pop(et);
	}
	while (eArmy->pickGun(eg)) {
		eg->disp();
		cout << "=========================" << endl;
		h.enqueue(eg);
	}

	while (!h.isEmpty()) {
		h.dequeue(eg);
		eArmy->addUnit(eg);
	}
	while (!h2.isEmpty()) {
		h2.pop(et);
		eArmy->addUnit(et);
	}

	uml->print();
	dead->print();
	

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
	// Test AS Attack
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
}

void game::fight(int mode)
{
		inputFn();
		bool fight = true;
			srand(time(0));
			int mainColor = 7, messageColor = 6;
		if (mode == 1)
		{
			

			while (true) {
				//if (timestep > 40)
				//{
				//	if (alienIsEmpty() and !earthIsEmpty())
				//	{
				//		//earth winner
				//		system("cls");
				//		result = 1;

				//		changeColor(messageColor);///////
				//		cout << "**********		EARTH ARMY WINS		************";
				//		changeColor(mainColor);
				//		break;
				//	}
				//	else if (!alienIsEmpty() and earthIsEmpty())
				//	{
				//		result = -1;

				//		system("cls");
				//		changeColor(messageColor);///////
				//		cout << "**********		ALIEN ARMY WINS		************";
				//		changeColor(mainColor);
				//		break;
				//	}
				//	else if(alienIsEmpty() and earthIsEmpty())
				//	{
				//		result = 0;

				//		system("cls");
				//		changeColor(messageColor);///////
				//		cout << "**********		DRAW NO ONE WIN		************";
				//		changeColor(mainColor);
				//		break;
				//	}
				//}
				changeColor(12);
				cout << endl << " Current Timestep: " << timestep << endl;
				changeColor(mainColor);

				fillArmies();

				// Print Armies
				eArmy->print();
				aArmy->print();
				
				//Start Fighting 
				cout << "\n============== Units fighting at current step ==============" << endl;//must be changed with current step 
				eArmy->attack();
				aArmy->attack();
				uml->print();
				// Heal Units To Be Healed
				eArmy->heal();
				cout << "\n============== killed/Destructed Units ==============" << endl;
				dead->print();
				cout << "\n============== Infected Units ==============" << endl;
				cout << " Infected Percentage: ";
				if (eArmy->get_soldierList()->getCount() > 0) cout << float(eArmy->getInfectedCount() * 100 / eArmy->get_soldierList()->getCount()) << "%" << endl;
				else cout << "0%" << endl;
				int x;
				eArmy->get_soldierList()->print(ES);
				if (eArmy->getInfectedCount() < 0)
				{
					cout << "error" << endl;
					cin >> x;
				}
				timestep++;
				cout << endl << "Press Enter To Continue" << endl;
				if (timestep > 100)
					cin.get(); // Wait for user to press enter
				//system("cls");
			}
		}
		else {
			set_mode(2); 
			cout << "Simulation starts ....\n";
			while (fight) {
				if (timestep > 40)
				{
					if (alienIsEmpty() and !earthIsEmpty())
					{
						//earth winner
						result = 1;
						break;
					}
					else if (!alienIsEmpty() and earthIsEmpty())
					{
						result = -1;
						break;
					}
					else if (alienIsEmpty() and earthIsEmpty())
					{
						result = 0;
						break;
					}
				}
			

				fillArmies();

				// Print Armies
				


				//Start Fighting
				eArmy->attack();
				aArmy->attack();
				timestep++;
				
			}
			cout << "Simulation ends....\n";
		}
		tempList temp;
		unit* temp_unit;
			while (aArmy->get_droneList()->removeFront(temp_unit)) {
				temp_unit->set_distructionTime(timestep);
				temp.enqueue(temp_unit);
			}
			while (temp.dequeue(temp_unit)) {
				aArmy->addUnit(temp_unit);
			}
			while (aArmy->get_soldierList()->remove(temp_unit)) {
				temp_unit->set_distructionTime(timestep);
				temp.enqueue(temp_unit);
			}
			while (temp.dequeue(temp_unit)) {
				aArmy->addUnit(temp_unit);
			}
			while (aArmy->get_monsterList()->remove(temp_unit)) {
				temp_unit->set_distructionTime(timestep);
				temp.enqueue(temp_unit);
			}
			while (temp.dequeue(temp_unit)) {
				aArmy->addUnit(temp_unit);
			}
			while (eArmy->get_soldierList()->remove(temp_unit)) {
				temp_unit->set_distructionTime(timestep);
				temp.enqueue(temp_unit);
			}
			while (temp.dequeue(temp_unit)) {
				aArmy->addUnit(temp_unit);
			}
			while (eArmy->get_GunneryList()->remove(temp_unit)) {
				temp_unit->set_distructionTime(timestep);
				temp.enqueue(temp_unit);
			}
			while (temp.dequeue(temp_unit)) {
				aArmy->addUnit(temp_unit);
			}
			while (eArmy->get_tankList()->remove(temp_unit)) {
				temp_unit->set_distructionTime(timestep);
				temp.enqueue(temp_unit);
			}
			while (temp.dequeue(temp_unit)) {
				aArmy->addUnit(temp_unit);
			}
			while (eArmy->get_healers()->remove(temp_unit)) {
				temp_unit->set_distructionTime(timestep);
				temp.enqueue(temp_unit);
			}
			while (temp.dequeue(temp_unit)) {
				aArmy->addUnit(temp_unit);
			}
		outputFn();
}

void game::inputFn()
{
	ifstream in_file("input_file.text");
	in_file>> N >> Es >> Et >> Eg  >> Hu >> SaverCount >> As >> Am >> Ad >> InfectionProb >> Prob >> epower1 >> epower2 >> ehealth1 >> ehealth2 >> eattackcap1
		>> eattackcap2 >> apower1 >> apower2 >> ahealth1 >> ahealth2 >> aattackcap1 >> aattackcap2;
	ehealth2 = -1 * ehealth2;
	ahealth2 = -1 * ahealth2;
	epower2 = -1 * epower2;
	apower2 = -1 * apower2;
	eattackcap2 = -1 * eattackcap2;
	aattackcap2 = -1 * aattackcap2;
	RG->setParams(Es, Et, Eg, Hu, SaverCount,As, Am, Ad, InfectionProb,Prob, 
		epower1, epower2, ehealth1, ehealth2, eattackcap1, eattackcap2,
		apower1, apower2, ahealth1, ahealth2, aattackcap1, aattackcap2
		,N);
}

void game::outputFn()
{
	ofstream out_file("output_file.txt");
	out_file.clear();
	unit* killedunit;
	unit* alliveunit;
	tempList temp;
	int deadET,deadES, deadEG;
	int ET, ES, EG;
	int df=0, dd=0, db=0;
	ET = ES = EG = deadEG = deadES= deadET =0;
	while (dead->remove(killedunit)) {
		if (killedunit->get_id() >=2000)
		{
			temp.insert(killedunit);
			continue;
		}
		if (killedunit->get_type() == 2)
			deadES++;
		else if (killedunit->get_type() == 1)
			deadET++;
		else if (killedunit->get_type() == 0)
			deadEG++;
		df = df + killedunit->get_df();
		dd = dd + killedunit->get_dd();
		db = db + killedunit->get_db();
		out_file << "Distructed time: " << killedunit->get_td() << "   \n" << "First attacked time: "
			<< killedunit->get_ta() << "   \n"
			<< "ID: " << killedunit->get_id() << "   \n" <<
			"Type: "<<killedunit->get_type()<<"   \n"
			"Jion time: " << killedunit->get_tj() << "   \n" << "First attacked delay (Df): " << killedunit->get_df() << "   \n" <<
			"Destruction delay (Dd): "<<killedunit->get_dd() << "   \n" <<"Battle time(Db): " << killedunit->get_db() << "   \n"<<
			"__________________________________________________________________\n";
	}
	while (temp.remove(killedunit))
		dead->insert(killedunit);
	while (uml->remove(alliveunit)) {
		if (alliveunit->get_type() == 2)
			ES++;
		else if (alliveunit->get_type() == 1)
			ET++;
		df = df + alliveunit->get_df();
		dd = dd + alliveunit->get_dd();
		db = db + alliveunit->get_db();
	}
	while (eArmy->get_soldierList()->remove(alliveunit)) {
		df = df + alliveunit->get_df();
		dd = dd + alliveunit->get_dd();
		db = db + alliveunit->get_db();
			ES++;
		
	}
	while (eArmy->get_tankList()->remove(alliveunit)) {
		df = df + alliveunit->get_df();
		dd = dd + alliveunit->get_dd();
		db = db + alliveunit->get_db();
		ET++;

	}
	while (eArmy->get_GunneryList()->remove(alliveunit)) {
		df = df + alliveunit->get_df();
		dd = dd + alliveunit->get_dd();
		db = db + alliveunit->get_db();
		EG++;

	}
	out_file << "Earth army:-\n";
	out_file << "No of dead ES= " << deadES << "\n" << "No of dead ET= " << deadET << "\n" << "No of dead EG= " << deadEG << "\n";
	if ((deadES + ES) != 0)
		out_file << "Precentage of dead ES relative to their total= " << float(deadES )/ (deadES + ES) * 100 << "%\n";
	if ((deadET + ET) != 0)
		out_file<< "Precentage of dead ET relative to their total= " << float(deadET )/ (deadET + ET) * 100 << "%\n";
	if((deadEG + EG)!=0)
		out_file<< "Precentage of dead EG relative to their total= " << float(deadEG) / (deadEG + EG)* 100 << "%\n";
	if((deadET + ES + deadES + ET + deadEG + EG)!=0)
	out_file << "Precentage of total earth destrcted unit relative to their total= " <<
		float((deadES + deadET + deadEG) )/ (deadET + ES + deadES + ET + deadEG + EG) * 100 << "%\n";
	if((deadES + deadET + deadEG)!=0)
	{
		out_file << "Average Df= " << float(df / (deadES + deadET + deadEG)) << "\n "
			"Average Dd= " << float(dd )/ (deadES + deadET + deadEG) << "\n " <<
			"Average Db= " << float(db) / (deadES + deadET + deadEG) << "\n";
	}
	if(db!=0)
	out_file << "Df/Db%= " << float(df )/ db * 100 << "%\n" << "Dd/Db%= " << float(dd) / db * 100 << "%\n";
	if((deadET + ES + deadES + ET + deadEG + EG)!=0)
	out_file << "Precentage of units healed successfully relative to all units= " <<
		float(uml->get_healed_count() )/ (deadET + ES + deadES + ET + deadEG + EG) * 100<<"\n";
	out_file << "Batle result: ";
	if (result == 1)
			out_file << "Win \n";
	if (result == 0)
		out_file << "Drawn\n";
	if (result == -1)
		out_file << "Loss \n";
	int deadAS, deadAM, deadAD;
	int AS, AM, AD;
	AS = AM = AD = deadAS = deadAM = deadAD = 0;
	df =  dd =db = 0;
	while (dead->remove(killedunit)) {
		
		if (killedunit->get_type() == 4)
			deadAS++;
		else if (killedunit->get_type() == 5)
			deadAM++;
		else if (killedunit->get_type() == 6)
			deadAD++;
		df = df + killedunit->get_df();
		dd = dd + killedunit->get_dd();
		db = db + killedunit->get_db();
		out_file << "Distructed time: " << killedunit->get_td() << "   \n" << "ID: "
			<< "First attacked time: " << killedunit->get_ta() << "   \n"
			<< "Number of attacked: " << killedunit->get_Noofattacked()<<"   \n"
			<<"ID: " << killedunit->get_id() << "   \n" <<
			"Type: " << killedunit->get_type() << "   \n"
			"Jion time: " << killedunit->get_tj() << "   \n" << "First attacked delay (Df): " << killedunit->get_df() << "   \n" <<
			"Destruction delay (Dd): " << killedunit->get_dd() << "   \n" << "Battle time(Db): " << killedunit->get_db() << "   \n" <<
			"__________________________________________________________________\n";
	}
	while (aArmy->get_soldierList()->remove(alliveunit)) {
		df = df + alliveunit->get_df();
		dd = dd + alliveunit->get_dd();
		db = db + alliveunit->get_db();
			AS++;
		
	}
	while (aArmy->get_monsterList()->remove(alliveunit)) {
		df = df + alliveunit->get_df();
		dd = dd + alliveunit->get_dd();
		db = db + alliveunit->get_db();
		AM++;

	}
	while (aArmy->get_droneList()->removeFront(alliveunit)) {
		df = df + alliveunit->get_df();
		dd = dd + alliveunit->get_dd();
		db = db + alliveunit->get_db();
		AD++;

	}
	out_file << "Alien army:-\n";
	out_file << "No of dead AS= " << deadAS<<"\n" << "No of dead AM= " << deadAM << "\n" << "No of dead AD= " << deadAD << "\n";
	if ((deadAS + AS) != 0)
		out_file << "Precentage of dead AS relative to their total= " << float(deadAS )/ (deadAS + AS) * 100 << "%\n";
	if ((deadAM + AM) != 0)
		out_file << "Precentage of dead AM relative to their total= " << float(deadAM) / (deadAM + AM) * 100 << "%\n";
	if((deadAD + AD)!=0)
	    out_file <<"Precentage of dead AD relative to their total= "<<float(deadAD) / (deadAD + AD) * 100 << "%\n";
	if((deadAM + AS + deadAM + AM + deadAD + AD)!=0)
	out_file << "Precentage of total alien destrcted unit relative to their total= "<<
		float((deadAS + deadAM + deadAD) )/ (deadAM + AS + deadAS + AM + deadAD + AD) * 100 << "%\n";
	if((deadAS + deadAM + deadAD)!=0)
	{
		out_file << "Average Df= " << float(df / (deadAS + deadAM + deadAD)) << "\n "
			"Average Dd= " << float(dd )/ (deadAS + deadAM + deadAD)<< "\n " <<
			"Average Db= " << float(db )/ (deadAS + deadAM + deadAD) << "\n";
	}
	if(db!=0)
	out_file <<"Df/Db%= " << float(df )/ db* 100 << "%\n"<<"Dd/Db%= " << float(dd )/ db * 100 << "%\n";
		

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
		return dead->insert(u);
	}
	else return false;
}

int game::getInfectionProb()
{
	return InfectionProb;
}


void game::printKilled()
{
	dead->print();
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
	delete dead;

	delete RG;
	delete uml;
	dead = nullptr;
	uml = nullptr;
	aArmy = nullptr;
	eArmy = nullptr;

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

bool game::alienIsEmpty()
{
	return !(aArmy->getListCnt(AS) + aArmy->getListCnt(AM) + aArmy->getListCnt(AD));
}

bool game::earthIsEmpty()
{
	return !(eArmy->getListCnt(ES) + eArmy->getListCnt(ET) + eArmy->getListCnt(EG)+uml->get_curr_count()
		);//add uml count
}

