#include"AlienSoldier.h"
#include"../Game/game.h"
AlienSoldier::AlienSoldier(game* master) : unit(master)
{
	set_type(AS);
}

void AlienSoldier::attack()
{
	
	EarthArmy * e  = g->getEarthArmy();
	unit* attackedUnit = nullptr;
	tempList tmp,tmp2;
	for (int i = 0; i < (attackCap); i++)
	{
		e->pickSoldier(attackedUnit);
		if (attackedUnit)
			tmp.insert(attackedUnit);
		else
			break;
		attackedUnit = nullptr;
	}
	if (g->get_mode() == 1)
		tmp.print(this);
	for (int i = 0; i < attackCap; i++) {
		if (!tmp.remove(attackedUnit)) break;
		else {
			if (attackedUnit->get_Noofattacked() == 0) {
				attackedUnit->set_atackedTime(g->getCurrTimeStep());
				attackedUnit->set_Noofattacked(1);
			}
			this->set_attackpower(attackedUnit);
			attackedUnit->set_health(attackedUnit->get_health() - this->get_attackpower());
			if (attackedUnit->get_health() <= 0)
			{
				//if (attackedUnit->get_type() == ES)
				if ((dynamic_cast<EarthSoldier*>(attackedUnit)->isInfected()))
					e->setInfectedCount(e->getInfectedCount() - 1);

				attackedUnit->set_distructionTime(g->getCurrTimeStep());
				g->insertKilled(attackedUnit);
			}
			else if ((attackedUnit->get_health() * 100 / attackedUnit->get_initial_health()) <= 20){

				g->insertUml(attackedUnit);
				attackedUnit->setUMLtime(g->getCurrTimeStep());
				if ((dynamic_cast<EarthSoldier*>(attackedUnit)->isInfected()))
					e->setInfectedCount(e->getInfectedCount() - 1);
			}
			else {

				tmp2.insert(attackedUnit);
			}
		}
		attackedUnit = nullptr;
	}

	while (tmp2.remove(attackedUnit)) {
		e->addUnit(attackedUnit);
	}
}
