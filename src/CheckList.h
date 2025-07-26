#ifndef CHECKLIST_H
#define CHECKLIST_H
#include <iostream>
#include <conio.h>
using namespace std;

class Data
{
public:
    int Row, Col;
    Data* next;

    Data(int row, int col);
};

class CheckList
{
private:
    Data* Point;
    Data* Run;

public:
    CheckList();

    //Adds the Set of Row and Coloumn
    void AddData(int row, int col);

    //Verify If Set of Row and Coloum Exists
    bool Check(int row, int col);

    //Empty the Qeueu
    ~CheckList();

};

#endif  // !CHECKLIST_H

