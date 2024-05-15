#include "Healer.h"
#include "../game.h"
#include "../tempList.h"

Healer::Healer(game* master) : unit(master)
{
	set_type(EH);
	initialHealth = joinTime = health = power = attackCap = id = 0;
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
					/*if (u->get_type() == ES)
						if ((dynamic_cast<EarthSoldier*>(u)->isInfected()))
							e->setInfectedCount(e->getInfectedCount() - 1);*/

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
							//e->setInfectedCount(e->getInfectedCount() - 1);
						}
					}
					else 
					{
						this->set_attackpower(u);
						u->set_health(u->get_health() + this->get_attackpower());//curStep-unlJOined>10=>killed
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
