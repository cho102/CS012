#include <string>
#include <iostream>
#include "Wizard.h"
#include "Character.h"

using namespace std;

Wizard::Wizard (const string &name, double health, double attackStrength, int rank) : Character(WIZARD, name, health, attackStrength) , rank(rank) { }

void Wizard::attack(Character &c)
{
    double dmg = attackStrength;
    
    if (c.getType() == WIZARD)
    {
        Wizard &opp = dynamic_cast<Wizard &>(c);
        dmg = attackStrength * (rank / static_cast<double>(opp.rank));
        opp.damage(dmg);
    }
    else
    {
        c.damage(dmg);
    }
    
    cout << "Wizard " << getName() << " attacks " << c.getName() << " --- POOF!!" << endl;
    cout << c.getName() << " takes " << dmg << " damage." << endl;
}
