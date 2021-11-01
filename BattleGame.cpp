#include <iostream>
#include <string>
#include "Character.h"
#include "weapon.h"
#include <Windows.h>
#include "functions.h"
#include <cstdlib>
#include <ctime>

using namespace std;

character chooseClass();
weapon chooseWeapon();
void startScreen();
void gameOver();

void press()
{
    cout << "\n\nPlease press enter to continue...\n";
    cin.ignore();
    cin.get();
    system("cls");
}

void enter()
{
    cin.ignore();
    cin.get();
    system("cls");
}

void Choise(character ourHero, character zerg, weapon ourWeapon, short int combat, int experience)
{
    int hit;
    int current_hp;
    int newCredits;

    cout << zerg.getClass() << " crosses your path\n";
    while (zerg.getHp() > 0)
    {
        cout << "What will you do?\n\n"
            << "[1] Attack\n\n"
            << "[2] Call for evacuation";
        cin >> combat;
        system("cls");
        switch (combat)
        {
        case 1:
        {
            if ((ourHero.getStr() + (rand() % 11)) > (zerg.getStr() + (rand() % 11)))
            {
                hit = ourHero.getStr() * (ourWeapon.getDamageMultiplier());
                cout << "You hit " << zerg.getClass() << " for " << hit << "\n\n";
                current_hp = zerg.getHp() - hit;
                zerg.setHp(current_hp);
                if (1 > zerg.getHp())
                {
                    cout << "You killed " << zerg.getClass() << " and recieved 40cr and 30exp!\n\n"
                        << "Please press enter...\n";
                    newCredits = ourHero.getCredits() + 40;
                    ourHero.setCredits(newCredits);
                    experience += 30;
                    zerg.setHp(0);
                }
            }
            else
            {
                cout << "You missed";
            }
            if (zerg.getHp() > 0)
            {
                if ((zerg.getStr() + (rand() % 11)) > (ourHero.getStr() + (rand() % 11)))
                {
                    hit = zerg.getStr() * 0.95;
                    hit = hit * ourHero.getArmor();
                    cout << zerg.getClass() << " hits you for " << hit << "\n\n";
                    current_hp = ourHero.getHp() - hit;
                    ourHero.setHp(current_hp);
                }
                else
                {
                    cout << "You have doged " << zerg.getClass();
                }
            }
            press();
        }
        case 2:
        {
            if ((rand() % 3) < 2)
            {
                cout << "Medivac arrived just at the right moment\n";
                press();
                zerg.setHp(0);
                break;
            }
            else
            {
                cout << "Evacuation arrived too late...\n\n";
                Sleep(3000);
                system("cls");
                ourHero.setHp(0);
                zerg.setHp(0);
                break;
            }
            break;
        }
        default:
        {
            cout << "Invalid selection\n\n";
            press();
        }

        if (ourHero.getHp() < 1)
        {
            cout << "YOU DIED";
            Sleep(1700);
            system("cls");
            break;
        }
        }
    }
}



int main()
{
    //startScreen();
    cout << "Enter name\n";
    string name;
    cin >> name;
    char yon;
    short int newCredits;
    short int newHealth;
    short int newStr;
    short int newDoge;
    short int experience = 0;
    system("cls");
    character ourHero = chooseClass();
    press();
    //weapon ourWeapon = chooseWeapon();
    weapon ourWeapon("name", 30);
    press();

    while (ourHero.getHp() > 0)
    {
        if (experience > 400 && ourHero.getLevel() < 2)
        {
            cout << "You have been promoted(2)!\n\n";
            ourHero.addLevel();
            press();
        }
        if (experience > 900 && ourHero.getLevel() < 3)
        {
            cout << "You have been promoted(3)!\n\n";
            ourHero.addLevel();
            press();
        }
        if (experience > 1500 && ourHero.getLevel() < 4)
        {
            cout << "You have been promoted(4)!\n\n";
            ourHero.addLevel();
            press();
        }
        if (experience > 2000 && ourHero.getLevel() < 5)
        {
            cout << "You have been promoted(5)!\n\n";
            ourHero.addLevel();
            press();
        }
        if (experience > 3000 && ourHero.getLevel() < 6)
        {
            cout << "You've reached max lvl!!!\n\n";
            ourHero.addLevel();
            press();
        }
        cout << "Choose our way:\n\n"
            << "[1] Engeneering bay\n\n"
            << "[2] Zerg locations\n\n"
            << "[3] Med-station\n\n"
            << "[4] Statistics\n\n"
            << "[5] Quit game\n";
        short int upgrade_lvl = 0;
        short int menuSelect;
        srand(time(0));
        cin >> menuSelect;
        system("cls");
        switch (menuSelect)
        {
            case 1:
            {
                system("cls");
                cout << "Welcome to armory!"
                    << "You have " << ourHero.getCredits() << " credits\n\n";
                cout << "What do you want? \n\n"
                    << "[1] Weapon upgrade 1 - 50\n\n"
                    << "[2] Weapon upgrade 2 - 100\n\n"
                    << "[3] Weapon upgrade 3 - 150\n\n"
                    << "[4] Exit";
                short int choice;
                cin >> choice;
                system("cls");
                switch (choice)
                {
                    case 1:
                    {
                        if (upgrade_lvl == 0)
                        {
                            if (ourHero.getCredits() > 49)
                            {
                                ourWeapon.WeaponUpgrade1();
                                newCredits = ourHero.getCredits() - 50;
                                ourHero.setCredits(newCredits);
                                cout << "Weapon upgrade complete!";
                                enter();
                                ++upgrade_lvl;
                                break;
                            }   
                            else
                            {
                                cout << "Not enough credits";
                                enter();
                                break;
                            }
                        }
                        else
                        {
                            cout << "You almost done level 1 upgrade!";
                            break;
                        }
                    }
                    case 2:
                    {
                        if (upgrade_lvl == 1)
                        {
                            if (ourHero.getCredits() > 99)
                            {
                                ourWeapon.WeaponUpgrade2();
                                newCredits = ourHero.getCredits() - 100;
                                ourHero.setCredits(newCredits);
                                cout << "Weapon upgrade complete!";
                                enter();
                                upgrade_lvl++;
                                break;
                            }
                            else
                            {
                                cout << "Not enough credits";
                                enter();
                                break;
                            }
                        }
                        else
                        {
                            cout << "You almost done level 2 upgrade!";
                            break;
                        }
                    }
                    case 3:
                    {
                        if (upgrade_lvl == 2)
                        {
                            if (ourHero.getCredits() > 149)
                            {
                                ourWeapon.WeaponUpgrade3();
                                newCredits = ourHero.getCredits() - 150;
                                ourHero.setCredits(newCredits);
                                cout << "Weapon upgrade complete!";
                                enter();
                                upgrade_lvl++;
                                break;
                            }
                            else
                            {
                                cout << "Not enough credits";
                                enter();
                                break;
                            }
                        }
                        else
                        {
                            cout << "You almost done level 3 upgrade!";
                            break;
                        }
                    }
                    case 4:
                    {
                        break;
                    }
                    default:
                    {
                        cout << "Invalid selection!\n\n";
                        press();
                    }
                }
                break;
            }
            case 2:
            {
                short int ArenaChoice;
                if (ourHero.getLevel() < 6)
                {
                    cout << "You have entered the zergs' locations\n"
                        << " Choose your way:\n\n"
                        << "[1] The Hatchery\n\n"
                        << "[2] The Lair\n\n"
                        << "[3] The Hive\n\n";
                    cin >> ArenaChoice;
                }
                if (ourHero.getLevel() == 6)
                {
                    cout << "You are starting to hear a voice in your head."
                        << "The Kerrigan is ready to accept your battle\n"
                        << "But are you, " << name << " ready for this ? ";
                    cin >> yon;
                }
                short int combat;
                short int hit;
                short int current_hp;
                system("cls");
                if (ourHero.getLevel() == 1)
                {
                    switch (ArenaChoice)
                    {
                        case 1:
                        {
                            character zerg("zergling", 40, 10, 14, 1, 0, 0);
                            cin >> combat;
                            Choise(ourHero, zerg, ourWeapon, combat, experience);
                        }
                        case 2:
                        {
                            character zerg("roach", 60, 20, 8, 3, 0, 0);
                            cin >> combat;
                            Choise(ourHero, zerg, ourWeapon, combat, experience);
                        }
                        case 3:
                        {
                            character zerg("Queen", 80, 40, 4, 5, 0, 0);
                            cin >> combat;
                            Choise(ourHero, zerg, ourWeapon, combat, experience);
                        }
                    }
                }
                if (ourHero.getLevel() == 2)
                {
                    switch (ArenaChoice)
                    {
                    case 1:
                    {
                        character zerg("Roach", 60, 20, 8, 3, 0, 0);
                        cin >> combat;
                        Choise(ourHero, zerg, ourWeapon, combat, experience);
                    }
                    case 2:
                    {
                        character zerg("Queen", 80, 40, 4, 5, 0, 0);
                        cin >> combat;
                        Choise(ourHero, zerg, ourWeapon, combat, experience);
                    }
                    case 3:
                    {
                        character zerg("Brutalisk", 100, 45, 5, 5, 0, 0);
                        cin >> combat;
                        Choise(ourHero, zerg, ourWeapon, combat, experience);
                    }
                    }
                }
                if (ourHero.getLevel() == 3)
                {
                    switch (ArenaChoice)
                    {
                        case 1:
                        {
                            character zerg("Queen", 80, 40, 4, 5, 0, 0);
                            cin >> combat;
                            Choise(ourHero, zerg, ourWeapon, combat, experience);
                        }
                        case 2:
                        {
                            character zerg("Brutalisk", 100, 45, 5, 5, 0, 0);
                            cin >> combat;
                            Choise(ourHero, zerg, ourWeapon, combat, experience);
                        }
                        case 3:
                        {
                            character zerg("Ultralisk", 130, 50, 1, 6, 0, 0);
                            cin >> combat;
                            Choise(ourHero, zerg, ourWeapon, combat, experience);
                        }
                    }
                }
            }
        }
    }
}

                           /*while (zerg.getHp() > 0)
                            {
                                cout << "What will you do?\n\n"
                                    << "[1] Attack\n\n"
                                    << "[2] Call for evacuation";
                                cin >> combat;
                                system("cls");
                                switch (combat)
                                {
                                    case 1:
                                    {
                                        if ((ourHero.getStr() + (rand() % 11)) > (zerg.getStr() + (rand() % 11)))
                                        {
                                            hit = ourHero.getStr() * (ourWeapon.getDamageMultiplier());
                                            cout << "You hit zergling for " << hit << "\n\n";
                                            current_hp = zerg.getHp() - hit;
                                            zerg.setHp(current_hp);
                                            if (1 > zerg.getHp())
                                            {
                                                cout << "You killed zergling and recieved 40cr and 30exp!\n\n"
                                                    << "Please press enter...\n";
                                                newCredits = ourHero.getCredits() + 40;
                                                ourHero.setCredits(newCredits);
                                                experience += 30;
                                                zerg.setHp(0);
                                            }
                                        }
                                        else
                                        {
                                            cout << "You missed";
                                        }
                                        if (zerg.getHp() > 0)
                                        {
                                            if ((zerg.getStr() + (rand() % 11)) > (ourHero.getStr() + (rand() % 11)))
                                            {
                                                hit = zerg.getStr() * 0.95;
                                                hit = hit * ourHero.getArmor();
                                                cout << " Zergling hits you for " << hit << "\n\n";
                                                current_hp = ourHero.getHp() - hit;
                                                ourHero.setHp(current_hp);
                                            }
                                            else
                                            {
                                                cout << "You have doged zergling";
                                            }
                                        }
                                        press();
                                    }
                                    case 2:
                                    {
                                        if ((rand() % 3) < 2)
                                        {
                                            cout << "Medivac arrived just at the right moment\n";
                                            press();
                                            zerg.setHp(0);
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Evacuation arrived too late...\n\n";
                                            Sleep(3000);
                                            system("cls");
                                            ourHero.setHp(0);
                                            zerg.setHp(0);
                                            break;
                                        }
                                        break;
                                    }
                                    default:
                                    {
                                        cout << "Invalid selection\n\n";
                                        press();
                                    }

                                    if (ourHero.getHp() < 1)
                                    {
                                        cout << "YOU DIED";
                                        Sleep(1700);
                                        system("cls");
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 2:
                        {
                            cout << "The Roach runs towards you!\n";
                            character roach("roach", 50, 15, 8, 2, 0, 0);
                            while (roach.getHp() > 0)
                            {
                                cout << "What will you do?";
                                cin >> combat;
                            }*/