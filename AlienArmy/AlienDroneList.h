#pragma once
#include<iostream>
#include "../unit.h"
#include"../DS/double_endedQueue.h"
#include"AlienDrone.h"
using namespace std;

class AlienDroneList
{
	double_endedQueue<unit*> droneList;	
	int count;
public:
	
	AlienDroneList();
	~AlienDroneList();
	bool RemoveEnd(unit*& u);
	bool RemoveFront(unit*& u);
	bool InsertEnd(unit* u);		
	bool insertFront(unit* u);		
	void print();
	int getCount();
};

