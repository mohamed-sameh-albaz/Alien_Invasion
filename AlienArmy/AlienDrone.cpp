#include "AlienDrone.h"
#include"../Game/game.h"
AlienDrone::AlienDrone(game* master) : unit(master)
{
	set_type(AD);
}

void AlienDrone::attack()
{
	EarthArmy* e = g->getEarthArmy();
	unit* attackedTank = nullptr;
	unit* attackedGunnery = nullptr;
	unit* attackedUnit= nullptr;
	bool EGRemain = true;//army still have EG
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
			break;
		}
		attackedTank = nullptr;
	}
	attackedCnt = attackedlist.getCount();
	for (int i = 0; i < attackCap - attackedCnt; i++)
	{
		e->pickGun(attackedGunnery);
		if (attackedGunnery)
			attackedlist.insert(attackedGunnery);
		else
		{
			EGRemain = false;
			break;
		}
		attackedGunnery = nullptr;
	}
	attackedCnt = attackedlist.getCount();
	if (!EGRemain && attackedCnt!=attackCap) {
		for (int i = 0 ; i < attackCap - attackedCnt ; i++) 
		{
			e->pickTank(attackedTank);
			if (attackedTank)
				attackedlist.insert(attackedTank);
			else
			{
				break;
			}
			attackedTank = nullptr;
		}
	}
	attackedCnt = attackedlist.getCount();

	if(g->get_mode()==1)
		attackedlist.print(this);

	for (int i = 0; i < attackCap; i++) {
		if (!attackedlist.remove(attackedUnit)) break;
		else
		 {
			if (attackedUnit->get_Noofattacked() == 0) {
				attackedUnit->set_atackedTime(g->getCurrTimeStep());
			}
				attackedUnit->set_Noofattacked(1+ attackedUnit->get_Noofattacked());
			this->set_attackpower(attackedUnit);
			attackedUnit->set_health(attackedUnit->get_health() - this->get_attackpower());
			if (attackedUnit->get_health() <= 0)
			{
				g->insertKilled(attackedUnit);
				attackedUnit->set_distructionTime(g->getCurrTimeStep());

			}
			else if ((attackedUnit->get_type() == ET) && ((attackedUnit->get_health() * 100 / attackedUnit->get_initial_health()) <= 20)) {
				
				g->insertUml(attackedUnit);
				attackedUnit->setUMLtime(g->getCurrTimeStep());
			}
			else 
				templist.insert(attackedUnit);

			attackedUnit = nullptr;
		 }
	}
	while (templist.remove(removedFromTmplst)) {
		e->addUnit(removedFromTmplst);
	}
	
}



