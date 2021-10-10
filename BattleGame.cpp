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

int main()
{
    startScreen();
    cout << "Enter name\n";
    string name;
    cin >> name;
    char yon;
    int newCredits;
    int newHealth;
    int newStr;
    int newDoge;
    int experience = 0;
    system("cls");
    character ourHero = chooseClass();
    press();
    weapon ourWeapon = chooseWeapon();
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
        int menuSelect;
        srand(time(0));
        cin >> menuSelect;
        system("cls");
        switch (menuSelect)
        {
        case 1:                //weapon/armor upgrades
        {
            if (ourHero.getCredits() > 49)
            {
                ourWeapon.WeaponUpgrade1();
                newCredits = ourHero.getCredits() - 50;
                ourHero.setCredits(newCredits);
                cout << "Upgrade complete!";
                press();
                break;
            }
            else
            {
                cout << "Not enough credits!";
                press();
                break;
            }
        }
        default:
        {
            cout << "Invalid selection.\n\n";
            press();
        }

        }
        break;
    }
    case 2:  //zergs
    {
        int arenaChoice;
        if (ourHero.getLevel() < 6)
        {
            cout << "You've entered the swarm territory:\n\n"
                << "[1] Hatchery\n\n"
                << "[2] Lair\n\n"
                << "[3] Hive\n\n";
            cin >> arenaChoice;
        }
        if (ourHero.getLevel() == 6)
        {
            cout << "After destroying most of zergs on the planet, you, " << name << " \nYou will lead the last battle\n"
                << "Are you ready? \n[Y]yes or [N]no?";
            cin >> yon;
        }
        //
        int combatChoice;
        int theHit;
        int currentHealth;
        system("cls");
        if (ourHero.getLevel() == 1)
            switch (arenaChoice)
            {
            case 1:
            {
                cout << "You've meet a zergling.\n";
                character zergling("zergling", 45, 10, 15, .30, 0, 0);
                while (zergling.getHp() > 0)
                {
                    cout << "What will you do?\n\n"
                        << "[1] Attack\n\n"
                        << "[2] try to evacuate";
                    cin >> combatChoice;
                    system("cls");
                    switch (combatChoice)
                    {
                    case 1:
                    {
                        if ((ourHero.getStr() + (rand() % 11)) > (zergling.getDoge() + (rand() % 11)))
                        {
                            theHit = ourHero.getStr() * (ourWeapon.getDamageMultiplier());
                            cout << "You shot zergling for " << theHit << "!\n";
                            currentHealth = zergling.getHp() - theHit;
                            zergling.setHp(currentHealth);
                            if (1 > zergling.getHp())
                            {
                                cout << "You killed zergling and recieved 30 gold and 30 exp!\n\n";
                                newCredits = ourHero.getCredits() + 30;
                                ourHero.setCredits(newCredits);
                                experience += 20;
                                zergling.setHp(0);
                            }
                        }
                        else
                        {
                            cout << "You missed!\n\n";
                        }
                        if (zergling.getHp() > 0)
                        {
                            if ((zergling.getStr() + (rand() % 11)) > (ourHero.getDoge() + (rand() % 11)))
                            {
                                theHit = zergling.getStr() * 0.95;
                                theHit = theHit * ourHero.getArmor();
                                cout << "Zergling attacked you and dealt " << theHit << "dmg!\n\n";
                                currentHealth = ourHero.getHp() - theHit;
                                ourHero.setHp(currentHealth);
                            }
                            else
                            {
                                cout << " You've dodged the zergling's attack!";
                            }
                        }
                        enter();
                        break;
                    }
                    case 2:
                    {
                        if ((rand() % 3) < 2)
                        {
                            cout << "The medivac ship picked you up at the last moment and saved your life!\n";
                            press();
                            zergling.setHp(0);
                            break;
                        }
                        else
                        {
                            cout << "Medivac arrived too late. This zergling kills you.";
                            Sleep(3000);
                            system("cls");
                            ourHero.setHp(0);
                            zergling.setHp(0);
                            break;
                        }
                        break;
                    }
                    default:
                        cout << "Invalid selection.\n\n";
                        press();
                    }
                }
                if (ourHero.getHp() < 1)
                {
                    cout << "You died!";
                    Sleep(1500);
                    system("cls");
                    break;
                }
            }
            case 2:
            {
                cout << "You've meet the Roach\n";
                character roach("roach", 45, 15, 10, 1, 0, 0);
                while (roach.getHp() > 0)
                {
                    cout << "What will you do?\n\n"
                        << "[1] Attack\n\n"
                        << "[2] try to evacuate\n";
                    cin >> combatChoice;
                    system("cls");
                    switch (combatChoice)
                    {
                    case 1:
                        if ((ourHero.getStr() + (rand() % 11)) > (roach.getDoge() + (rand() % 11)))
                        {
                            theHit = ourHero.getStr() * (ourWeapon.getDamageMultiplier());
                            cout << "You shot the roach for " << theHit << "!\n\n";
                            currentHealth = roach.getHp() - theHit;
                            roach.setHp(currentHealth);
                            if (1 > roach.getHp())
                            {
                                cout << "You killed this roach and gained 50 credits and 40 exp!\n";
                                newCredits = ourHero.getCredits() + 50;
                                ourHero.setCredits(newCredits);
                                experience += 40;
                                roach.setHp(0);
                            }
                        }
                        else
                        {
                            cout << " Roach has doged your shot";
                        }
                        if (roach.getHp() > 0)
                        {
                            if ((roach.getStr() + (rand() % 11)) > (ourHero.getDoge() + (rand() % 11)))
                            {
                                theHit = roach.getStr() * 1.5;
                                theHit = theHit * ourHero.getArmor();
                                cout << "Roach hits you for " << theHit << "!\n\n";
                                currentHealth = ourHero.getHp() - theHit;
                                ourHero.setHp(currentHealth);
                            }
                            else
                            {
                                cout << "You has dodged roach's attack";
                            }
                        }
                        enter();
                        break;
                    }
                    case 2:
                    {
                        if ((rand() % 3) < 2)
                        {
                            cout << "Medivac get your up and saves you!\n";
                            press();
                            roach.setHp(0);
                            break;
                        }
                        else
                        {
                            cout << "Poor decision. The roach executes you!";
                            Sleep(3000);
                            system("cls");
                            ourHero.setHp(0);
                            roach.setHp(0);
                            break;
                        }
                        break;
                    }

                    default:
                        break;
                    }
                }
            }
            }
    }
} 

