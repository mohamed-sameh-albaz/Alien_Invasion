#include <iostream>
#include "monster.h"
using namespace std;

#pragma once
class MonsterList
{
	int n;
	int index;
	monster** monsters;
public:
	MonsterList(int num) 
	{
		n = num; index = -1;
		monsters = new monster * [n];
		for (int i = 0; i < n; i++) monsters[i] = nullptr;
	}

	bool addMonster(monster* m) {
		if (index < n) {
			monsters[++index] = m;
			return true;
		}
		else return false;
	}

	bool pickMonster(unit*& m) {
		if (index > 0) {

			srand(time(0));
			int randMonster = (rand() % (index + 1));
			m = monsters[randMonster];
			monsters[randMonster] = monsters[index];
			monsters[index] = nullptr;
			index--;
			return true;
		}
		else if (index == 0) {
			m = monsters[0];
			monsters[0] = nullptr;
			index = -1;
			return true;
		}
		else return false;
	}

	void print() {
		if (index == -1) {
			cout << "The List Is Empty" << endl;
			return;
		}
		for (int i = 0; i < n; i++) {
			if (monsters[i]) {
				monsters[i]->disp();
				cout << endl << "----------------------------" << endl;
			}
		}
	}
};

