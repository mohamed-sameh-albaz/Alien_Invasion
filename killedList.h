#pragma once
#include<iostream>
#include"unit.h"
#include"DS/LinkedQueue.h"
using namespace std;

class killedList
{
	LinkedQueue<unit*> deadList;
	int count;

public:
	killedList(); 

	~killedList();
	

	bool insert(unit*& killedUnit);
	
	void print();
	
	
};

