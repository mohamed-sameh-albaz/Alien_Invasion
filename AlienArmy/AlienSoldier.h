#pragma once
#include"../unit.h"
#include"../DS/LinkedQueue.h"
class AlienSoldier : public unit
{
 public:
	 AlienSoldier() {
		 set_type("soldier");
		 initialHealth = joinTime = health = power = attackCap = id = 100;

	 }
void attack() {}
	
};

