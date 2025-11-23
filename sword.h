#ifndef SWORD_H
#define SWORD_H   


class Sword {
private:
    int weight;  // (2-5)
    int quality; // (1-6)

public:
    // Constructor
    Sword(int iWeight, int iQuality);

    int Damage();      // Returns weight * quality
    void WearAndTear(); // Reduces quality by 1
    void Sharpen();     // Increases quality by 2 

    // Getters
    int GetWeight() const;
    int GetQuality() const;
};

#endif // SWORD_H

