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

void game::simulate(int mode)
{
	//phase 1.2 simualation code or delete the function
}

void game::fight(mode CurMode,selector s)
{
	inputFn( s);
	bool fight = true;
	srand(time(0));
	int mainColor = 7, messageColor = 6;
	if (CurMode==InterActive )
	{
		while (true) 
		{
			if (timestep > 40)
			{
				if (alienIsEmpty() and !earthIsEmpty())
				{
					//earth winner
					system("cls");
					battleHero = Earth;
					changeColor(messageColor);///////
					cout << "**********		EARTH ARMY WINS		************";
					changeColor(mainColor);
					break;
				}
				else if (!alienIsEmpty() and earthIsEmpty())
				{
					battleHero=ALien;
					system("cls");
					changeColor(messageColor);///////
					cout << "**********		ALIEN ARMY WINS		************";
					changeColor(mainColor);
					break;
				}
				else if(alienIsEmpty() and earthIsEmpty())
				{
					battleHero=drawn;
					system("cls");
					changeColor(messageColor);///////
					cout << "**********		DRAW NO ONE WIN		************";
					changeColor(mainColor);
					break;
				}
			}
			changeColor(12);
			cout << endl << " Current Timestep: " << timestep << endl;
			changeColor(mainColor);

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
				if (eArmy->get_soldierList()->getCount() > 0) 
					cout << float(eArmy->getInfectedCount() * 100 / eArmy->get_soldierList()->getCount()) << "%" << endl;
				else
					cout << "0%" << endl;

				timestep++;
				cout << endl << "Press Enter To Continue" << endl;
				//if (timestep > 100)
					//cin.get(); // Wait for user to press enter
				system("cls");
				if (!eArmy->getInfectedCount())
				{
					while (eArmy->get_SaverList()->remove(destroing))
						insertKilled(destroing);
				}
		}
	}
	else
	{
		set_mode(Silent);
		changeColor(9);

		cout << "Simulation starts...\n";
		while (true) 
		{
			if (timestep > 40)
			{
				if (alienIsEmpty() and !earthIsEmpty())
				{
					battleHero = Earth;
					break;
				}
				else if (!alienIsEmpty() and earthIsEmpty())
				{
					battleHero = ALien;
					break;
				}
				else if (Drawn())
				{
					battleHero = drawn;
					break;
				}
			}
			fillArmies();
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
		}
		changeColor(10);
		cout << "Simulation ends....\n";
	}
	tempList temp;
	unit* temp_unit;//destructor
	while (aArmy->get_droneList()->removeFront(temp_unit))
	{
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
		in_file.open("WeakEarth_WeakAliens.txt");
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
	out_file << "-------------------------:Batle result:---------------------------\n";
	if (battleHero == Earth)
		out_file << "------------------------------:Win:-------------------------------\n";
	if (battleHero == ALien)
		out_file << "----------------------------:Loss:-------------------------------\n";
	if (battleHero == drawn)
		out_file << "-----------------------------:Drawn:-------------------------------\n";


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
	changeColor(9);

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
	changeColor(8);

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
	if (!(uml->get_curr_count() > 0 and eArmy->getListCnt(EH) > 0) and !(eArmy->getListCnt(ES) + eArmy->getListCnt(ET) + eArmy->getListCnt(EG)))
		return true;
	return false;
}

bool game::Drawn()
{
	bool ES_empty, AS_empty, ET_empty, EG_empty,ESU_empty, EH_empty, AD_empty, AM_empty,UML_empty;
	ES_empty = AS_empty = ET_empty = EG_empty = ESU_empty = EH_empty = AD_empty = AM_empty = UML_empty = false;

	ES_empty = eArmy->getListCnt(ES) == 0;
	AS_empty = aArmy->getListCnt(AS) == 0;
	ET_empty = eArmy->getListCnt(ET) == 0;
	EG_empty = eArmy->getListCnt(EG) == 0;
	ESU_empty = eArmy->getListCnt(saver) == 0;
	EH_empty = eArmy->getListCnt(EH) == 0;
	AD_empty = aArmy->getListCnt(AD) == 0;
	AM_empty = aArmy->getListCnt(AM) == 0;
	UML_empty = uml->get_curr_count() == 0;

	if (!EH_empty and !UML_empty)
		return false;
	else
	{
		if (ES_empty and AS_empty and ET_empty and EG_empty and !ESU_empty and !AD_empty and AM_empty)
		{
			return true;
		}
		else if (ES_empty and !AS_empty and ET_empty and !EG_empty and ESU_empty and AD_empty and AM_empty)
		{
			return true;
		}
		else if (!ES_empty and AS_empty and ET_empty and EG_empty and ESU_empty and !AD_empty and AM_empty)
		{
			return true;
		}
	}
	return false;
}

