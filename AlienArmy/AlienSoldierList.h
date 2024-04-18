#pragma once
#include<iostream>
#include"../DS/LinkedQueue.h"
#include"AlienSoldier.h" //including soldier
#include"../unit.h"
using namespace std;

class AlienSoldierList
{
	LinkedQueue<AlienSoldier*> alienSoldierList; //change list name
	int count;
public:
	AlienSoldierList();
	~AlienSoldierList();

	bool insert(AlienSoldier* u);		//remove refrence 
	bool remove(unit*& u);
	void print();
	int getCount();
};

