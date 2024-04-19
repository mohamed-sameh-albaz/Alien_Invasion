#include "HL.h"
#include"Healer.h"

HL::HL() {
	count = 0;
}

HL::~HL()
{
	unit* A;
	while (remove(A)) {
		delete A;
		A = nullptr;
	}
}
bool HL::insert(Healer* u) {
	if (Heal.push(u)) {
		count++;
		return true;
	}
	else return false;
}

bool HL::remove(unit*& u) {
	Healer* h;
	if (Heal.pop(h)) {
		u = h;
		count--;
		return true;
	}
	else { 
		u = h;

		return false; }
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