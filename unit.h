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
	int tj, ta, td, df, dd, db, attackpower;

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
	void set_atackedTime(int a);
	void set_distructionTime(int a);
	int get_tj();
	int get_ta();
	int get_td();
	int get_df();
	int get_dd();
	int get_db();
	void set_attackpower(unit*u);
	int get_attackpower();

	string get_type();

	virtual void attack() = 0;

};

