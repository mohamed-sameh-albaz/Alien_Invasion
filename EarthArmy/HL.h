#pragma once
#include "../DS/ArrayStack.h"
#include "Healer.h"
class HL
{
	ArrayStack<Healer*> Heal;
public:
	HL() {}
	bool add(Healer* u) {
		return (Heal.push(u));
	}

	 bool pick(Healer*& u) {
		return Heal.pop(u);
	}

	void print() {
		ArrayStack<Healer*> tmp = Heal;
		while (!tmp.isEmpty()) {
			Healer* tmpUnit;
			tmp.pop(tmpUnit);
			tmpUnit->disp();
			cout << endl << "---------------------------" << endl;
		}
	}
};

