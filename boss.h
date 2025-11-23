#ifndef BOSS_H
#define BOSS_H

#include "monster.h"
#include "hero.h"

// Boss derives from Monster
class Boss : public Monster {
private:
    int heads;
public:
    // Constructor 
    Boss(string iName, int iLife, int iStrength, int sw_w, int sw_q, int sh_s, int sh_p,
         int iLevel = 1, int iHeads = 1);
    int GetHeads() const;
    // Eat a hero increases Boss life by Hero life, increases heads by 1, reduces Hero life to 0
    void Eat(Hero &hero);

    // Redefine Print to show boss information
    void Print() const;
};

#endif // BOSS_H
