#include <iostream>
#include"DS/LinkedQueue.h"
#include"DS/priQueue.h"
#include"DS/ArrayStack.h"
#include"AlienArmy/AlineDroneList.h"
#include"AlienArmy/AlienDrone.h"
#include"AlienArmy/MonsterList.h"
#include"EarthArmy/HL.h"
#include"EarthArmy/UML.h"
#include<fstream>
#include<string>
using namespace std;

void inputfn(int& N, int& Es, int& Et, int& Eg, int& As, int& Am, int& Ad, int& Prob,
	int& epower1, int& epower2, int& ehealth1, int& ehealth2, int& eattackcap1, int& eattackcap2,
	int& apower1, int& apower2, int& ahealth1, int& ahealth2, int& aattackcap1, int& aattackcap2) {
	ifstream f("in1.text");
	f >> N>>Prob>>Es>>Et>>Eg>>As>>Am>>Ad>> epower1>> epower2>> ehealth1>> ehealth2>> eattackcap1
		>> eattackcap2>> apower1>> apower2>> ahealth1>> ahealth2>> aattackcap1>> aattackcap2;
	ehealth2 = -1 * ehealth2;
	ahealth2 = -1 * ahealth2;
	epower2 = -1 * epower2;
	apower2 = -1 * apower2;
	eattackcap2 = -1 * eattackcap2;
	aattackcap2 = -1 * aattackcap2;

}
int main() {

	
	
	/*
	int n, es, et, eg, as, am, ad, prob,epower1,epower2,ehealth1,ehealth2,eattackcap1,eattackcap2,
		apower1, apower2, ahealth1, ahealth2, aattackcap1, aattackcap2;
	inputfn(n,es, et, eg, as, am, ad, prob,epower1, epower2, ehealth1, ehealth2,
		eattackcap1, eattackcap2,
		apower1, apower2, ahealth1, ahealth2, aattackcap1, aattackcap2);
	cout << n <<endl<< prob << endl << es << endl << et << endl << eg << endl << as << endl << am << endl << ad << endl << epower1
		<< endl << epower2<< endl << ehealth1 << endl << ehealth2<< endl << eattackcap1<< endl << eattackcap2
		<< endl << apower1<< endl << apower2 <<  endl << ahealth1 << endl << ahealth2 << endl << aattackcap1 << endl << 
		aattackcap2 <<endl << endl;
	AlineDroneList a;
	unit* u1=new AlienDrone ;
	unit* u2= new AlienDrone;
	unit* u = new AlienDrone;

	u1->set_id(1);
	u1->set_joinTime(2);
	u1->set_attackCap(5);
	u1->set_health(30);
	u1->set_power(22);
	u2->set_id(2);
	u2->set_joinTime(55);
	u2->set_attackCap(556);
	u2->set_health(340);
	u2->set_power(225);
	a.enqueue(u1);
	a.enqueue(u2);
	a.disp();

	a.dequeue(u);
	a.disp();
	a.enqueue(u);
	a.disp();
	a.dequeueBack(u);
	a.disp();
	*/
	cout << "test main" << endl;
	MonsterList m1(5);
	monster M1, M2, M3,M4;
	M1.set_id(1);
	M2.set_id(2);
	M3.set_id(3);
	M4.set_id(4);

	m1.addMonster(&M1);
	m1.addMonster(&M2);
	m1.addMonster(&M3);
	m1.addMonster(&M4);

	m1.print();

	
	return 0;
}
