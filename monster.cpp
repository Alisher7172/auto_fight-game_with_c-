#include "monster.h"
#include <iostream>

using namespace std;

Monster::Monster(string iName, int iLife, int iStrength, int sw_w, int sw_q, int sh_s, int sh_p,
                 int iLevel)
    : Character(iName, iLife, iStrength, sw_w, sw_q, sh_s, sh_p), level(iLevel)
{
    cout << "------------------------------------" << endl;
    cout << "Monster Created: " << GetName() << endl;
    cout << "  [Monster Stats] Level: " << level << endl;
    cout << "------------------------------------" << endl;
}

int Monster::GetLevel() const {
    return level;
}

void Monster::Print() const {
    Character::Print();
    cout << "--- Monster Additional Info ---" << endl;
    cout << "Level: " << level << endl;
}
