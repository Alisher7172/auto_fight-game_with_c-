#ifndef SHIELD_H
#define SHIELD_H

class Shield {
private:
    int size;        // (0-4)
    int protection; // (1-5)
    
public:
    // Constructor
    Shield(int iSize, int iProtection);

    int Block();           // Returns size * protection
    void Destruction();    // Reduces size by 1 not less than 0
    void Repair();         // Increases size by 2  max 4

    // Getters
    int GetSize() const;
    int GetProtection() const;
};

#endif // SHIELD_H

