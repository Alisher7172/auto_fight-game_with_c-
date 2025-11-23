#include "Character.h"
#include <algorithm> // for max
#include <iostream>

using namespace std;

// Defining the conditions
const int MIN_LIFE = 0;
const int MAX_LIFE = 10;
const int MIN_STRENGTH = 1;
const int MAX_STRENGTH = 10;
const int PATH_SIZE = 10;

// Character alive checker
bool Character::checkAlive() const {
    return life > MIN_LIFE;
}

// Constructor
Character::Character(string iName, int iLife, int iStrength, int sw_w, int sw_q, int sh_s, int sh_p)
    // member initialization GeekForGeeks.org
    : sw(sw_w, sw_q), sh(sh_s, sh_p)
{
	// initializing values
    name = iName;
    life = max(1, min(MAX_LIFE, iLife));
    strength = max(MIN_STRENGTH, min(MAX_STRENGTH, iStrength));
    isAlive = checkAlive();
    
    cout << "------------------------------------" << endl;
    cout << "Character Created: " << name << endl;
    cout << "  [Stats] Life: " << life << " Strength: " << strength << endl;
    cout << "------------------------------------" << endl;
}

// Destructor
Character::~Character() {
	cout << "=============================="<< endl;
    cout << "Game over for " << name <<endl;
    cout << "=============================="<< endl;
}

// gives damage and checks life status of character
bool Character::Hit(int damage) {
    if (!isAlive) {
        cout << "  [Hit] " << name << " is already dead." << endl;
        return false;
    }

    cout << "  [Hit] " << name << " takes " << damage << " damage" << endl;
    
    // Reduces life
    life = max(MIN_LIFE, life - damage);
    
    // Update status
    isAlive = checkAlive();

    if (!isAlive) {
        cout << "  [Status] " << name << "  is now DEAD." << endl;
    } else {
        cout << "  [Status] " << name << " remaining life: " << life << endl;
    }
    
    return isAlive;
}

// Calculates the attack
int Character::Attack() {
	// dead character can not attack
    if (!isAlive) {
        cout << "  [Attack] " << name << " is dead and cannot attack." << std::endl;
        return 0;
    }
    
	// According to formula provided    
    int totalAttack = strength + sw.Damage();
    cout << "  [Attack] " << name << "'s total Attack: " << totalAttack << endl;
    return totalAttack;
}

// Calculates the defence
int Character::Defence() {
	// dead chracter can not defend
    if (!isAlive) {
        cout << "  [Defence] " << name << " is dead and cannot defend." << endl;
        return 0;
    }
    
    // According to formula provided
    int totalDefence = (strength / 2) + sh.Block();
    cout << "  [Defence] " << name << "'s total Defence: " << totalDefence << endl;
    return totalDefence;
}

// Getter
int Character::GetLife() const {
    return life;
}

// Adds walking direction
void Character::Go(char direction) {
    if (!isAlive) {
        cout << "  [Go] " << name << " is dead and cannot move." << endl;
        return;
    }

    // Check for input data correctness
    if (direction != 'w' && direction != 'a' && direction != 's' && direction != 'd') {
        cout << "  [Go] Error: Invalid direction '" << direction << "'. Use 'w', 'a', 's', or 'd'." << endl;
        return;
    }
    
    for (int i = 0; i < PATH_SIZE - 1; ++i) {
        path[i] = path[i+1];
    }
    
    // Insert the new direction at the end (path[9])
    path[PATH_SIZE - 1] = direction;

    cout << "  [Go] " << name << " moved " << direction << endl;
}

// displays life, dead or alive, route info about sword and shield
void Character::Print() const {
    cout << "\n=========== Character Status ============" << endl;
    cout << "Name: " << name << endl;
    
    if (isAlive) {
        cout << "Status: ALIVE! Life Points: " << life << "/" << MAX_LIFE << endl;
    } else {
        cout << "Status: DEAD." << endl;
    }

    cout << "Strength: " << strength << "/" << MAX_STRENGTH << endl;

    // Display route
    cout << "Last 10 Movements Route: [";
    for (int i = 0; i < PATH_SIZE; ++i) {
        cout << path[i];
    }
    cout << "]" << endl;
}

// Repaires shield
void Character::RepairShield() {
    if (isAlive) {
        cout << "  [Repair] " << name << " Repairing shield." << endl;
        sh.Repair();
    } else {
        cout << "  [Repair] " << name << " is dead and can not repair shield." << endl;
    }
}
// Getter
const string& Character::GetName() const {
    return name;
}

