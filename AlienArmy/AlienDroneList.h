#pragma once
#include<iostream>
#include "../unit.h"
#include"../DS/double_endedQueue.h"
#include"../DS/Node.h"
#include"AlienDrone.h"
using namespace std;

class AlienDroneList
{
	double_endedQueue<unit*> droneList;		//change list name
	int count;
public:
	
	AlienDroneList();
	bool RemoveEnd(unit*& u);
	bool RemoveFront(unit*& u);
	bool InsertEnd(unit* u);		//remove refrence
	bool insertFront(unit* u);		//remove refrence
	void print();
	int getCount();
};

