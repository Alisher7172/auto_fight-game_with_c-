#ifndef HERO_H
#define HERO_H

#include "Character.h"

// Hero class derived from Character
class Hero : public Character {
private:
    int experience;
    int level;
public:
// Constructor
    Hero(string iName, int iLife, int iStrength, int sw_w, int sw_q, int sh_s, int sh_p,
         int iExperience = 0, int iLevel = 1);

    // Method to kill a monster character,
    // and reduce the monster's life to 0.
    void Kill(Character &monster);

    // Redifined, addition to Character::Print()
    void Print() const;
};

#endif // HERO_H