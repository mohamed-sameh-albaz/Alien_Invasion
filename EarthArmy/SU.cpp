#include "SU.h"
#include"../game.h"
#include"../tempList.h"
SU::SU(game* g) : unit(g)
{
	set_type(saver);
	initialHealth = joinTime = health = power = attackCap = id = 0;

}

void SU::attack()
{
	AlienArmy* attackedArmy = g->getAlienArmy();
	unit* attackedUnit = nullptr;
	tempList tmp;
	for (int i = 0; i < attackCap; i++)
	{
		attackedArmy->pickSoldier(attackedUnit);
		if (attackedUnit)
			tmp.insert(attackedUnit);
		else
			break;
		attackedUnit = nullptr;
	}
	//cout << id << " ES ";
	if (g->get_mode() == 1)
		tmp.print(get_type(), id);
	int attackedCnt = tmp.getCount();

	for (int i = 0; i < attackedCnt; i++)
	{
		tmp.remove(attackedUnit);
		if (attackedUnit->get_Noofattacked() == 0) {
			attackedUnit->set_atackedTime(g->getCurrTimeStep());
			attackedUnit->set_Noofattacked(1);
		}
		this->set_attackpower(attackedUnit);
		attackedUnit->set_health(attackedUnit->get_health() - this->get_attackpower());
		if (attackedUnit->get_health() <= 0)
		{
			g->insertKilled(attackedUnit);
			attackedUnit->set_distructionTime(g->getCurrTimeStep());
		}
		else
			tmp.insert(attackedUnit);
	}
	while (tmp.remove(attackedUnit))
		attackedArmy->addUnit(attackedUnit);
}
