#include "unit.h"

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

		case ET:cout << "Tank";
			break;

		case AS:cout << "Alien Soldier";
			break;

		case AD:cout << "Alien Drone";
			break;

		case AM:cout << "Monster";
			break;

	}
	cout << "\n Power: " << power
		<< "\n Attack Capacity: " << attackCap
		<< "\n Join Time: " << joinTime << endl;
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
	tj = a;
}

void unit::set_distructionTime(int a)
{ 
	td = a;
	df = ta - tj;
	dd = td - ta;
	db = df + dd;

}

int unit::get_tj()
{
	return tj;
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
