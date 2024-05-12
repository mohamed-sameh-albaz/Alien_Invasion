#include "tempList.h"

bool tempList::firstPrinted = false;

void tempList::print(type attacker,int id )//attacking 2 units print
{
	Node<unit*>* nextUnit = frontPtr;
	switch (attacker)
	{
	case EG:cout << " EG ";
		break;
	case ES:cout << " ES ";
		break;

	case ET:cout << " ET ";
		break;

	case AS:cout << " AS ";
		break;

	case AD:cout << " AD ";
		break;

	case AM:cout << " AM ";
		break;
	}
	cout << id << " shots [";
	while (nextUnit)
	{
		cout << nextUnit->getItem()->get_id();
		if (nextUnit->getNext())
			cout << ", ";
		nextUnit = nextUnit->getNext();
	}
	cout << "]" << endl;
}