#include <iostream>
using namespace std;


#pragma once
class unit
{
	int id;
	string type;
	int joinTime;
	int health;
	int power;
	int attackCap;

public:
	void disp();
	void set_id(int a);
	void set_joinTime(int a);
	void set_health(int a);
	void set_power(int a);
	void set_attackCap(int a);
	void set_type(string s);
	int get_id();
	int get_joinTime();
	int get_health();
	int get_power();
	int get_attackCap();
	string get_type();

	virtual void attack() = 0;

};

