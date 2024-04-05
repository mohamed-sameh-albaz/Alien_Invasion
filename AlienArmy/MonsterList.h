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
		for (int i = 0; i < n; i++) {
			monsters[i] = nullptr;
		}
	}

	bool addMonster(monster* m) {
		if (index >= n) return false;
		monsters[index++] = m;
	}

	monster* pickMonster() {
		srand(time(0));
		int randMonster = (rand() % (n));
		cout << randMonster;
		return monsters[randMonster];
	}
};

