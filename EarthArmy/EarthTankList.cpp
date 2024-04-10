#include "EarthTankList.h"

EarthTankList::EarthTankList()
{
}

void EarthTankList::addUnit(EarthTank* newTank)
{
	list.push(newTank);
	TankList.push(newTank);
}

void EarthTankList::removeUnit(EarthTank* deletedTank)
{
}

void EarthTankList::print() const
{
}
