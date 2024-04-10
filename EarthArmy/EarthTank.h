#pragma once
#include "../unit.h"
class EarthTank : public unit
{
public:
	EarthTank()
	{
		this->id = 0;
		this->joinTime = 0;
		this->health = 0;
		this->power = 0;
		this->attackCap = 0;

	}
	void setId(int id)
	{
		this->id = id;
	}
	int getId()const
	{
		return id;
	}
	void setJoinTime(int time)
	{
		this->joinTime = time;
	}
	int getJoinTime()const
	{
		return joinTime;
	}
	void setHealth(int health)
	{
		this->health = health;
	}
	int getHealth()const
	{
		return health;
	}
	void setPower(int power)
	{
		this->power = power;
	}
	int  getPower()const
	{
		return power;
	}
	void setCap(int cap)
	{
		this->attackCap = cap;
	}
	int getCap() const
	{
		return attackCap;
	}
	virtual void attack()// Attacking logic phase 2
	{

	}


};

