#include <iostream>
#include <Windows.h>
#include "game.h"

using namespace std;


int main() {
	game* g = new game;
	int mod;
	int sel;
	mode GameMode;
	selector s;
	do
	{
		system("cls");
		cout << "please enter 1 if you want interactive mode and 2 if you want silent mode\n";
		cin >> mod;
	}
	while (mod != 1 && mod != 2);
	do
	{
		system("cls");
		cout << "enter 1 if you want strong earth moderete aliens \n" <<
			"or 2 if you want strong earth strong aliens \n" <<
			"or 3 if you want strong earth  weak aliens \n" <<
			"or 4 if you want weak earth  moderete aliens\n" <<
			"or 5 if you want weak earth  strong aliens\n" <<
			"or 6 if you want weak earth  weak aliens\n";


		cin >> sel;
	} while (sel < 1 ||sel > 6);
	GameMode = (mod == 1) ? InterActive : Silent;
	switch (sel)
	{
	case 1: s= strong_moderete;
		break;
	case 2: s = strong_strong;
		break;
	case 3: s = strong_weak;
		break;
	case 4: s = weak_moderete;
		break;
	case 5: s = weak_strong;
		break;
	case 6: s = weak_weak;
		break;
	}
	system("cls");
	if (GameMode == InterActive) {
		cout << "=================================== InterActive Mode =============================" << endl;
	}
	else {
		cout << "=================================== Silent Mode ===================================" << endl;
	}
	cin.get();
	
	g->fight(GameMode,s);
	return 0;
}