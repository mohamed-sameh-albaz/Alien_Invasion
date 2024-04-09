#pragma once
#include "../DS/ArrayStack.h"
#include "Healer.h"
class HL
{
	const int n;
	ArrayStack<unit*> Heal;
public:
	bool add(unit* u) {
		return (Heal.push(u));
	}

	unit* pick() {
		unit* tmp;
		Heal.pop(tmp);
		return tmp;
	}

	void print() {
		ArrayStack<unit*> tmp = Heal;
		while (!tmp.isEmpty()) {
			unit* tmpUnit;
			tmp.pop(tmpUnit);
			tmpUnit->disp();
		}
	}
};

