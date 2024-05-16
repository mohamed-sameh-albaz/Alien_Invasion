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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);

		system("cls");
		cout << "please enter 1 if you want interactive mode and 2 if you want silent mode\n";
		cin >> mod;
	}
	while (mod != 1 && mod != 2);
	do
	{

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		system("cls");
		cout << "enter 1 if you want strong earth moderete aliens \n" <<
			"or 2 if you want strong earth strong aliens \n" <<
			"or 3 if you want strong earth  weak aliens \n" <<
			"or 4 if you want weak earth  moderete aliens\n" <<
			"or 5 if you want weak earth  strong aliens\n" <<
			"or 6 if you want weak earth  weak aliens\n";


		cin >> sel;
	} while (sel < 1 ||sel > 6);
	/*mod == 1 ? (GameMode = InterActive) : (GameMode = Silent);
	sel == 1 ? (s = strong_moderete) : 2 ? (s = strong_strong) : 3 ? (s = strong_weak) : 4 ? (s = weak_moderete) : 5 ? (s = weak_strong) :  (s = weak_weak);*/
	GameMode = (mod == 1) ? InterActive : Silent;
	s = (sel == 1) ? strong_moderete : (sel == 2) ? strong_strong : (sel == 3) ? strong_weak : (sel == 4) ? weak_moderete : (sel == 5) ? weak_strong
		: weak_weak;
	system("cls");
	if (GameMode == InterActive) {
		cout << "=================================== InterActive Mode =============================" << endl;
	}
	else {
		cout << "=================================== Silent Mode =============================" << endl;
	}
	cin.get();
	
	g->fight(GameMode,s);
	return 0;
}