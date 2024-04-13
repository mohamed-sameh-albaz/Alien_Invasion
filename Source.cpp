#include <iostream>
#include"DS/LinkedQueue.h"
#include"DS/priQueue.h"
#include"DS/ArrayStack.h"
#include"AlienArmy/AlienArmy.h"
#include"AlienArmy/AlineDroneList.h"
#include"AlienArmy/MonsterList.h"
#include"AlienArmy/AlineSoldierList.h"
#include"EarthArmy/EarthArmy.h"
#include"EarthArmy/EarthTankList.h"
#include"EarthArmy/EarthGunList.h"
#include"EarthArmy/EarthSoldierList.h"
#include"EarthArmy/HL.h"
#include"EarthArmy/UML.h"
#include"killedList.h"
#include<fstream>
#include<string>
#include "randGen.h"
using namespace std;

void inputfn(int& N, int& Es, int& Et, int& Eg,int&Hu, int& As, int& Am, int& Ad, int& Prob,
	int& epower1, int& epower2, int& ehealth1, int& ehealth2, int& eattackcap1, int& eattackcap2,
	int& apower1, int& apower2, int& ahealth1, int& ahealth2, int& aattackcap1, int& aattackcap2) {
	ifstream f("in1.text");
	f >> N>>Prob>>Es>>Et>>Eg>>Hu>>As>>Am>>Ad>> epower1>> epower2>> ehealth1>> ehealth2>> eattackcap1
		>> eattackcap2>> apower1>> apower2>> ahealth1>> ahealth2>> aattackcap1>> aattackcap2;
	ehealth2 = -1 * ehealth2;
	ahealth2 = -1 * ahealth2;
	epower2 = -1 * epower2;
	apower2 = -1 * apower2;
	eattackcap2 = -1 * eattackcap2;
	aattackcap2 = -1 * aattackcap2;
	if (Hu > 5)
		Hu = 5;
}
int main() {

	cout << "test main" << endl;
	
	////////testing earth army///////////
	EarthArmy earthArmy;
	AlienArmy alienArmy;
	killedList deadlist;
	unit* t1,* t2,* g1,* g2,* s1,* s2;
	unit* d1,* d2,* m1,* m2,* s3,* s4;
	unit* pickedUnit;
	int pri;

	t1 = new EarthTank;t2 = new EarthTank;
	t1->set_id(1);t2->set_id(2);

	g1 = new EarthGun;		g2 = new EarthGun;
	g1->set_id(3);			g2->set_id(4);
	g1->set_health(100);	g2->set_health(200);
	g1->set_power(200);		g2->set_power(300);

	s1 = new EarthSoldier;	s2 = new EarthSoldier;
	s1->set_id(5);			s2->set_id(6);
	
	d1 = new AlienDrone;	d2 = new AlienDrone;
	d1->set_id(100);		d2->set_id(101);

	m1 = new monster;		m2 = new monster;
	m1->set_id(102);		m2->set_id(103);

	s3 = new AlienSoldier;	s4 = new AlienSoldier;
	s3->set_id(104);		s4->set_id(105);
	
	earthArmy.addUnit(t1);	earthArmy.addUnit(t2);
	earthArmy.addUnit(s1);	earthArmy.addUnit(s2);
	earthArmy.addUnit(g1);	earthArmy.addUnit(g2);
	
	alienArmy.addUnit(d1);	alienArmy.addUnit(d2);
	alienArmy.addUnit(m1);	alienArmy.addUnit(m2);
	alienArmy.addUnit(s3);	alienArmy.addUnit(s4);

	earthArmy.print();
	alienArmy.print();
	deadlist.print();

	cout << "\n======picking gunnery========" << endl;
	earthArmy.pickGun(pickedUnit ,pri);
	cout << "picked unit info::\n";
	pickedUnit->disp();
	deadlist.insert(pickedUnit);

	cout << "\n======picking alienSoldier========" << endl;
	alienArmy.pickSoldier(pickedUnit);
	cout << "picked unit info::\n";
	pickedUnit->disp();
	deadlist.insert(pickedUnit);

	cout << "\n======picking tank========" << endl;
	earthArmy.pickTank(pickedUnit);
	cout << "picked unit info::\n";
	pickedUnit->disp();
	deadlist.insert(pickedUnit);

	cout << "\n======picking monster========" << endl;
	alienArmy.pickMonster(pickedUnit);
	cout << "picked unit info::\n";
	pickedUnit->disp();
	deadlist.insert(pickedUnit);

	earthArmy.print();
	alienArmy.print();
	deadlist.print();

	


	//deadlist.print();
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

	///////testing monster////////
	/*MonsterList M;
	monster m1, m2, m3;
	m1.set_id(1);
	m2.set_id(2);
	m3.set_id(3);

	M.insert(&m1);
	M.insert(&m2);
	M.insert(&m3);

	M.print();

	unit* u = nullptr;
	M.remove(u);

	cout << endl << "###############" << endl;

	M.print();

	M.remove(u);

	cout << endl << "###############" << endl;

	M.print();*/

	/*
	/////////////// testing tankList ////////////
	EarthTankList tankList;
	EarthTank t1;
	EarthTank t2;
	t1.set_id(1);
	t2.set_id(2);
	tankList.insert(&t1);
	tankList.insert(&t2);
	cout << "Printing list\n";
	tankList.print();
	unit* u = nullptr;

	cout << "\n\n########## Picking Tank ##########\n\n";
	tankList.remove(u);
	cout << "Printing list\n";
	tankList.print();
	cout << "\n picked Tank info::\n";
	u->disp();

	cout << "\n\n########## Picking Tank ##########\n\n";
	tankList.remove(u);
	cout << "Printing list\n";
	tankList.print();
	cout << "\n picked Tank info::\n";
	u->disp();

	cout << "\n\n########## Picking Tank ##########\n\n";
	tankList.remove(u);
	cout << "\n\n##########\n\n";
	*/

	////////// testing gunList ////////////
	
	//EarthGunList GunList;
	//EarthGun g1;
	//EarthGun g2;
	//g1.set_id(1);
	//g1.set_health(100);
	//g1.set_power(200);
	//g2.set_id(2);
	//g2.set_health(200);
	//g2.set_power(300);
	//GunList.insert(&g1);
	//GunList.insert(&g2);
	//cout << "Printing list\n";
	//GunList.print();
	//unit* u = nullptr;
	//int pri;
	//cout << "\n\n########## Picking Gunnery ##########\n\n";
	//GunList.remove(u,pri);
	//cout << "Printing list\n";
	//GunList.print();
	//cout << "\n picked Gunnery info::\n";
	//u->disp();

	//cout << "\n\n########## Picking Gunnery ##########\n\n";
	//GunList.remove(u,pri);
	//cout << "Printing list\n";
	//GunList.print();
	//cout << "\n picked Gunnery info::\n";
	//u->disp();

	//cout << "\n\n########## Picking Gunnery ##########\n\n";
	//GunList.remove(u,pri);
	//cout << "\n\n##########\n\n";
	//
	
	// Testing Random Generator //

	/*randGen r;
	r.setParams(70, 20, 10, 80, 12, 8, 100, 3, 50, 30, 90, 2, 5, 1, 20, 40, 80, 1, 4);

	unit* u = r.generateAlienUnit(7);

	if (u) u->disp();
	else cout << "No Object To Show"; */
	

	/*Healer h1, h2;
	h1.set_id(1);
	h2.set_id(2);

	HL h;
	h.add(&h1);
	h.add(&h2);

	h.print();
	Healer h0;
	h.add(&h0);
	h.print();*/

	/////// testing EarthSoldierList ////////////

	/*EarthSoldierList soldierList;
	EarthSoldier g1;
	EarthSoldier g2;
	g1.set_id(1);
	g2.set_id(2);
	soldierList.insert(&g1);
	soldierList.insert(&g2);
	cout << "Printing list\n";
	soldierList.print();
	unit* u = nullptr;
	cout << "\n\n########## Picking soldier ##########\n\n";
	soldierList.remove(u);
	cout << "Printing list\n";
	soldierList.print();
	cout << "\n picked soldier info::\n";
	u->disp();

	cout << "\n\n########## Picking soldier ##########\n\n";
	soldierList.remove(u);
	cout << "Printing list\n";
	soldierList.print();
	cout << "\n picked soldier info::\n";
	u->disp();

	cout << "\n\n########## Picking soldier ##########\n\n";
	soldierList.remove(u);
	cout << "\n\n##########\n\n";*/
	
	/////// testing alienSoldierList ////////////

	//AlineSoldierList soldierList;
	//AlienSoldier g1;
	//AlienSoldier g2;
	//g1.set_id(1);
	//g2.set_id(2);
	//soldierList.insert(&g1);
	//soldierList.insert(&g2);
	//cout << "Printing list\n";
	//soldierList.print();
	//unit* u = nullptr;
	//cout << "\n\n########## Picking soldier ##########\n\n";
	//soldierList.remove(u);
	//cout << "Printing list\n";
	//soldierList.print();
	//cout << "\n picked soldier info::\n";
	//u->disp();
	//
	//cout << "\n\n########## Picking soldier ##########\n\n";
	//soldierList.remove(u);
	//cout << "Printing list\n";
	//soldierList.print();
	//cout << "\n picked soldier info::\n";
	//u->disp();
	//
	//cout << "\n\n########## Picking soldier ##########\n\n";
	//soldierList.remove(u);
	//cout << "\n\n##########\n\n";

	return 0;
}
