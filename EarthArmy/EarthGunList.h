#pragma once
#include<iostream>
#include"../unit.h"
#include"EarthGun.h"
#include"../DS/priQueue.h"
using namespace std;

class EarthGunList
{
	priQueue<EarthGun*> GunList;
	int count;
public:
	EarthGunList();
	~EarthGunList();
	bool insert(EarthGun* newGun);
	bool peek(unit*& peekedUnit);
	bool remove(unit*& deletedUnit);
	int getCount();
	void print();
};

