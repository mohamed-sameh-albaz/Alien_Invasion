#include "unit.h"

unit::unit(game* master)
{  g = master; tUML = 0; 
number_of_attacked = 0;
}

void unit::disp()
{
	cout << " ID: " << id
		<< "\n Health: " << health <<
		"\n Type: ";
	switch (unitType) 
	{
		case EG:cout << "Gunnery";
			break;
		case ES:cout << "Earth Soldier";
			break;

		case EH:cout << "Earth Healer";
			break;

		case ET:cout << "Tank";
			break;

		case AS:cout << "Alien Soldier";
			break;

		case AD:cout << "Alien Drone";
			break;

		case AM:cout << "Monster";
			break;
		case saver:cout << "Saver";
			break;

	}
	cout << "\n Power: " << power
		<< "\n Attack Capacity: " << attackCap
		<< "\n Join Time: " << joinTime << endl;
}

void unit::set_batleTime(int a)
{
	db = a - joinTime;
}



void unit::set_Noofattacked(int a)
{
	number_of_attacked = a;
}

int unit::get_Noofattacked()
{
	return number_of_attacked;
}

void unit::setUMLtime(int tUML)
{
	this->tUML = tUML;
}

int unit::getUMLtime()
{
	return tUML;
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
	if (initialHealth == 0) initialHealth = a;

}

void unit::set_power(int a)
{
	power = a;
}

void unit::set_attackCap(int a)
{
	attackCap = a;
}

void unit::set_type(type s)
{
	unitType = s;
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

int unit::get_initial_health()
{
	return initialHealth;
}

int unit::get_power()
{
	return power;
}

int unit::get_attackCap()
{
	return attackCap;
}

void unit::set_atackedTime(int a)
{
	ta = a;
}

void unit::set_distructionTime(int a)
{ 
	td = a;
	df = ta - joinTime;
	dd = td - ta;
	db = df + dd;

}

int unit::get_tj()
{
	return joinTime;
}

int unit::get_ta()
{
	return ta;
}

int unit::get_td()
{
	return td;
}

int unit::get_df()
{
	if (df < 0)
		return 0;
	return df;
}

int unit::get_dd()
{
	return dd;
}

int unit::get_db()
{
	return db;
}

void unit::set_attackpower(unit*u)
{
	attackpower = (power * health / 100) / sqrt(u->get_health());
}

int unit::get_attackpower()
{
	return attackpower;
}

type unit::get_type()
{
	return unitType;
}
