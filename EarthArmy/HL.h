#pragma once
#include "../DS/ArrayStack.h"
#include "Healer.h"
class HL
{
	ArrayStack<Healer*> Heal;
	int count;
public:
	HL() { 
		count = 0;

	}
	bool add(Healer* u) {
		count++;
		return (Heal.push(u));
	}

	 bool pick(Healer*& u) {
		 count--;
		return Heal.pop(u);
	 }

	 int getcount() {
		 return count;
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

