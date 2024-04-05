#include "unit.h"
#include<iostream>
using namespace std;
void unit::disp()
{
	cout << " ID: " << id <<
		"\n Health: " << health <<
		"\n Type: " << type <<
		"\n Power: " << power<<
		"\n Atack Capacity: " <<attackCap <<
		"\n Join Time: " << joinTime;
}

void unit::set_id(int a)
{
	id = a;
}

void unit::set_joinTime(int a)
{
	joinTime = a;
}

void unit::set_health(int a)
{
	health = a;
}

void unit::set_power(int a)
{
	power = a;
}

void unit::set_attackCap(int a)
{
	attackCap = a;
}

void unit::set_type(string s)
{
	type = s;
}

int unit::get_id()
{
	return id;
}

int unit::get_joinTime()
{
	return joinTime;
}

int unit::get_health()
{
	return health;
}

int unit::get_power()
{
	return power;
}

int unit::get_attackCap()
{
	return attackCap;
}

string unit::get_type()
{
	return type;
}
