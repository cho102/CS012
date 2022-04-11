#include <string>
#include <iostream>
#include "Elf.h"
#include "Character.h"

using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, string family) : Character(ELF, name, health, attackStrength) , family(family) { }

void Elf::attack(Character &c)
{
    double dmg;
    
    if (c.getType() == ELF)
    {
        Elf &opp = dynamic_cast<Elf &>(c);
        if (family == opp.family)
        {
            cout << "Elf " << getName() << " does not attack Elf " << c.getName() << "." << endl;
            cout << "They are both members of the " << family << " family." << endl;
        }
        else if (opp.isAlive())
        {
            dmg = (health/MAX_HEALTH) * attackStrength;
            opp.damage(dmg);
            cout << "Elf " << getName() << " shoots an arrow at " << c.getName() << " --- TWANG!!" << endl;
            cout << c.getName() << " takes " << dmg << " damage." << endl;
        }
    }
    else
    {
        if (c.isAlive())
        {
            dmg = (health/MAX_HEALTH) * attackStrength;
            c.damage(dmg);
            cout << "Elf " << getName() << " shoots an arrow at " << c.getName() << " --- TWANG!!" << endl;
            cout << c.getName() << " takes " << dmg << " damage." << endl;
        }
        
    }
}