#include "boss.h"
#include <iostream>

using namespace std;

Boss::Boss(string iName, int iLife, int iStrength, int sw_w, int sw_q, int sh_s, int sh_p,
           int iLevel, int iHeads)
    : Monster(iName, iLife, iStrength, sw_w, sw_q, sh_s, sh_p, iLevel), heads(iHeads)
{
    cout << "------------------------------------" << endl;
    cout << "Boss Created: " << GetName() << endl;
    cout << "  [Boss Stats] Heads: " << heads << " Level: " << GetLevel() << endl;
    cout << "------------------------------------" << endl;
}

int Boss::GetHeads() const {
    return heads;
}

void Boss::Eat(Hero &hero) {
    if (hero.GetLife() <= 0) {
        cout << "  [Eat] " << hero.GetName() << " is already dead." << endl;
        return;
    }

    int heroLife = hero.GetLife();

    // Increase boss life by hero life
    this->Hit(-heroLife);

    // Increase heads by 1
    heads += 1;

    // Reduce hero life to 0
    hero.Hit(heroLife);

    cout << "  [Eat] " << GetName() << " eats " << hero.GetName()
         << ", gains " << heroLife << " life and now has " << heads << " heads." << endl;
}

void Boss::Print() const {
    Monster::Print();
    cout << "--- Boss Additional Info ---" << endl;
    cout << "Heads: " << heads << endl;
}
