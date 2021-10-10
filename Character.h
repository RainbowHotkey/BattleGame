#ifndef CHARACTER_H
#define CHARACTER_H
class character
{
public:
    character(std::string name, int hp, int att, int dogge, float armor, int cred, int level);
    void setClass(std::string x);
    void setHp(int hp);
    void setStr(int att);
    void setDoge(int dogge);
    void setArmor(float armor);
    void setCredits(int cred);
    void setLevel(int level);
    void addHealth();//прибавление
    void minHealth();//вычитание
    void addCredits();
    void minCredits();
    void addLevel();
    std::string getClass()
    {
        return pClass;
    }
    int getHp()
    {
        return health;
    }
    int getStr()
    {
        return str;
    }
    int getDoge()
    {
        return dex;
    }
    float getArmor()
    {
        return armor;
    }
    int getCredits()
    {
        return credits;
    }
    int getLevel()
    {
        return level;
    }
private:
    std::string pClass;
    int health;
    int str;
    int dex;
    float armor;
    int credits;
    int level;

};

character ourHero();

#endif // CHARACTER_H
