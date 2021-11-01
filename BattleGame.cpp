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

int Choise(character ourHero, character zerg, weapon ourWeapon, int dmg = 0)
{
    short int combat;
    int hit;
    int current_hp;
    short int combat;

    cout << zerg.getClass() << " crosses your path\n";
    while (zerg.getHp() > 0)
    {
        cout << "What will you do?\n\n"
            << "[1] Attack\n\n"
            << "[2] Call for evacuation\n\n";
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
                    cout << "You killed " << zerg.getClass() << " and recieved " << zerg.getCredits() 
                        << " credits and " << zerg.getLevel() << " exp!\n\n";
                    zerg.setHp(0);
                    press();
                    break;
                }
            }
            else
            {
                cout << "You missed\n";
            }
            if (zerg.getHp() > 0)
            {
                if ((zerg.getStr() + (rand() % 11)) > (ourHero.getStr() + (rand() % 11)))
                {
                    hit = zerg.getStr() * 0.95;
                    hit = hit * ourHero.getArmor();
                    cout << zerg.getClass() << " hits you for " << hit << "\n\n";
                    current_hp = ourHero.getHp() - hit;
                    dmg += hit;
                    ourHero.setHp(current_hp);
                    break;
                }
                else
                {
                    cout << "You have doged " << zerg.getClass() << "\n";
                }
            }
            cin.ignore();
            cin.get();
            system("cls");
            break;
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
                ourHero.setHp(0);
                zerg.setHp(0);
                Sleep(3000);
                system("cls");
                break;
            }
            break;
        }
        default:
        {
            cout << "Invalid selection\n\n";
            press();
        }

        }
        if (ourHero.getHp() < 1)
        {
            cout << "\n\n\n\n\t\t\t\t\t\n\n\n\tYOU DIED";
            Sleep(1700);
            system("cls");
            break;
        }
    }
    return dmg;
}



int main()
{
    //Startscreen();
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
    weapon ourWeapon = chooseWeapon();
    press();

    while (ourHero.getHp() > 0)
    {
        if (experience > 100 && ourHero.getLevel() < 2)
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
        if (experience > 1600 && ourHero.getLevel() < 4)
        {
            cout << "You've reached max lvl!!!\n\n";
            ourHero.addLevel();
            press();
        }*/
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
                                upgrade_lvl = 1;
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
                                upgrade_lvl = 2;
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
                                upgrade_lvl = 3;
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
                if (ourHero.getLevel() < 4)
                {
                    cout << "You have entered the zergs' locations\n"
                        << " Choose your way:\n\n"
                        << "[1] The Hatchery\n\n"
                        << "[2] The Lair\n\n"
                        << "[3] The Hive\n\n"
                        << "[4] Exit";
                    cin >> ArenaChoice;
                }
                if (ourHero.getLevel() == 4)
                {
                    cout << "You are hearing a voice in your head."
                        << "The Kerrigan is ready to accept your battle\n"
                        << "But are you, " << name << " ready for this ? ";
                    cin >> yon;
                }
                short int combat;
                short int dmg = 0;
                int newCredits = 0;
                short int creds;
                short int current_hp;
                system("cls");
                if (ourHero.getLevel() == 1)
                {
                    switch (ArenaChoice)
                    {
                        case 1:
                        {
                            character zerg("zergling", 40, 10, 14, 1, 40, 50);
                            Choise(ourHero, zerg, ourWeapon, dmg);
                            creds = ourHero.getCredits() + zerg.getCredits();
                            ourHero.setCredits(creds);
                            experience += zerg.getLevel();
                            dmg = 0;
                            break;
                        }
                        case 2:
                        {
                            character zerg("roach", 60, 20, 8, 3, 50, 60);
                            Choise(ourHero, zerg, ourWeapon, dmg);
                            creds = ourHero.getCredits() + zerg.getCredits();
                            ourHero.setCredits(creds);
                            experience += zerg.getLevel();
                            dmg = 0;
                            break;
                        }
                        case 3:
                        {
                            character zerg("Queen", 80, 30, 1, 4, 60, 70);
                            Choise(ourHero, zerg, ourWeapon, dmg);
                            creds = ourHero.getCredits() + zerg.getCredits();
                            ourHero.setCredits(creds);
                            experience += zerg.getLevel();
                            dmg = 0;
                            break;
                        }
                        case 4:
                        {
                            break;
                        }
                    }
                }
                if (ourHero.getLevel() == 2)
                {
                    switch (ArenaChoice)
                    {
                        case 1:
                        {
                            character zerg("Roach", 60, 20, 8, 3, 50, 60);
                            Choise(ourHero, zerg, ourWeapon, dmg);
                            creds = ourHero.getCredits() + zerg.getCredits();
                            ourHero.setCredits(creds);
                            experience += zerg.getLevel();
                            dmg = 0;
                            break;
                        }
                        case 2:
                        {
                            character zerg("Queen", 80, 40, 4, 5, 60, 70);
                            Choise(ourHero, zerg, ourWeapon, dmg);
                            creds = ourHero.getCredits() + zerg.getCredits();
                            ourHero.setCredits(creds);
                            experience += zerg.getLevel();
                            dmg = 0;
                            break;
                        }
                        case 3:
                        {
                            character zerg("Brutalisk", 100, 45, 5, 5, 70, 80);
                            Choise(ourHero, zerg, ourWeapon, dmg);
                            creds = ourHero.getCredits() + zerg.getCredits();
                            ourHero.setCredits(creds);
                            experience += zerg.getLevel();
                            dmg = 0;
                            break;
                        }
                        case 4: 
                        {
                            break;
                        }
                    }
                }
                if (ourHero.getLevel() == 3)
                {
                    switch (ArenaChoice)
                    {
                        case 1:
                        {
                            character zerg("Queen", 80, 40, 4, 5, 60, 70);
                            Choise(ourHero, zerg, ourWeapon, dmg);
                            creds = ourHero.getCredits() + zerg.getCredits();
                            ourHero.setCredits(creds);
                            experience += zerg.getLevel();
                            dmg = 0;
                            break;
                        }
                        case 2:
                        {
                            character zerg("Brutalisk", 100, 45, 5, 5, 80, 90);
                            Choise(ourHero, zerg, ourWeapon, dmg);
                            creds = ourHero.getCredits() + zerg.getCredits();
                            ourHero.setCredits(creds);
                            experience += zerg.getLevel();
                            dmg = 0;
                            break;
                        }
                        case 3:
                        {
                            character zerg("Ultralisk", 130, 50, 1, 6, 90, 100);
                            Choise(ourHero, zerg, ourWeapon, dmg);
                            creds = ourHero.getCredits() + zerg.getCredits();
                            ourHero.setCredits(creds);
                            experience += zerg.getLevel();
                            dmg = 0;
                            break;
                        }
                        case 4:
                        {
                            break;
                        }
                    }
                }
                int hit;
                if (ourHero.getLevel() == 4)
                    switch (yon)
                    {
                        case 'y':
                        {
                            cout << "The Queen of Blades itself stands in front of you!";
                            character Kerrigan("Kerrigan", 800, 50, 30, 1, 0, 0);

                            while (Kerrigan.getHp() > 0)
                            {
                                cout << "What will you do?\n\n"
                                    << "[1] Attack"
                                    << "[2] Call for evacuation";
                                cin >> combat;
                                system("cls");
                                switch (combat)
                                {
                                case 1:
                                {
                                    if ((ourHero.getStr() + (rand() % 11)) > (Kerrigan.getStr() + (rand() % 11)))
                                    {
                                        hit = ourHero.getStr() * (ourWeapon.getDamageMultiplier());
                                        cout << "You hit Kerrigan for " << hit << "\n\n";
                                        current_hp = Kerrigan.getHp() - hit;
                                        Kerrigan.setHp(current_hp);
                                        if (1 > Kerrigan.getHp())
                                        {
                                            cout << "You have seriously injured The Queen of Blades\n\n";
                                            Sleep(3000);
                                            system("cls");
                                            cout << "The Emperror Mengsk proud of you!\n"
                                                << "You have succesfully complete this task and now you, "
                                                << name << " are the proud of Dominion";
                                            cout << "Please press enter...";
                                            cin.ignore();
                                            cin.get();
                                            ourHero.setHp(0);
                                        }
                                    }
                                    else
                                    {
                                        cout << "You missed\n\n";
                                    }
                                    if (Kerrigan.getHp() > 0)
                                    {
                                        if ((Kerrigan.getStr() + (rand() % 11)) > (ourHero.getStr() + (rand() % 11)))
                                        {
                                            hit = Kerrigan.getStr() * 3.3;
                                            hit = hit * ourHero.getArmor();
                                            cout << "Kerrigan deals you " << hit << " damage!\n\n";
                                            current_hp = ourHero.getHp() - hit;
                                            ourHero.setHp(current_hp);
                                        }
                                        else
                                        {
                                            cout << "Kerrigan missed";
                                        }
                                    }
                                    cin.ignore();
                                    cin.get();
                                    system("cls");
                                    break;
                                }
                                case 2:
                                {
                                    cout << "That was wrong decision...\n";
                                    Sleep(1500);
                                    cout << "Kerrigan desintagrates you!";
                                    Sleep(3000);
                                    system("cls");
                                    ourHero.setHp(0);
                                    Kerrigan.setHp(0);
                                    break;
                                }
                                default:
                                {
                                    cout << "Invalid selection\n\n";
                                    press();
                                }
                                }
                                if (ourHero.getHp() < 1)
                                {
                                    cout << "You died";
                                    Sleep(1700);
                                    system("cls");
                                    break;
                                }
                            }
                            break;
                        }
                        default:
                        {
                            system("cls");
                            break;
                        }
                    }
                break;
            }
            case 3:
            {
                system("cls");
                cout << "Welcome to the Med-station\n";
                cout << "You have" << ourHero.getCredits() << " credits!\n\n";
                cout << "What do you want?\n\n"
                    << "[1] Light heal - 25\n\n"
                    << "[2] Medium heal - 45\n\n"
                    << "[3] Big heal - 100\n\n"
                    << "[4] Stimpack - 65\n\n"
                    << "[5] Exit";
                int choice;
                cin >> choice;
                system("cls");
                int newhp;
                switch (choice)
                {
                    case 1:
                    {
                        if (ourHero.getCredits() > 24)
                        {
                            newhp = ourHero.getHp() + 20;
                            ourHero.setHp(newhp);
                            newCredits = ourHero.getCredits() - 25;
                            ourHero.setCredits(newCredits);
                            cout << "A little better";
                            enter();
                            break;
                        }
                        else
                        {
                            cout << "Not enough credits";
                            enter();
                            break;
                        }
                    }
                    case 2:
                    {
                        if (ourHero.getCredits() > 44)
                        {
                            newhp = ourHero.getHp() + 50;
                            ourHero.setHp(newhp);
                            newCredits = ourHero.getCredits() - 45;
                            ourHero.setCredits(newCredits);
                            cout << "You feel better";
                            enter();
                            break;
                        }
                        else
                        {
                            cout << "Not enough credits";
                            enter();
                            break;
                        }
                    }
                    case 3:
                    {
                        if (ourHero.getCredits() > 99)
                        {
                            newhp = ourHero.getHp() + 110;
                            ourHero.setHp(newhp);
                            newCredits = ourHero.getCredits() - 100;
                            ourHero.setCredits(newCredits);
                            cout << "Power Overwhelthing!";
                            enter();
                            break;
                        }
                        else
                        {
                            cout << "Not enough credits";
                            enter();
                            break;
                        }
                    }
                    case 4:
                    {
                        if (ourHero.getCredits() > 64)
                        {
                            newStr = ourHero.getStr() + 2;
                            ourHero.setStr(newStr);
                            newCredits = ourHero.getCredits() - 65;
                            ourHero.setCredits(newCredits);
                            newDoge = ourHero.getDoge() + 2;
                            ourHero.setDoge(newDoge);
                            cout << "Задавим врагов интеллектом!!!";
                            enter();
                        }
                        else
                        {
                            cout << "Not enough credits";
                            enter();
                            break;
                        }
                    }
                    case 5:
                    {
                        break;
                    }
                    default:
                    {
                        cout << "Invalid selection\n\n";
                        press();
                    }
                }
                break;
            }
            case 4:             //statistics
            {
                cout << "Your stats: \n"
                    << "Class: " << ourHero.getClass() << endl
                    << "Name: " << name << endl
                    << "Hp: " << ourHero.getHp() << endl
                    << "Strength: " << ourHero.getStr() << endl
                    << "Doge: " << ourHero.getDoge() << endl << endl
                    << "Weapon stats: \n"
                    << ourWeapon.getWeaponName() << endl
                    << "Damage: " << ourWeapon.getDamageMultiplier();
                press();
            }
            case 5: //Quit game
            {
                cout << "Are you sure?\n [y]es or [n]o";
                char yes;
                cin >> yes;
                if (yes == 'y' || yes == 'Y')
                    ourHero.setHp(0);
                system("cls");
                break;
            }
            default:
            {
                cout << "Invalid selection\n\n";
                enter();
            }
        }
    }
    if (ourHero.getHp() < 1)
    {
        gameOver();
        cout << "You finished with " << experience << " exp";
        press();
    }
    cout << "Play again? \n [y]es or [n]o";
    cin >> yon;
    switch (yon)
    {
        case 'y':
        {
            main();
            break;
        }
        case 'Y':
        {
            main();
            break;
        }
    default:
        break;
    }
    return 0;
}
