#pragma once
#include<iostream>
#include "../unit.h"
#include"../DS/double_endedQueue.h"
#include"AlienDrone.h"
using namespace std;

class AlienDroneList
{
	double_endedQueue<AlienDrone*> droneList;		
	int count;
public:
	
	AlienDroneList();
	~AlienDroneList();

	bool removeEnd(unit*& u);
	bool removeFront(unit*& u);
	bool insertEnd(AlienDrone* u);
	bool peekFront(unit*& u);
	bool peekBack(unit*& u);

	bool insertFront(AlienDrone* u);		
	void print();
	int getCount();
};

