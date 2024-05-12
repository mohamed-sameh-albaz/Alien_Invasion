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
	
	EarthArmy* e = g->getEarthArmy();
	unit* attackedTank = nullptr;
	unit* attackedgunnery = nullptr;
	unit* attackedunit= nullptr;

	unit* removedFromTmplst = nullptr;
	tempList attackedlist,templist;
	

	for (int i = 0; i < ((attackCap / 2) + (attackCap % 2)); i++)
	{
		e->pickTank(attackedTank);
		if (attackedTank)
			attackedlist.insert(attackedTank);
		else
			break;
		attackedTank = nullptr;
	}
	for (int i = 0; i < (attackCap / 2); i++)
	{
		e->pickGun(attackedgunnery);
		if (attackedgunnery)
			attackedlist.insert(attackedgunnery);
		else
			break;
		attackedgunnery = nullptr;
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



