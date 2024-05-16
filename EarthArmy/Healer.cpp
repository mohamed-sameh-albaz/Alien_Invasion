#include "Healer.h"
#include"../Game/game.h"

Healer::Healer(game* master) : unit(master)
{
	set_type(EH);
}

void Healer::attack()
{
	UML* uml = g->getUML();
	unit* u = nullptr;
	tempList tmp;
	EarthArmy* e = g->getEarthArmy();
	if (uml->get_curr_count() > 0) {

		for (int i = 0; i < attackCap; i++) {
			if (!uml->remove(u)) break;
			else {
				if (g->getCurrTimeStep() - u->getUMLtime() > 10)
				{
					u->set_distructionTime(g->getCurrTimeStep());
					g->insertKilled(u);
				}
				else
				{
					if(u->get_type() == ES)
					{
						if ((dynamic_cast<EarthSoldier*>(u))->isInfected())
						{
							dynamic_cast<EarthSoldier*>(u)->setCured(true);
							dynamic_cast<EarthSoldier*>(u)->setInfected(false);
						}
					}
					else 
					{
						this->set_attackpower(u);
						u->set_health(u->get_health() + this->get_attackpower());
						if ((u->get_health() * 100 / u->get_initial_health()) > 20)
						{
							g->getEarthArmy()->addUnit(u);
							uml->set_healed_count(uml->get_healed_count() + 1);
						}
						else
							tmp.insert(u);
					}
				}
			}
		}
		while (tmp.remove(u))
			g->insertUml(u);
		g->getEarthArmy()->pickHealer(u);
		suicide();
	}
}

void Healer::suicide()
{
	set_distructionTime(g->getCurrTimeStep());

	g->insertKilled(this);
}
