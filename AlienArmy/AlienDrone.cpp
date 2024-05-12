#include "AlienDrone.h"
#include"../tempList.h"
#include"../EarthArmy/EarthArmy.h"
#include"../game.h"
AlienDrone::AlienDrone(game* master) : unit(master)
{
	set_type(AD);
	initialHealth = joinTime = health = power = attackCap = id = 0;
}

void AlienDrone::attack()
{
	/*if (get_attacks() == 0)
	{
		set_attacks(1);
		set_joinTime(g->getCurrTimeStep());
	}*/
	EarthArmy* e = g->getEarthArmy();
	unit* attackedTank = nullptr;
	unit* attackedgunnery = nullptr;
	unit* attackedunit= nullptr;
	bool EGremain = true;//army still have AS
	bool ETremain = true;//army still have AM
	int attackedCnt=0;
	unit* removedFromTmplst = nullptr;
	tempList attackedlist,templist;
	

	for (int i = 0; i < (attackCap / 2); i++)
	{
		e->pickTank(attackedTank);
		if (attackedTank)
			attackedlist.insert(attackedTank);
		else
		{
			ETremain = false;
			break;
		}
		attackedTank = nullptr;
	}
	attackedCnt = attackedlist.getCount();
	for (int i = 0; i < attackCap - attackedCnt; i++)
	{
		e->pickGun(attackedgunnery);
		if (attackedgunnery)
			attackedlist.insert(attackedgunnery);
		else
		{
			EGremain = false;
			break;
		}
		attackedgunnery = nullptr;
	}

	if (!EGremain && ETremain) {
		attackedCnt = attackedlist.getCount();
		attackedTank = nullptr;
		for (int i = 0 ; i < attackCap - attackedCnt ; i++) {
			e->pickTank(attackedTank);
			if (attackedTank)
				attackedlist.insert(attackedTank);
			else
			{
				ETremain = false;
				break;
			}
			attackedTank = nullptr;
			}
	}

	if(g->get_mode()==1)
		attackedlist.print(get_type(), id);

	for (int i = 0; i < attackCap ; i++) {
		if (!attackedlist.remove(attackedunit)) break;
		else {
			if (attackedunit->get_Noofattacked() == 0) {
				attackedunit->set_atackedTime(g->getCurrTimeStep());
				attackedunit->set_Noofattacked(1);
			}
			this->set_attackpower(attackedunit);
			attackedunit->set_health(attackedunit->get_health() - this->get_attackpower());
			if (attackedunit->get_health() <= 0)
			{
				attackedunit->set_distructionTime(g->getCurrTimeStep());
				g->insertKilled(attackedunit);

			}
			else if ((attackedunit->get_type() == ET) && ((attackedunit->get_health() * 100 / attackedunit->get_initial_health()) <= 20)) {
				
				g->insertUml(attackedunit);
				attackedunit->setUMLtime(g->getCurrTimeStep());
			}
			else {

				templist.insert(attackedunit);
			}
		}
	}
	
	

	while (templist.remove(removedFromTmplst)) {
		e->addUnit(removedFromTmplst);
	}
}



