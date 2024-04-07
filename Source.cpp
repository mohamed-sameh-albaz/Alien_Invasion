#include <iostream>
#include"DS/LinkedQueue.h"
#include"DS/priQueue.h"
#include"DS/ArrayStack.h"
#include"AlienArmy/AlineDroneList.h"
#include"AlienArmy/AlienDrone.h"
#include"AlienArmy/MonsterList.h"
#include<fstream>
#include<string>
using namespace std;

void inputfn(int& N, int& Es, int& Et, int& Eg, int& As, int& Am, int& Ad, int& Prob) {
	ifstream f("in1.text");
	f >> N>>Prob>>Es>>Et>>Eg>>As>>Am>>Ad;

}
int main() {

	
	
	int n, es, et, eg, as, am, ad, prob;
	inputfn(n,es, et, eg, as, am, ad, prob);
	cout << n <<endl<< prob << endl << es << endl << et << endl << eg << endl << as << endl << am << endl << ad << endl << endl;
	/*
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
	
	m1.pickMonster();

	
	return 0;
}
