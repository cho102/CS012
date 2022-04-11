#include "Character.h"
#include "Warrior.h"
#include "Elf.h"
#include "Wizard.h"
#include <iostream>
using namespace std;

Character::Character(HeroType t, const string & n, double h, double s)
{
    type = t;
    name = n;
    health = h;
    attackStrength = s;
}

HeroType Character::getType() const
{
    return type;
}

const string & Character::getName() const
{
    return name;
}

int Character::getHealth() const
{
    return static_cast<int>(health);
}

void Character::setHealth(double h)
{
    health = h;
}

void Character::damage(double d)
{
      health = health - d;
}

bool Character::isAlive() const
{
    if (health <= 0)
    {
        cout <<"I'm dead" <<endl;
        return false;
    }
    else
    {
        return true;
    }
}