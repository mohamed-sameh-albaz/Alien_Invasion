#include <iostream>
#include "game.h"
using namespace std;


int main() {
	game* g = new game;
	int mod;
	mode GameMode;
	do
	{
		system("cls");
		cout << "please enter 1 if you want interactive mode and 2 if you want silent mode\n";
		cin >> mod;
	}
	while (mod != 1 && mod != 2);

	mod == 1 ? (GameMode = InterActive) : (GameMode = Silent);
	system("cls");
	if (GameMode == InterActive) {
		cout << "=================================== InterActive Mode =============================" << endl;
	}
	else {
		cout << "=================================== Silent Mode =============================" << endl;
	}
	cin.get();
	g->fight(GameMode);
	return 0;
}