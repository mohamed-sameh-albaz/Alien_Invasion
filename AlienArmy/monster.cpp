#include "monster.h"
#include"../Game/game.h"

monster::monster(game* master) : unit(master)
{
	set_type(AM);
}

void monster::attack()
{
	
	EarthArmy* e = g->getEarthArmy();
	tempList tmp, tmp2;
	unit* attackedUnit = nullptr;
	bool ESRemain = true;//army still have ES
	int attackedCnt = 0;
	for (int i = 0; i < ((attackCap / 2) + (attackCap % 2)); i++)
	{
		e->pickTank(attackedUnit);
		if (attackedUnit)
			tmp.insert(attackedUnit);
		else
			break;
		attackedUnit = nullptr;
	}

	attackedCnt = tmp.getCount();
	if(e->is_empty_saver())
	{
		for (int i = 0; i < attackCap - attackedCnt; i++)
		{
			e->pickSoldier(attackedUnit);
			if (attackedUnit)
			{
				tmp.insert(attackedUnit);
			}
			else
			{
				ESRemain = false;
				break;
			}
			attackedUnit = nullptr;
		}

		attackedCnt = tmp.getCount();
		if (!ESRemain && attackedCnt != attackCap) {
			for (int i = 0; i < attackCap - attackedCnt; i++)
			{
				e->pickTank(attackedUnit);
				if (attackedUnit)
					tmp.insert(attackedUnit);
				else
				{
					break;
				}
				attackedUnit = nullptr;
			}
		}
	}
	else {
		attackedCnt = tmp.getCount();

		for (int i = 0; i < (attackCap- attackedCnt)/2 ; i++)
		{
			e->pickSaver(attackedUnit);
			if (attackedUnit)
				tmp.insert(attackedUnit);
			else
			{
				break;
			}
			attackedUnit = nullptr;
		}
		attackedCnt = tmp.getCount();

		for (int i = 0; i < (attackCap - attackedCnt); i++)
		{
			e->pickSoldier(attackedUnit);
			if (attackedUnit)
			{
				tmp.insert(attackedUnit);
			}
			else
			{
				break;
			}
			attackedUnit = nullptr;
		}
		attackedCnt = tmp.getCount();
		if ( attackedCnt < attackCap) {
			for (int i = 0; i < attackCap - attackedCnt; i++)
			{
				e->pickSaver(attackedUnit);
				if (attackedUnit)
					tmp.insert(attackedUnit);
				else
				{
					break;
				}
				attackedUnit = nullptr;
			}
		}
		attackedCnt = tmp.getCount();
		if (tmp.getCount() < attackCap) {
			for (int i = 0; i < attackCap - attackedCnt; i++)
			{
				e->pickTank(attackedUnit);
				if (attackedUnit)
					tmp.insert(attackedUnit);
				else
				{
					break;
				}
				attackedUnit = nullptr;
			}
		}
	}
	attackedCnt = tmp.getCount();
	if (g->get_mode() == 1)
		tmp.print(this);


	for (int i = 0; i < attackedCnt; i++) {
		if (!tmp.remove(attackedUnit)) break;
		else {
			if (attackedUnit->get_Noofattacked() == 0) {
				attackedUnit->set_atackedTime(g->getCurrTimeStep());
			}
				attackedUnit->set_Noofattacked(1 + attackedUnit->get_Noofattacked());
			if (attackedUnit->get_type() == ES) {
				int A = (rand() % 100) + 1;
				int B = (rand() % 100) + 1;
				int randomSoldierNum = -1;
				if (e->get_soldierList()->getCount() > 0)
					randomSoldierNum = (rand() % e->get_soldierList()->getCount());

				if (!dynamic_cast<EarthSoldier*>(attackedUnit)->isInfected()) {
					infectSoldier(attackedUnit, A, B, randomSoldierNum);
					tmp2.enqueue(attackedUnit);
					attackedUnit = nullptr;
					continue;
				}
			}
			if(attackedUnit)
			{
				this->set_attackpower(attackedUnit);
				attackedUnit->set_health(attackedUnit->get_health() - this->get_attackpower());
				if (attackedUnit->get_health() <= 0)
				{
					if(attackedUnit->get_type()==ES)
						if ((dynamic_cast<EarthSoldier*>(attackedUnit)->isInfected()))
							e->setInfectedCount(e->getInfectedCount() - 1);

					attackedUnit->set_distructionTime(g->getCurrTimeStep());
					g->insertKilled(attackedUnit);
				}
				else if ((attackedUnit->get_health() * 100 / attackedUnit->get_initial_health()) <= 20) {

					g->insertUml(attackedUnit);
					attackedUnit->setUMLtime(g->getCurrTimeStep());
					if (attackedUnit->get_type() == ES)
						if ((dynamic_cast<EarthSoldier*>(attackedUnit)->isInfected()))
							e->setInfectedCount(e->getInfectedCount() - 1);
				}
				else {

					tmp2.insert(attackedUnit);
				}
			}
		}
		attackedUnit = nullptr;
	}

	while (tmp2.remove(attackedUnit)) {
		e->addUnit(attackedUnit);
	}
	
}

void monster::infectSoldier(unit*& s, int A, int B, int randomSoldierNum)
{
	EarthArmy* e = g->getEarthArmy();
	EarthSoldier* mySoldier = dynamic_cast<EarthSoldier*>(s);
	if (A <= g->getInfectionProb()) {
		if (!mySoldier->isCured()) {
			if (!mySoldier->isInfected()) {
				mySoldier->setInfected(true);
				e->setInfectedCount(e->getInfectedCount() + 1);
				if (B <= 2) {
					tempList t;

					int solCount = e->get_soldierList()->getCount();
					for (int i = 0; i < solCount; i++) {
						unit* tempSol = nullptr;
						e->pickSoldier(tempSol);
						t.enqueue(tempSol);
						if (i == randomSoldierNum) {
							EarthSoldier* randomSoldier = dynamic_cast<EarthSoldier*>(tempSol);
							if (!randomSoldier->isCured()) {
								if (!randomSoldier->isInfected()) {
									randomSoldier->setInfected(true);
									e->setInfectedCount(e->getInfectedCount() + 1);
								}
							}
						}
					}

					for (int i = 0; i < solCount; i++) {
						unit* tempSol = nullptr;
						t.dequeue(tempSol);
						e->addUnit(tempSol);
					}

				}
			}
		}
	}
}


