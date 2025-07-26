#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include <conio.h>
using namespace std;

class Patch
{
public:
    bool Treasure;
    bool FOV;
    bool Mined;
    bool Bomb;
    Patch* Left;
    Patch* Right;
    Patch* Up;
    Patch* Down;

    Patch();
};

class Level
{
private:
    Patch* Start;

    // Row 1
    Patch* R1C1;
    Patch* R1C2;
    Patch* R1C3;
    Patch* R1C4;
    Patch* R1C5;

    // Row 2
    Patch* R2C1;
    Patch* R2C2;
    Patch* R2C3;
    Patch* R2C4;
    Patch* R2C5;

    // Row 3
    Patch* R3C1;
    Patch* R3C2;
    Patch* R3C3;
    Patch* R3C4;
    Patch* R3C5;

    // Row 4
    Patch* R4C1;
    Patch* R4C2;
    Patch* R4C3;
    Patch* R4C4;
    Patch* R4C5;

    // Row 5
    Patch* R5C1;
    Patch* R5C2;
    Patch* R5C3;
    Patch* R5C4;
    Patch* R5C5;

public:
    Level();

    //For Editing the Level
    void Edit(Level lvl, char mode);

    //To Add a Bomb to a Patch
    void AddBomb(int row, int col);

    //To Add a Treasure to a Patch
    void AddTreasure(int row, int col);

    //Clears all Level
    void Clear();

    //Reset the Level by Removing Mined Patch
    void Reset();

    friend class Player;
    friend void Map(Level, char);
};

#endif  // !LEVEL_H