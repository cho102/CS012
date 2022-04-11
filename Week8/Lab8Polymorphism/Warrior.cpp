#include <string>
#include <iostream>
#include "Warrior.h"
#include "Character.h"

using namespace std;

Warrior::Warrior(const string &name, double health, double attackStrength, string allegiance): Character(WARRIOR, name, health, attackStrength),  allegiance(allegiance){ }



void Warrior::attack(Character &c)
{
    double dmg;
    
    if (c.getType() == WARRIOR)
    {
        Warrior &opp = dynamic_cast<Warrior &>(c);
        if (allegiance == opp.allegiance)
        {
            cout << "Warrior " << getName() << " does not attack Warrior " << c.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
        }
        else
        {
            if (c.isAlive())
            {
                dmg = (health/MAX_HEALTH) * attackStrength;
                c.damage(dmg);
                cout << "Warrior " << getName() << " attacks " << c.getName() << " --- SLASH!!" << endl;
                cout << c.getName() << " takes " << dmg << " damage." << endl;
            }
        }
    }
    else
    {
        if (c.isAlive())
        {
            dmg = (health/MAX_HEALTH) * attackStrength;
            c.damage(dmg);
            cout << "Warrior " << getName() << " attacks " << c.getName() << " --- SLASH!!" << endl;
            cout << c.getName() << " takes " << dmg << " damage." << endl;
        }
    }

}