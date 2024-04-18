#include <iostream>
#include "monster.h"
using namespace std;

#pragma once
class MonsterList
{
	int n;
	int index;
	monster** monsters;
public:
	MonsterList();
	~MonsterList();

	bool insert(monster* m);
	bool remove(unit*& m); 
	void print(); 
	int getCount(); 
};

