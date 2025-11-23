#include <algorithm> // for max/min  found in cplusplus.com
#include "sword.h"
#include <iostream>

using namespace std;

// Defining the limits
const int MIN_WEIGHT = 2;
const int MAX_WEIGHT = 5;
const int MIN_QUALITY = 1;
const int MAX_QUALITY = 6;

// Constructor
Sword::Sword(int iWeight, int iQuality) {
	// Weight takes value after checking input weight is in the range
    weight = max(MIN_WEIGHT, min(MAX_WEIGHT, iWeight)); 
    // Same goes for quality as weight
    quality = max(MIN_QUALITY, min(MAX_QUALITY, iQuality));

    // Confirmation output 
    cout << "  [Sword] Created: W=" << weight << ", Q=" << quality << endl;
}

// returns the amount after damage
int Sword::Damage() {
    int calculatedDamage = weight * quality;
    
    cout << "  [Sword] Damage calculated: " << calculatedDamage << " (W:" << weight << " * Q:" << quality << ")" << endl;
    
    //  we need to call WearAndTear() in order to apply damage after calculation
    WearAndTear(); 
    
    return calculatedDamage;
}

// reduces quality by 1 
void Sword::WearAndTear() {
    //can not reduce quality less than 1
    quality = max(MIN_QUALITY, quality - 1);
    cout << "  [Sword] WearAndTear: Quality is now " << quality <<endl;
}

// Increases the quility by 2
void Sword::Sharpen() {
    // Can not increase quality more than 6
    quality = min(MAX_QUALITY, quality + 2);
    cout << "  [Sword] Sharpened! Quality is now " << quality << endl;
}

// Returns weight 
int Sword::GetWeight() const {
    return weight;
}

// Returns quality
int Sword::GetQuality() const {
    return quality;
}



