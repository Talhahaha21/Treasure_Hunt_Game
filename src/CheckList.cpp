#include "CheckList.h"

Data::Data(int row, int col)
{
    Row = row;
    Col = col;
    next = nullptr;
}

CheckList::CheckList()
{
    Point = NULL;
    Run = NULL;
}

//Adds the Set of Row and Coloumn
void CheckList::AddData(int row, int col)
{
    Data* NewData = new Data(row, col);
    if (Point)
    {
        Run = Point;
        while (Run->next)
        {
            Run = Run->next;
        }
        Run->next = NewData;
    }
    else
    {
        Point = NewData;
    }
}

//Verify If Set of Row and Coloum Exists
bool CheckList::Check(int row, int col)
{
    if (Point)
    {
        Run = Point;
        while (Run)
        {
            if ((row == Run->Row) && (col == Run->Col))
            {
                return true;
            }
            Run = Run->next;
        }
        return false;
    }
    else
    {
        return false;
    }
}

//Empty the Qeueu
CheckList::~CheckList()
{
    while (Point)
    {
        Run = Point;
        Point = Point->next;
        delete Run;
    }
}