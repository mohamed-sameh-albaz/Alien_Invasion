#pragma once
#include <iostream>
#include "monster.h"
using namespace std;

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
	bool peek(unit*& m);
	void print(); 
	int getCount(); 
};

