#pragma once
#include <iostream>
using namespace std;
class game;
enum type { EG, ET, ES, EH, AS, AM, AD, saver ,Dead};

class unit
{
protected:
	int id;
	type unitType;
	int health;
	int power;
	int attackCap;
	int joinTime,ta, td, df, dd, db, attackpower;
	int number_of_attacked;
	int initialHealth;
	int attacks;
	int tUML;
	game* g;
public:
	unit(game* master); 
	void disp();
	void set_batleTime(int a);
	void set_Noofattacked(int a);
	int get_Noofattacked();
	void setUMLtime(int tUML);
	int getUMLtime();
	void set_id(int a);
	void set_joinTime(int a);
	void set_health(int a);
	void set_power(int a);
	void set_attackCap(int a);
	void set_type(type s);
	int get_id();
	int get_joinTime();
	int get_health();
	int get_initial_health();
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
	type get_type();
	virtual void attack() = 0;

};

