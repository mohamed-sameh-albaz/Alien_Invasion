#include "HL.h"
HL::HL() {
	count = 0;
}
HL::~HL()
{
}
bool HL::insert(Healer* u) {
	if (Heal.push(u)) {
		count++;
		return true;
	}
	else return false;
}

bool HL::remove(Healer*& u) {
	if (Heal.pop(u)) {

		count--;
		return true;
	}
	else return false;
}

int HL::getCount() {
	return count;
}


void HL::print() {
	ArrayStack<Healer*> tempList;
	Healer* tmpUnit;
	cout << " EH [";
	while (!tempList.isEmpty()) {
		tempList.pop(tmpUnit);
		cout<<tmpUnit->get_id();
		tempList.push(tmpUnit);
		if (!Heal.isEmpty())
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;
	while (!tempList.isEmpty())
	{
		tempList.pop(tmpUnit);
		Heal.push(tmpUnit);
	}
}