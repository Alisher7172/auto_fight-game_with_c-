#include <algorithm>  // for min/max src: cplusplus.com
#include "shield.h"
#include <iostream> 
using namespace std;

// Defining the limits
const int MIN_SIZE = 0;
const int MAX_SIZE = 4;
const int MIN_PROTECTION = 1;
const int MAX_PROTECTION = 5;

// Constructor
Shield::Shield(int iSize, int iProtection) {
    // size takes value after checking input size is in the range
    size = max(MIN_SIZE, min(MAX_SIZE, iSize));
    
    // checking same as size
    protection = max(MIN_PROTECTION, min(MAX_PROTECTION, iProtection));

    // Confirmation output
    cout << "  [Shield] Created: S=" << size << ", P=" << protection << endl;
}

// 
int Shield::Block() {
    int calculatedBlock = size * protection;
    // shoowing the result
    cout << "  [Shield] Block calculated: " << calculatedBlock << " (S:" << size << " * P:" << protection << ")" << endl;
    
    // After calculation we need to call destruction to make damage
    // Destruction(); 
    
    return calculatedBlock;
}

// gives the damage  to shield
void Shield::Destruction() {
	// reduces size by 1 , can not to be below 0
    size = max(MIN_SIZE, size - 1);
    cout << "  [Shield] Destruction: Size is now " << size << std::endl;
}

// increases size by 2 max: 4
void Shield::Repair() {
    // cannot increase size more than 4
    size = min(MAX_SIZE, size + 2);
    cout << "  [Shield] Repaired! Size is now " << size << endl;
}

// getter
int Shield::GetSize() const {
    return size;
}
// getter
int Shield::GetProtection() const {
    return protection;
}
