#include <iostream>
#include "game.h"
using namespace std;


int main() {
	game* g = new game;
	int mode ;
	do
	{
		system("cls");
		cout << "please enter 1 if you want interactive mode and 2 if you want silent mode\n";
		cin >> mode;
	}
	while (mode != 1 && mode != 2);
	system("cls");
	if (mode == 1) {
		cout << "=================================== InterActive Mode =============================" << endl;
	}
	else {
		cout << "=================================== Silent Mode =============================" << endl;

	}
	g->fight(mode);
	return 0;
	// test branch
}