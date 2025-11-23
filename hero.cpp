#include "hero.h"
#include <iostream>

using namespace std;

Hero::Hero(string iName, int iLife, int iStrength, int sw_w, int sw_q, int sh_s, int sh_p,
           int iExperience, int iLevel)
    : Character(iName, iLife, iStrength, sw_w, sw_q, sh_s, sh_p),
      experience(iExperience), level(iLevel)
{
    cout << "------------------------------------" << endl;
    cout << "Hero Created: " << GetName() << endl;
    cout << "  [Hero Stats] Experience: " << experience << " Level: " << level << endl;
    cout << "------------------------------------" << endl;
}

void Hero::Kill(Character &monster) {
    if (monster.GetLife() <= 0) {
        cout << "  [Kill] " << monster.GetName() << " is already dead." << endl;
        return;
    }

    int gained = monster.GetLife() * level;
    experience += gained;

    cout << "  [Kill] " << GetName() << " kills " << monster.GetName()
         << " and gains " << gained << " experience total: " << experience << endl;

    // Reduce monster life to 0 by calling Hit with current life
    monster.Hit(monster.GetLife());
}

void Hero::Print() const {
    // Print base character info
    Character::Print();
    cout << "--- info of Hero ---" << endl;
    cout << "Experience: " << experience << endl;
    cout << "Level: " << level << endl;
}
