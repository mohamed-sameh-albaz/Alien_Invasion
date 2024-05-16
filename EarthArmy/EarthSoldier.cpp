#include "EarthSoldier.h"
#include"../Game/game.h"
EarthSoldier::EarthSoldier(game* master) : unit(master)
{
	set_type(ES);
	Infected = false;
	cured = false;
}

void EarthSoldier::setInfected(bool b)
{
	Infected = b;
}

void EarthSoldier::setCured(bool b)
{
	cured = b;
}

bool EarthSoldier::isInfected()
{
	return Infected;
}

bool EarthSoldier::isCured()
{
	return cured;
}

void EarthSoldier::attack()
{
	
	AlienArmy* attackedArmy = g->getAlienArmy();
	EarthArmy* allies = g->getEarthArmy();
	unit* attackedUnit = nullptr;
	tempList tmp;
	if (this->isInfected())
	{
		for (int i = 0; i < attackCap; i++)
		{
			allies->pickSoldier(attackedUnit);
			if (attackedUnit)
				if (attackedUnit == this)
					i--;		//don't attack your-self
				else
					tmp.insert(attackedUnit);
			else
				break;
			attackedUnit = nullptr;
		}
		allies->addUnit(this);
	}
	else
	{
		for (int i = 0; i < attackCap; i++)
		{
			attackedArmy->pickSoldier(attackedUnit);
			if (attackedUnit)
				tmp.insert(attackedUnit);
			else
				break;
			attackedUnit = nullptr;
		}
	}
	if (g->get_mode() == 1)//change nums
		tmp.print(this);
	int attackedCnt = tmp.getCount();
	for (int i = 0; i < attackedCnt; i++)
	{
		tmp.remove(attackedUnit);
		if (attackedUnit->get_Noofattacked() == 0) 
		{
			attackedUnit->set_atackedTime(g->getCurrTimeStep());
		}
		attackedUnit->set_Noofattacked(1 + attackedUnit->get_Noofattacked());
		this->set_attackpower(attackedUnit);
		attackedUnit->set_health(attackedUnit->get_health() - this->get_attackpower());
		
		if (attackedUnit->get_health() <= 0)
		{
			g->insertKilled(attackedUnit);
			attackedUnit->set_distructionTime(g->getCurrTimeStep());
			if(Infected)
				if ((dynamic_cast<EarthSoldier*>(attackedUnit)->isInfected()))
					allies->setInfectedCount(allies->getInfectedCount() - 1);
		}
		else if(Infected and (attackedUnit->get_health() * 100 / attackedUnit->get_initial_health()) <= 20)
		{
			g->insertUml(attackedUnit);
			attackedUnit->setUMLtime(g->getCurrTimeStep());
			if ((dynamic_cast<EarthSoldier*>(attackedUnit)->isInfected()))
				allies->setInfectedCount(allies->getInfectedCount() - 1);
		}
		else
			tmp.insert(attackedUnit);
		
	}
	if (Infected)
		while (tmp.remove(attackedUnit))
			allies->addUnit(attackedUnit);
	else
		while (tmp.remove(attackedUnit))
			attackedArmy->addUnit(attackedUnit);
}
