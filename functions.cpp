#include <iostream>
#include <string>
#include "Character.h"
//#include "weapon.h"
#include <Windows.h>

using namespace std;

string StartScreen()
{
	cout << "***************************************************";
	cout << "\n\t\t\t Welcome to the Copulu Sector \n";
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
