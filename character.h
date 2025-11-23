#ifndef CHARACTER_H
#define CHARACTER_H

#include "sword.h"
#include "shield.h"
#include <string> // library for strings
using namespace std;

class Character {
private:
    string name;
    int life;       // (1-10)
    int strength;   // (1-10)
    char path[10];  // Last 10 walking directions (w, a, s, d)
    Sword sw;
    Shield sh;
    
    // To check if the character is alive
    bool isAlive; 

    // To get life status
    bool checkAlive() const;

public:
    // Constructor
    Character(string iName, int iLife, int iStrength, int sw_w, int sw_q, int sh_s, int sh_p);

    bool Hit(int damage);           // Reduces life, returns if the character is alive
    int Attack();                   // Calculates and returns strength + sw.Damage()
    int Defence();                  // Calculates and returns strength/2 + sh.Block()
    int GetLife() const;            // returns the amount of the character's life
    void Go(char direction);        // Adds walking direction
    void Print() const;             // Displays stats 
    
    // Brawl simulation
    void RepairShield();            // Calls the internal sh.Repair() function.
    
    // Getters
    const string& GetName() const;

    // Destructor
    ~Character();
};

#endif // CHARACTER_H

