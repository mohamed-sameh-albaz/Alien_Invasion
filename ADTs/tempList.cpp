#include "tempList.h"

void tempList::print(unit *attacker)//attacking 2 units print
{
	Node<unit*>* nextUnit = frontPtr;
	type attackerType = attacker->get_type();
	tempList tmp; //for multiple attacking units-->to be done...
	switch (attackerType)
	{
	case EG:cout << " EG ";		break;
	case ES:cout << " ES ";		break;
	case ET:cout << " ET ";		break;
	case AS:cout << " AS ";		break;
	case AD:cout << " AD ";		break;
	case AM:cout << " AM ";		break;
	case saver:cout << " SU ";		break;

	}
	if (attackerType== ES)
		if (dynamic_cast<EarthSoldier*>(attacker)->isInfected())
			cout << "#";			//print infected ES when attack??
	cout << attacker->get_id()<< " shots [";
	while (nextUnit)
	{
		if(nextUnit->getItem()->get_type()==ES)
			if(dynamic_cast<EarthSoldier*>(nextUnit->getItem())->isInfected())
				cout<<"#";
		cout << nextUnit->getItem()->get_id();
		if (nextUnit->getNext())
			cout << ", ";
		nextUnit = nextUnit->getNext();
	}
	cout << "]" << endl;
}