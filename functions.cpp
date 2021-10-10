#include <iostream>
#include <string>
#include "Character.h"
//#include "weapon.h"
#include <Windows.h>

using namespace std;

void StartScreen()
{
	cout << "***************************************************";
	cout << "\n\t\t\t Welcome to the Coprulu Sector \n";
	cout << "\t\t\t The Terran Dominion needs you! \n";
	cout << "***************************************************";
	Sleep(3600);
	system("cls");
	cout << "\t\t\t This Sector is full of danger coming from Zergs \n";
	cout << "\t\t\t You are the part of an Elite Dominion Forces\n";
	cout << "\t\t\t And You must bring the piece to our home! Good luck, Soldier!\n";
	Sleep(3600);
	system("cls");
}
void gameOver()
{
	cout << "\t\t\t Another brave soldier died in the Zerg swarm \n";
	cout << "\t\t\t GAME OVER!!! \n";
	Sleep(5000);
	system("cls");
}
character chooseClass()
{
	int classChoosen;
	cout << "You can be an: \n\n"
		<< "[1] Elite Marine(default armor, dmgand doge, trpl attack) \n\n"
		<< "[2] The Emperor's Shadow(-armor,+dmg,+doge,sngl attack)\n\n"
		<< "[3] Egida Marauder(+armor, +dmg, -doge, dbl attack)\n\n";
	cin >> classChoosen;
	system("cls");
	switch (classChoosen)
	{
	case 1:
		cout << "Elite Marine! Good choise.\n\n";
		return character("Elite Marine", 50, 15, 15, .65, 100, 1);
	case 2: 
		cout << "The Emperor's Shadow? I only can wish you good luck.\n\n";
		return character("Ghost", 35, 40, 50, .35, 150, 1);
	case 3:
		cout << "Egida Squad? Fine firepower, but will it be enough wihout accuarcy?";
		return character("Egida marauder", 75, 60, 3, .75, 150, 1);
	case 35:
		cout << "You called in the 'Pride of Augustgrad' battlecruiser! Your mission will be completed without any losses!";
		return character("Pride of Augustgrad", 10000, 300, 3, 1, 10000, 1);
	default:
		cout << "Invalid class selection.\n\n";
		cout << "press enter to continue\n";

		cin.ignore();
		cin.get();
		system("cls");
		return chooseClass();
	}
}
