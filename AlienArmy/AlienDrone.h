#pragma once
#include "../unit.h"
#include"../EarthArmy/EarthArmy.h"
class AlienDrone : public unit
{
public:
	AlienDrone(game* master); 
	void attack(); 

};

