#include <iostream>
using namespace std;


#pragma once
class unit
{
protected:
	int id;
	string type;
	int joinTime;
	int health;
	int power;
	int attackCap;

public:

	virtual void attack() = 0;

};

