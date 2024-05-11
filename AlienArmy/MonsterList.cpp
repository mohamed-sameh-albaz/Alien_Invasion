#include "MonsterList.h"


MonsterList::MonsterList() {
	n = 1000; index = -1;
	monsters = new monster * [n];
	for (int i = 0; i < n; i++) monsters[i] = nullptr;
}
MonsterList::~MonsterList() {
	for (int i = 0; i <= index; i++) {
		delete monsters[i];
		monsters[i] =nullptr;
	}
	delete[]monsters;
}

bool MonsterList::insert(monster* m) {
	if (index < n) {
		monsters[++index] = m;
		return true;
	}
	else return false;
}

bool MonsterList::MonsterList::remove(unit*& m){
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

void MonsterList::print() {  
	cout << getCount() + 1 << " AM ["; //index start from -1
	for (int i = 0; i < n; i++) {
		if (monsters[i]) {
			cout << monsters[i]->get_id();
			if (i != (index))  //index start from -1
			{
				cout << ", ";
			}
		}
	}
	cout << "]" << endl;
	cout << "_____________________________________________________\n";

}

int MonsterList::getCount() {
	return index+1;
}