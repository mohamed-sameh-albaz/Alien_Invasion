#include "HL.h"
HL::HL() {
	count = 0;

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
	ArrayStack<Healer*> tmp = Heal;
	while (!tmp.isEmpty()) {
		Healer* tmpUnit;
		tmp.pop(tmpUnit);
		tmpUnit->disp();
		cout << endl << "---------------------------" << endl;
	}
}