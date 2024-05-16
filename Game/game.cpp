#include "game.h"
game::game() {
	RG = new randGen(this);
	earthCount = 1;
	alienCount = 2000;
	uml = new UML;
	aArmy = new AlienArmy;
	eArmy = new EarthArmy;
	dead = new QueueList;
	timestep = 1;
	GameMode = InterActive;
	battleHero = drawn;
}

void game::set_mode(mode GameMode )
{
	this->GameMode = GameMode;
}

mode game::get_mode()
{
	return GameMode;
}

void game::set_file_mode(selector s)
{
	file_mode = s;
}

void game::simulate(int mode)//add phase 1.2 simualation code or delete the func
{
	/*
	if(mode==1)
	{
		srand(time(0));
		SU s1(this),s2(this),s3(this);
		monster m1(this);
		EarthSoldier
		int mainColor = 7, messageColor = 6;
		inputFn();
		//testing drone

		SU* save = new SU(this);
		save->set_power(10);
		save->set_attackCap(10);
		save->set_health(100);
		save->disp();

		AlienSoldier t1(this), t2(this), t3(this);
		SU g1(this), g2(this), g3(this);

		//t1.set_id(1);
		//t1.set_health(100);
		//t2.set_id(2);
		//t2.set_health(100);
		//t3.set_id(3);
		//t3.set_health(100);
		//g1.set_id(4);
		//g1.set_health(100);
		//g2.set_id(5);
		//g2.set_health(100);
		//g3.set_id(6);
		//g3.set_health(100);

		//eArmy->addUnit(&t1);
		//eArmy->addUnit(&t2);
		//eArmy->addUnit(&t3);
		//eArmy->addUnit(&g1);
		////eArmy->addUnit(&g2);
		////eArmy->addUnit(&g3);

		//eArmy->print();

		//cout << "====================== Drone Attack ======================" << endl;
		//AM->attack();

		//cout << "After Attacking" << endl;
		//eArmy->print();
	
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

void game::fight(mode CurMode,selector s)
{
	bool Esoldier_empty, Asoldier_empty, Etank_empty, Egunnery_empty,
		Esu_empty, Ehealer_empty, Adrone_empty, Amonster_empty;
	Esoldier_empty = Asoldier_empty = Etank_empty = Egunnery_empty =
		Esu_empty = Ehealer_empty = Adrone_empty = Amonster_empty = 0;
	inputFn( s);
	bool fight = true;
	srand(time(0));
	int mainColor = 7, messageColor = 6;
	if (CurMode==InterActive )
	{









		while (true) {
			
			if (timestep > 40)
			{
		Esoldier_empty = eArmy->get_soldierList()->isEmpty();
		Etank_empty = eArmy->get_tankList()->isEmpty();
		Egunnery_empty = eArmy->get_GunneryList()->isEmpty();
		Esu_empty = eArmy->get_SaverList()->isEmpty();
		Ehealer_empty = eArmy->get_healers()->isEmpty();
		Asoldier_empty = aArmy->get_soldierList()->isEmpty();
		Adrone_empty = aArmy->get_droneList()->isEmpty();
		if (aArmy->get_monsterList()->getCount() == 0)
			Amonster_empty = 1;
		else Amonster_empty = 0;

				if (alienIsEmpty() and !earthIsEmpty())
				{
					//earth winner
					system("cls");

					battleHero = Earth;

					changeColor(245);
					cout << "**********		EARTH ARMY WINS		************";
					changeColor(mainColor);
					break;
				}
				else if (!alienIsEmpty() and earthIsEmpty())
				{

					battleHero=ALien;
					system("cls");
					changeColor(245);///////
					cout << "**********		ALIEN ARMY WINS		************";
					changeColor(245);
					break;
				}
				else if((alienIsEmpty() and earthIsEmpty() )or
					(Etank_empty&& Egunnery_empty&& Esu_empty&& Asoldier_empty&& Amonster_empty))
				{

					battleHero=drawn;
					system("cls");
					changeColor(245);
					cout << "**********		DRAW NO ONE WIN		************";
					changeColor(mainColor);
					break;
				}
			}
			changeColor(240);
			cout << endl << " Current Timestep: " << timestep << endl;
			changeColor(240);

			fillArmies();

				// Print Armies
				
				//Start Fighting 
				if(eArmy->get_soldierList()->getCount()>0)
				if (eArmy->getInfectedCount()*100/ eArmy->get_soldierList()->getCount() >= RG->get_threshold())
					RG->genAlliedArmy(eArmy);
				unit* destroing;
				eArmy->print();


				aArmy->print();
				cout << "\n============== Units fighting at current step ==============" << endl;//must be changed with current step 
				eArmy->attack();
				aArmy->attack();

				uml->print();
				// Heal Units To Be Healed
				eArmy->heal();
				cout << "\n============== killed/Destructed Units ==============" << endl;
				dead->print(Dead);
				cout << "\n============== Infected Units ==============" << endl;
				cout << "Infected Percentage: ";
				if (eArmy->get_soldierList()->getCount() > 0) cout << float(eArmy->getInfectedCount() * 100 / eArmy->get_soldierList()->getCount()) << "%" << endl;
				else cout << "0%" << endl;

				timestep++;
				cout << endl << "Press Enter To Continue" << endl;
				//if (timestep > 100)
					cin.get(); // Wait for user to press enter
				system("cls");
				if (!eArmy->getInfectedCount())
				{
					while (eArmy->get_SaverList()->remove(destroing))
						insertKilled(destroing);
				}
			}
		}
		else {
			set_mode(Silent);

			cout << "Simulation starts...\n";
			while (true) {
				if (timestep > 40)
				{
					Esoldier_empty = eArmy->get_soldierList()->isEmpty();
					Etank_empty = eArmy->get_tankList()->isEmpty();
					Egunnery_empty = eArmy->get_GunneryList()->isEmpty();
					Esu_empty = eArmy->get_SaverList()->isEmpty();
					Ehealer_empty = eArmy->get_healers()->isEmpty();
					Asoldier_empty = aArmy->get_soldierList()->isEmpty();
					Adrone_empty = aArmy->get_droneList()->isEmpty();
					if (aArmy->get_monsterList()->getCount() == 0)
						Amonster_empty = 1;
					else Amonster_empty = 0;					if (alienIsEmpty() and !earthIsEmpty())
					{
						//earth winner
						battleHero = Earth;

						
						break;
					}
					else if (!alienIsEmpty() and earthIsEmpty())
					{
						battleHero = ALien;

						
						break;
					}
					else if (alienIsEmpty() and earthIsEmpty())
					{
						battleHero = drawn;

						
						break;
					}
				}
				

				fillArmies();

				// Print Armies

				//Start Fighting 
				if (eArmy->get_soldierList()->getCount() > 0)
					if (eArmy->getInfectedCount() * 100 / eArmy->get_soldierList()->getCount() >= RG->get_threshold())
						RG->genAlliedArmy(eArmy);
				unit* destroing;


				eArmy->attack();
				aArmy->attack();

				// Heal Units To Be Healed
				eArmy->heal();
				
				
				

				if (!eArmy->getInfectedCount())
				{
					while (eArmy->get_SaverList()->remove(destroing))
						insertKilled(destroing);
				}
				timestep++;
				//if (timestep > 100)
				
			}
			changeColor(245);

			cout << "Simulation ends....\n";
		}
		tempList temp;
		unit* temp_unit;//destructor
			while (aArmy->get_droneList()->removeFront(temp_unit)) {
				temp_unit->set_distructionTime(timestep);
				temp.insert(temp_unit);
			}
			while (temp.remove(temp_unit)) {
				aArmy->addUnit(temp_unit);
			}
			while (aArmy->get_soldierList()->remove(temp_unit)) {
				temp_unit->set_distructionTime(timestep);
				temp.insert(temp_unit);
			}
			while (temp.remove(temp_unit)) {
				aArmy->addUnit(temp_unit);
			}
			while (aArmy->get_monsterList()->remove(temp_unit)) {
				temp_unit->set_distructionTime(timestep);
				temp.insert(temp_unit);
			}
			while (temp.remove(temp_unit)) {
				aArmy->addUnit(temp_unit);
			}
			while (eArmy->get_soldierList()->remove(temp_unit)) {
				temp_unit->set_distructionTime(timestep);
				temp.insert(temp_unit);
			}
			while (temp.remove(temp_unit)) {
				eArmy->addUnit(temp_unit);
			}
			while (eArmy->get_SaverList()->remove(temp_unit)) {
				temp_unit->set_distructionTime(timestep);
				temp.insert(temp_unit);
			}
			while (temp.remove(temp_unit)) {
				eArmy->addUnit(temp_unit);
			}
			while (eArmy->get_GunneryList()->remove(temp_unit)) {
				temp_unit->set_distructionTime(timestep);
				temp.insert(temp_unit);
			}
			while (temp.remove(temp_unit)) {
				eArmy->addUnit(temp_unit);
			}
			while (eArmy->get_tankList()->remove(temp_unit)) {
				temp_unit->set_distructionTime(timestep);
				temp.insert(temp_unit);
			}
			while (temp.remove(temp_unit)) {
				eArmy->addUnit(temp_unit);
			}
			while (eArmy->get_healers()->remove(temp_unit)) {
				temp_unit->set_distructionTime(timestep);
				temp.insert(temp_unit);
			}
			while (temp.remove(temp_unit)) {
				eArmy->addUnit(temp_unit);
			}
		outputFn();
}

void game::inputFn(selector s)
{
	ifstream in_file;
	if(s==strong_moderete)
	 in_file.open("StrongEarth_ModerateAliens.txt");
	else if (s == strong_strong)
		in_file.open("StrongEarth_StrongAliens.txt");
	else if (s == strong_weak)
		in_file.open("StrongEarth_WeakAliens.txt");
	else if (s == weak_moderete)
		in_file.open("WeakEarth_ModerateAliens.txt");
	else if (s == weak_strong)
		in_file.open("WeakEarth_StrongAliens.txt");
	else if (s == weak_weak)
		in_file.open("WeakEarth_StrongAliens.txt");
	in_file>> N >> Es >> Et >> Eg  >> Hu >> SaverCount >> threshold >>As >> Am >> Ad >> InfectionProb >> Prob >> epower1 >> epower2 >> ehealth1 >> ehealth2 >> eattackcap1
		>> eattackcap2 >> apower1 >> apower2 >> ahealth1 >> ahealth2 >> aattackcap1 >> aattackcap2;
	ehealth2 = -1 * ehealth2;
	ahealth2 = -1 * ahealth2;
	epower2 = -1 * epower2;
	apower2 = -1 * apower2;
	eattackcap2 = -1 * eattackcap2;
	aattackcap2 = -1 * aattackcap2;
	RG->setParams(Es, Et, Eg, Hu, SaverCount,threshold,As, Am, Ad, InfectionProb,Prob, 
		epower1, epower2, ehealth1, ehealth2, eattackcap1, eattackcap2,
		apower1, apower2, ahealth1, ahealth2, aattackcap1, aattackcap2,N);
}

void game::outputFn()///////////////////modify using Enum
{
	ofstream out_file("output.txt");
	out_file.clear();
	unit* killedunit;
	unit* alliveunit;
	tempList temp;
	int deadET,deadES, deadEG,deadSU,deadHU;
	int ET, ES, EG,SU,HU;
	int df=0, dd=0, db=0;
	ET = ES = EG = deadEG = deadES= deadET = deadSU = SU =HU=deadHU=0;
	out_file << "--------------------------:Earth army:----------------------------\n";
		while (dead->remove(killedunit)) {
		if (killedunit->get_id() >=2000)
		{
			temp.insert(killedunit);
			continue;
		}
			
		if (killedunit->get_type() == 2)//change nums to enum value
			deadES++;
		else if (killedunit->get_type() == 1)
			deadET++;
		else if (killedunit->get_type() == 0)
			deadEG++;
		else if (killedunit->get_type() == saver)
			deadSU++;
		else if (killedunit->get_type() == 3)
			deadHU++;
		if (killedunit->get_type() != 3)
		
			df = df + killedunit->get_df();
			dd = dd + killedunit->get_dd();
			db = db + killedunit->get_db();
		
		out_file << "Distructed time: " << killedunit->get_td() << "   \n" <<
			"First attacked time: "<< killedunit->get_ta() << "   \n"
			<< "Number of times be attacked: " << killedunit->get_Noofattacked() << "   \n"

			<< "ID: " << killedunit->get_id() << "   \n";
		
		switch (killedunit->get_type())
		{
		case 0:out_file << "type:Gunnery\n";
			break;
		case 2:out_file << "type:Earth Soldier\n";
			break;

		case 3:out_file << "type:Earth Healer\n";
			break;

		case 1:out_file << "type:Tank\n";
			break;

		
		case saver:out_file << "type:Saver\n";
			break;

		}
		out_file<<	"Jion time: " << killedunit->get_tj() << "   \n" << "First attacked delay (Df): " << killedunit->get_df() << "   \n" <<
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
		
	}
	while (eArmy->get_soldierList()->remove(alliveunit)) {
		
			ES++;
		
	}
	while (eArmy->get_healers()->remove(alliveunit)) {

		HU++;

	}
	while (eArmy->get_tankList()->remove(alliveunit)) {
		
		ET++;

	}
	while (eArmy->get_GunneryList()->remove(alliveunit)) {
		
		EG++;

	}
	while (eArmy->get_SaverList()->remove(alliveunit)) {
		
		SU++;

	}

	out_file 	 << "--------------------------:Earth army:----------------------------\n"

		<<"------------------------------------------------------------------\nNo of  ES = " << deadES +ES<< "\n" << "No of  ET = " << deadET +ET<< "\n" << "No of  EG = " 
		<< deadEG +EG<< "\n"<<"No of  SU="<<deadSU+SU<<"\n" << "No of  HU=" << deadHU + HU << "\n";
	if ((deadES + ES) != 0)
		out_file << "Precentage of dead ES relative to their total= " << float(deadES )/ (deadES + ES) * 100 << "%\n";
	if ((deadET + ET) != 0)
		out_file<< "Precentage of dead ET relative to their total= " << float(deadET )/ (deadET + ET) * 100 << "%\n";
	if((deadEG + EG)!=0)
		out_file<< "Precentage of dead EG relative to their total= " << float(deadEG) / (deadEG + EG)* 100 << "%\n";
	if ((deadSU + SU) != 0)
		out_file << "Precentage of dead SU relative to their total= " << float(deadSU) / (deadSU + SU) * 100 << "%\n";
	if ((deadHU + HU) != 0)
		out_file << "Precentage of dead healers relative to their total= " << float(deadHU) / (deadHU + HU) * 100 << "%\n";
	if((deadET + ES + deadES + ET + deadEG + EG+ deadSU+ SU+ deadHU + HU)!=0)
	out_file << "Precentage of total earth destrcted unit relative to their total= " <<
		float((deadES + deadET + deadEG+ deadSU+deadHU) )/ (deadET + ES + deadES + ET + deadEG + EG+deadSU + SU+deadHU+HU) * 100 << "%\n";
	if ((deadES + deadET + deadEG + deadSU) != 0)

		out_file << "Average Df= " << float(df) / (deadES + deadET + deadEG + deadSU) << "\n";
	if ((deadES + deadET + deadEG + deadSU+ deadHU) != 0)

	{
		out_file << "Average Dd= " << float(dd) / (deadES + deadET + deadEG + deadSU + deadHU) << "\n";
		out_file << "Average Db= " << float(db) / (deadES + deadET + deadEG + deadSU + deadHU) << "\n";
	}
	
	if(db!=0)
	out_file << "Df/Db%= " <<float(df) /  db * 100 << "%\n" << "Dd/Db%= " <<
		float(dd) / db * 100 << "%\n";
	if((deadET + ES + deadES + ET + deadEG + EG+deadSU + SU)!=0)
	out_file << "Precentage of units healed successfully relative to all units= " <<
		float(uml->get_healed_count() )/ (deadET + ES + deadES + ET + deadEG + EG+ deadSU + SU) * 100<<"%\n";
	out_file << "-------------------------:Batle result:---------------------------\n";
	if (battleHero == Earth)
		out_file << "------------------------------:Win:-------------------------------\n";
	if (battleHero == ALien)
		out_file << "----------------------------:Loss:-------------------------------\n";
	if (battleHero == drawn)
		out_file << "-----------------------------:Drawn:-------------------------------\n";
	int deadAS, deadAM, deadAD;
	int AS, AM, AD;
	AS = AM = AD = deadAS = deadAM = deadAD = 0;
	df =  dd =db = 0;
	out_file << "--------------------------:Alien army:----------------------------\n";
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
		out_file << "Distructed time: " << killedunit->get_td() << "   \n"
			<< "First attacked time: " << killedunit->get_ta() << "   \n"
			<< "Number of times be attacked: " << killedunit->get_Noofattacked() << "   \n"
			<< "ID: " << killedunit->get_id() << "   \n";
			switch (killedunit->get_type())
			{
			case 4:out_file << "type:Alien Soldier\n";
				break;

			case 6:out_file << "type:Alien Drone\n";
				break;

			case 5:out_file << "type:Monster\n";
				break;

			}
		out_file<<"Jion time: " << killedunit->get_tj() << "   \n" << "First attacked delay (Df): " << killedunit->get_df() << "   \n" <<
			"Destruction delay (Dd): " << killedunit->get_dd() << "   \n" << "Battle time(Db): " << killedunit->get_db() << "   \n" <<
			"__________________________________________________________________\n";
	}
	while (aArmy->get_soldierList()->remove(alliveunit)) {
		
			AS++;
		
	}
	while (aArmy->get_monsterList()->remove(alliveunit)) {
		
		AM++;

	}
	while (aArmy->get_droneList()->removeFront(alliveunit)) {
		
		AD++;

	}

	out_file << "--------------------------:Alien army:----------------------------\n";

	out_file << "__________________________________________________________________\nNo of  AS = " << deadAS+AS<<"\n" << "No of  AM = " << deadAM+AM << "\n" << "No of  AD = " << deadAD+AD << "\n";
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
		out_file << "Average Df= " << float(df) / (deadAS + deadAM + deadAD) << "\n "
			<<"Average Dd= " << float(dd )/ (deadAS + deadAM + deadAD) << "\n " <<
			"Average Db= " << float(db )/ (deadAS + deadAM + deadAD) << "\n";
	}
	if(db!=0)
	out_file <<"Df/Db%= " << float(df )/ db* 100 << "%\n"<<"Dd/Db%= " << float(dd )/ db * 100 << "%\n__________________________________________________________________\n";
		

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
	dead->print(Dead);
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
	return (2000 - alienCount);
}

bool game::alienIsEmpty()
{
	return !(aArmy->getListCnt(AS) + aArmy->getListCnt(AM) + aArmy->getListCnt(AD));
}

bool game::earthIsEmpty()
{
	return !(eArmy->getListCnt(ES) + eArmy->getListCnt(ET) + eArmy->getListCnt(EG)+uml->get_curr_count());
}

