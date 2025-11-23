#include "Character.h"
#include "hero.h"
#include "monster.h"
#include "boss.h"
#include <cstdlib> // for rand()
#include <ctime>   // for time()
#include <utility> // for swap()
#include <iostream>
#include <random>

using namespace std;

// Fight function
bool Fight(Character& ch1, Character& ch2) {
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "<<< F I G H T: " << ch1.GetName() << " vs " << ch2.GetName() << " >>>" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl; 
    
    // Check whether both characters are alive
    if (ch1.GetLife() <= 0 || ch2.GetLife() <= 0) {
        cout << "  [Fight] Cancelled: One of the characters is already dead." << endl;
        return false;
    }

    // Both are alive continue the attack sequence.
    bool wasAlive = true; 

    // Calculates the attack strength of ch1
    int attackForce = ch1.Attack();

    // Calculates the protective force of ch2
    int defenceForce = ch2.Defence();

    // The difference is the injury value 
    int injury = max(0, attackForce - defenceForce);
    cout << "  [Damage] Total Injury: " << injury << endl;

    // Invokes the injury function to ch2
    ch2.Hit(injury);

    return wasAlive;
}


void BrawlSimulation(Character& ch1, Character& ch2) {
    cout << "\n\n#####################################################" << endl;
    cout <<             "### G A M E  S T A R T S ###" << endl;
    cout << "#####################################################" << endl;

    int turn = 1;
    srand(time(0)); 

    Character* attacker = &ch1;
    Character* defender = &ch2;

    while (ch1.GetLife() > 0 && ch2.GetLife() > 0) {
        cout << "\n<<<<<<<<<<<<<<< Turn " << turn << " >>>>>>>>>>>>>>>" << endl;
        
        // Attacker attacks Defender
        Fight(*attacker, *defender);

        // Randomly attempt to repair shield 
        int action = rand() % 10; 

        if (action < 2) {
            cout << "  [Attacker] " << attacker->GetName() << " attempts a shield repair." << endl;
            attacker->RepairShield();
        }
        
        // Swap roles for the next turn
        swap(attacker, defender);
        turn++;
    }

    cout << "\n\n#####################################################" << endl;
    if (ch1.GetLife() > 0) {
        cout << "### " << ch1.GetName() << " is the WINNER! (Life: " << ch1.GetLife() << ") ###" << endl;
    } else {
        cout << "### " << ch2.GetName() << " is the WINNER! (Life: " << ch2.GetLife() << ") ###" << endl;
    }
    cout << "#####################################################" << endl;
}


int main() {
    cout << "******************************************************" << endl;
    // Character 1
    Character Arthur("Arthur", 10, 8,4, 5, 53, 4);
    
    // Character 2
    Character Lanselot("Lanselot", 6, 6, 62, 4, 1, 2);
    cout << "******************************************************" << endl;
    
    // sample moves
    cout << "\n------ Movement Testing -------" << endl;

    // Arthur
    Arthur.Go('w');
    Arthur.Go('a');
    Arthur.Go('w');
    Arthur.Go('d');
    Arthur.Go('s');
    Arthur.Go('w');
    Arthur.Go('a');
    Arthur.Go('w');
    Arthur.Go('d');
    Arthur.Go('s');
    Arthur.Go('d');
    Arthur.Go('s');

    // Lanselot
    Lanselot.Go('w');
    Lanselot.Go('d'); 
    Lanselot.Go('d'); 
    Lanselot.Go('d');
    Lanselot.Go('s'); 
    Lanselot.Go('a'); 
    Lanselot.Go('w'); 
    Lanselot.Go('d'); 
    Lanselot.Go('a'); 
    Lanselot.Go('s'); 
    Lanselot.Go('w'); 
    Lanselot.Go('a'); 

    // Invalid movement
    Arthur.Go('x');

    // Trying to hit the one you killed 
    cout << "\n--- Testing function calls on a dead character ---" << endl;
    Lanselot.Hit(1);

    // Try go with dead char
    cout << "\nAttempting Go function on Lanselot" << endl;
    Lanselot.Go('w');

    // Print
    Arthur.Print();
    Lanselot.Print();
    BrawlSimulation(Arthur, Lanselot);
    
    // ------------------ Instances with Hero, Monster, Boss ------------------
    // Create one instance of each class
    Hero theHero("Robin good", 7, 7, 3, 4, 2, 3, 0, 1);
    Monster theMonster("IT", 6, 5, 2, 3, 1, 2, 2);
    Boss theBoss("Tanus", 10, 9, 4, 5, 3, 2, 3, 2);

    // Call Print for all objects
    theHero.Print();
    theMonster.Print();
    theBoss.Print();

    // Hero kills Monster
    cout << "\n-- Hero kills Monster --" << endl;
    theHero.Kill(theMonster);

    // Boss eats Hero
    cout << "\n-- Boss eats Hero --" << endl;
    theBoss.Eat(theHero);

    // Print results
    theHero.Print();
    theMonster.Print();
    theBoss.Print();

    // Create Character* array and insert 3 copies of each
    Character *characters[9];
    for (int i = 0; i < 3; ++i) characters[i] = new Hero(theHero);
    for (int i = 3; i < 6; ++i) characters[i] = new Monster(theMonster);
    for (int i = 6; i < 9; ++i) characters[i] = new Boss(theBoss);

    cout << "\n-- Print 9 characters in array --" << endl;
    for (int i = 0; i < 9; ++i) {
        cout << "Character [" << i << "]:" << endl;
        characters[i]->Print();
    }

    // random
    srand((unsigned)time(0));
    const char dirs[4] = {'w','a','s','d'};

    // Loop 5 iterations: add random move and hit with random damage [5..10]
    for (int iter = 1; iter <= 5; ++iter) {
        cout << "\n=== Iteration " << iter << " ===" << endl;
        for (int i = 0; i < 9; ++i) {
            char d = dirs[rand() % 4];
            characters[i]->Go(d);
            int dmg = 5 + (rand() % 6); // 5..10
            characters[i]->Hit(dmg);
        }

        cout << "\n-- After iteration " << iter << " prints --" << endl;
        for (int i = 0; i < 9; ++i) {
            cout << "Character [" << i << "]:" << endl;
            characters[i]->Print();
        }
    }

    // Clean up 
    for (int i = 0; i < 9; ++i) delete characters[i];

    return 0;
}

