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
		cout<< "enter :\n"
			<<"\t1 for strong earth moderate aliens \n" 
			<<"\t2 for strong earth strong aliens \n"
			<<"\t3 for strong earth  weak aliens \n"
			<<"\t4 for weak earth  moderate aliens\n" 
			<<"\t5 for weak earth  strong aliens\n" 
			<<"\t6 for weak earth  weak aliens\n";

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