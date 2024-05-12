#include"AlienSoldier.h"
#include "../game.h"
#include "../tempList.h"
AlienSoldier::AlienSoldier(game* master) : unit(master)
{
	set_type(AS);
	initialHealth = joinTime = health = power = attackCap = id = 0;
}

void AlienSoldier::attack()
{
	if (get_attacks() == 0)
	{
		set_attacks(1);
		set_joinTime(g->getCurrTimeStep());
	}
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
	tmp.print(get_type(), id);
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

				attackedUnit->set_distructionTime(g->getCurrTimeStep());
				g->insertKilled(attackedUnit);
			}
			else if ((attackedUnit->get_health() * 100 / attackedUnit->get_initial_health()) <= 20){

				g->insertUml(attackedUnit);
				attackedUnit->setUMLtime(g->getCurrTimeStep());
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
