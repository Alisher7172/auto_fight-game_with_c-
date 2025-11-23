#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"

class Monster : public Character {
private:
    int level;
public:
    // Constructor)
    Monster(string iName, int iLife, int iStrength, int sw_w, int sw_q, int sh_s, int sh_p,
            int iLevel = 1);
    int GetLevel() const;

    // Redefine Print() to show monster information
    void Print() const;
};

#endif // MONSTER_H
