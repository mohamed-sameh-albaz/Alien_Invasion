#include <iostream>
#include "monster.h"
using namespace std;

#pragma once
class MonsterList
{
	int n;
	int index;
	monster** monsters = new monster*[n];
public:
	MonsterList(int num) 
	{
		n = num; index = 0;
		for (int i = 0; i < n; i++) monsters[i] = nullptr;
	}

	bool addMonster(monster* m) {
		if (index >= n) return false;
		else {
		monsters[index++] = m;
		return true;
		}
	}

	bool pickMonster(monster*& m) {
		if (index > 0) {

			srand(time(0));
			int randMonster = (rand() % (index));
			m = monsters[randMonster];
			monsters[randMonster] = monsters[index];
			monsters[index] == nullptr;
			index--;
			return true;
		}
		else return false;
	}

	void print() {
		for (int i = 0; i < index; i++) {
			if (monsters[i]) {
				monsters[i]->disp();
				cout << endl << "----------------------------" << endl;
			}
		}
	}
};

