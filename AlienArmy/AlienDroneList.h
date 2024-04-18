#pragma once
#include<iostream>
#include "../unit.h"
#include"../DS/double_endedQueue.h"
#include"AlienDrone.h"
using namespace std;

class AlienDroneList
{
	double_endedQueue<AlienDrone*> droneList;		//change list name
	int count;
public:
	
	AlienDroneList();
	~AlienDroneList();

	bool removeEnd(unit*& u);
	bool removeFront(unit*& u);
	bool insertEnd(AlienDrone* u);		//remove refrence
	bool insertFront(AlienDrone* u);		//remove refrence
	void print();
	int getCount();
};

