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
	if (Heal.push(u))
	{
		count++;
		return true;
	}
	return false;
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
	ArrayStack<Healer*>tempList;
	Healer* temp;
	cout << getCount() << " EH [";
	while (!Heal.isEmpty())
	{
		Heal.pop(temp);
		cout << temp->get_id();
		tempList.push(temp);
		if (!Heal.isEmpty())
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;
	cout << "_____________________________________________________\n";

	while (!tempList.isEmpty())
	{
		tempList.pop(temp);
		Heal.push(temp);
	}
}