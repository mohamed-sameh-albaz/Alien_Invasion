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
		if (Heal.push(u)) {
			count++;
			return true;
		}
		else return false;
	}

	 bool pick(Healer*& u) {
		 if (Heal.pop(u)) {

			 count--;
			 return true;
		 }
		 else return false;
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

