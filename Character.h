#ifndef CHARACTER_H
#define CHARACTER_H
class character
{
public:
    character(std::string z, int a, int b, int c, float i, int e, int f);
    void setClass(std::string x);
    void setHp(int h);
    void setStr(int s);
    void setDoge(int d);
    void setArmor(float arm);
    void setCredits(int g);
    void setLevel(int l);
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
