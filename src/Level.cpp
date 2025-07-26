#include "CheckList.h"
#include "Functionalities.h"

Patch::Patch()
{
    Treasure = false;
    FOV = false;
    Mined = false;
    Bomb = false;
    Left = nullptr;
    Right = nullptr;
    Up = nullptr;
    Down = nullptr;
}

Level::Level()
{
    // Row 1
    R1C1 = new Patch;
    R1C2 = new Patch;
    R1C3 = new Patch;
    R1C4 = new Patch;
    R1C5 = new Patch;

    // Row 2
    R2C1 = new Patch;
    R2C2 = new Patch;
    R2C3 = new Patch;
    R2C4 = new Patch;
    R2C5 = new Patch;

    // Row 3
    R3C1 = new Patch;
    R3C2 = new Patch;
    R3C3 = new Patch;
    R3C4 = new Patch;
    R3C5 = new Patch;

    // Row 4
    R4C1 = new Patch;
    R4C2 = new Patch;
    R4C3 = new Patch;
    R4C4 = new Patch;
    R4C5 = new Patch;

    // Row 5
    R5C1 = new Patch;
    R5C2 = new Patch;
    R5C3 = new Patch;
    R5C4 = new Patch;
    R5C5 = new Patch;

    Start = R3C3;
    Start->FOV = true;

    // Row 1 Column 1
    R1C1->Right = R1C2;
    R1C1->Down = R2C1;

    // Row 1 Column 2
    R1C2->Right = R1C3;
    R1C2->Down = R2C2;
    R1C2->Left = R1C1;

    // Row 1 Column 3
    R1C3->Right = R1C4;
    R1C3->Down = R2C3;
    R1C3->Left = R1C2;

    // Row 1 Column 4
    R1C4->Right = R1C5;
    R1C4->Down = R2C4;
    R1C4->Left = R1C3;

    // Row 1 Column 5
    R1C5->Down = R2C5;
    R1C5->Left = R1C4;

    // Row 2 Column 1
    R2C1->Up = R1C1;
    R2C1->Right = R2C2;
    R2C1->Down = R3C1;

    // Row 2 Column 2
    R2C2->Up = R1C2;
    R2C2->Right = R2C3;
    R2C2->Down = R3C2;
    R2C2->Left = R2C1;

    // Row 2 Column 3
    R2C3->Up = R1C3;
    R2C3->Right = R2C4;
    R2C3->Down = R3C3;
    R2C3->Left = R2C2;

    // Row 2 Column 4
    R2C4->Up = R1C4;
    R2C4->Right = R2C5;
    R2C4->Down = R3C4;
    R2C4->Left = R2C3;

    // Row 2 Column 5
    R2C5->Up = R1C5;
    R2C5->Down = R3C5;
    R2C5->Left = R2C4;

    // Row 3 Column 1
    R3C1->Up = R2C1;
    R3C1->Right = R3C2;
    R3C1->Down = R4C1;

    // Row 3 Column 2
    R3C2->Up = R2C2;
    R3C2->Right = R3C3;
    R3C2->Down = R4C2;
    R3C2->Left = R3C1;

    // Row 3 Column 3
    R3C3->Up = R2C3;
    R3C3->Right = R3C4;
    R3C3->Down = R4C3;
    R3C3->Left = R3C2;

    // Row 3 Column 4
    R3C4->Up = R2C4;
    R3C4->Right = R3C5;
    R3C4->Down = R4C4;
    R3C4->Left = R3C3;

    // Row 3 Column 5
    R3C5->Up = R2C5;
    R3C5->Down = R4C5;
    R3C5->Left = R3C4;

    // Row 4 Column 1
    R4C1->Up = R3C1;
    R4C1->Right = R4C2;
    R4C1->Down = R5C1;

    // Row 4 Column 2
    R4C2->Up = R3C2;
    R4C2->Right = R4C3;
    R4C2->Down = R5C2;
    R4C2->Left = R4C1;

    // Row 4 Column 3
    R4C3->Up = R3C3;
    R4C3->Right = R4C4;
    R4C3->Down = R5C3;
    R4C3->Left = R4C2;

    // Row 4 Column 4
    R4C4->Up = R3C4;
    R4C4->Right = R4C5;
    R4C4->Down = R5C4;
    R4C4->Left = R4C3;

    // Row 4 Column 5
    R4C5->Up = R3C5;
    R4C5->Down = R5C5;
    R4C5->Left = R4C4;

    // Row 5 Column 1
    R5C1->Up = R4C1;
    R5C1->Right = R5C2;

    // Row 5 Column 2
    R5C2->Up = R4C2;
    R5C2->Right = R5C3;
    R5C2->Left = R5C1;

    // Row 5 Column 3
    R5C3->Up = R4C3;
    R5C3->Right = R5C4;
    R5C3->Left = R5C2;

    // Row 5 Column 4
    R5C4->Up = R4C4;
    R5C4->Right = R5C5;
    R5C4->Left = R5C3;

    // Row 5 Column 5
    R5C5->Up = R4C5;
    R5C5->Left = R5C4;

}

//For Editing the Level
void Level::Edit(Level lvl, char mode)
{
    char Opt, Diff;

    if (mode == 'C')
    {
        EditMenu();
        cout << "\t\t\t\t\t\t";
        Opt = _getch();
        cout << endl << endl;

        if (Opt == '1')
        {
            DifficultyMenu();
            cout << "\t\t\t\t\t\t";
            Diff = _getch();
            cout << endl << endl;
        }
    }
    else
    {
        Opt = '1';
        if (mode == 'E')
        {
            Diff = '1';
        }
        else if (mode == 'M')
        {
            Diff = '2';
        }
        else if (mode == 'H')
        {
            Diff = '3';
        }
        else
        {
            Diff = mode;
        }
    }

    switch (Opt)
    {
    case '1': //Auto Generated Maps
    {
        Clear();
        srand(time(0));
        int row, col, count = 0, tempR = 0, tempC = 0;
        CheckList patchCheck;
        switch (Diff)
        {
        case '1': //Easy
            //Adding Bombs
            while (count < 3)
            {
                do
                {
                    row = 1 + (rand() % (5 - 1 + 1));
                    col = 1 + (rand() % (5 - 1 + 1));
                } while (patchCheck.Check(row, col));

                AddBomb(row, col);

                patchCheck.AddData(row, col);
                count++;
            }

            //Adding Treasure
            count = 0;
            while (count < 3)
            {
                do
                {
                    row = 1 + (rand() % (5 - 1 + 1));
                    col = 1 + (rand() % (5 - 1 + 1));
                } while (patchCheck.Check(row, col));

                AddTreasure(row, col);

                patchCheck.AddData(row, col);
                count++;
            }

            break;
        case '2': //Medium
            //Adding Bombs
            while (count < 5)
            {
                do
                {
                    row = 1 + (rand() % (5 - 1 + 1));
                    col = 1 + (rand() % (5 - 1 + 1));
                } while (patchCheck.Check(row, col));

                AddBomb(row, col);

                patchCheck.AddData(row, col);
                count++;
            }

            //Adding Treasure
            count = 0;
            while (count < 2)
            {
                do
                {
                    row = 1 + (rand() % (5 - 1 + 1));
                    col = 1 + (rand() % (5 - 1 + 1));
                } while (patchCheck.Check(row, col));

                AddTreasure(row, col);

                patchCheck.AddData(row, col);
                count++;
            }

            break;
        case '3': //Hard
            //Adding Bombs
            while (count < 10)
            {
                do
                {
                    row = 1 + (rand() % (5 - 1 + 1));
                    col = 1 + (rand() % (5 - 1 + 1));
                } while (patchCheck.Check(row, col));

                AddBomb(row, col);

                patchCheck.AddData(row, col);
                count++;
            }

            //Adding Treasure
            count = 0;
            while (count < 1)
            {
                do
                {
                    row = 1 + (rand() % (5 - 1 + 1));
                    col = 1 + (rand() % (5 - 1 + 1));
                } while (patchCheck.Check(row, col));

                AddTreasure(row, col);

                patchCheck.AddData(row, col);
                count++;
            }

            break;
        default:
            break;
        }
        break;
    }
    case '2': //Map Making
    {
        Player Creator;
        Creator.Move(lvl, Creator, mode);
        break;
    }

    case '3':
        cout << endl;
        cout << "\t\t\t\tExiting Edit Mode" << endl;
        cout << endl;
        break;
    default:
        break;
    }
}

//To Add a Bomb to a Patch
void Level::AddBomb(int row, int col)
{
    switch (row)
    {
    case 1:
        switch (col)
        {
        case 1:
            R1C1->Bomb = true;

            break;
        case 2:
            R1C2->Bomb = true;

            break;
        case 3:
            R1C3->Bomb = true;

            break;
        case 4:
            R1C4->Bomb = true;

            break;
        case 5:
            R1C5->Bomb = true;

            break;
        default:
            break;
        }

        break;
    case 2:
        switch (col)
        {
        case 1:
            R2C1->Bomb = true;

            break;
        case 2:
            R2C2->Bomb = true;

            break;
        case 3:
            R2C3->Bomb = true;

            break;
        case 4:
            R2C4->Bomb = true;

            break;
        case 5:
            R2C5->Bomb = true;

            break;
        default:
            break;
        }

        break;
    case 3:
        switch (col)
        {
        case 1:
            R3C1->Bomb = true;

            break;
        case 2:
            R3C2->Bomb = true;

            break;
        case 3:
            R3C3->Bomb = true;

            break;
        case 4:
            R3C4->Bomb = true;

            break;
        case 5:
            R3C5->Bomb = true;

            break;
        default:
            break;
        }

        break;
    case 4:
        switch (col)
        {
        case 1:
            R4C1->Bomb = true;

            break;
        case 2:
            R4C2->Bomb = true;

            break;
        case 3:
            R4C3->Bomb = true;

            break;
        case 4:
            R4C4->Bomb = true;

            break;
        case 5:
            R4C5->Bomb = true;

            break;
        default:
            break;
        }

        break;
    case 5:
        switch (col)
        {
        case 1:
            R5C1->Bomb = true;

            break;
        case 2:
            R5C2->Bomb = true;

            break;
        case 3:
            R5C3->Bomb = true;

            break;
        case 4:
            R5C4->Bomb = true;

            break;
        case 5:
            R5C5->Bomb = true;

            break;
        default:
            break;
        }

        break;
    default:
        break;
    }
}

//To Add a Treasure to a Patch
void Level::AddTreasure(int row, int col)
{
    switch (row)
    {
    case 1:
        switch (col)
        {
        case 1:
            R1C1->Treasure = true;

            break;
        case 2:
            R1C2->Treasure = true;

            break;
        case 3:
            R1C3->Treasure = true;

            break;
        case 4:
            R1C4->Treasure = true;

            break;
        case 5:
            R1C5->Treasure = true;

            break;
        default:
            break;
        }

        break;
    case 2:
        switch (col)
        {
        case 1:
            R2C1->Treasure = true;

            break;
        case 2:
            R2C2->Treasure = true;

            break;
        case 3:
            R2C3->Treasure = true;

            break;
        case 4:
            R2C4->Treasure = true;

            break;
        case 5:
            R2C5->Treasure = true;

            break;
        default:
            break;
        }

        break;
    case 3:
        switch (col)
        {
        case 1:
            R3C1->Treasure = true;

            break;
        case 2:
            R3C2->Treasure = true;

            break;
        case 3:
            R3C3->Treasure = true;

            break;
        case 4:
            R3C4->Treasure = true;

            break;
        case 5:
            R3C5->Treasure = true;

            break;
        default:
            break;
        }

        break;
    case 4:
        switch (col)
        {
        case 1:
            R4C1->Treasure = true;

            break;
        case 2:
            R4C2->Treasure = true;

            break;
        case 3:
            R4C3->Treasure = true;

            break;
        case 4:
            R4C4->Treasure = true;

            break;
        case 5:
            R4C5->Treasure = true;

            break;
        default:
            break;
        }

        break;
    case 5:
        switch (col)
        {
        case 1:
            R5C1->Treasure = true;

            break;
        case 2:
            R5C2->Treasure = true;

            break;
        case 3:
            R5C3->Treasure = true;

            break;
        case 4:
            R5C4->Treasure = true;

            break;
        case 5:
            R5C5->Treasure = true;

            break;
        default:
            break;
        }

        break;
    default:
        break;
    }
}

//Clears all Level
void Level::Clear()
{
    // Row 1 Column 1
    R1C1->Bomb = false;
    R1C1->Treasure = false;
    R1C1->FOV = false;
    R1C1->Mined = false;

    // Row 1 Column 2
    R1C2->Bomb = false;
    R1C2->Treasure = false;
    R1C2->FOV = false;
    R1C2->Mined = false;

    // Row 1 Column 3
    R1C3->Bomb = false;
    R1C3->Treasure = false;
    R1C3->FOV = false;
    R1C3->Mined = false;

    // Row 1 Column 4
    R1C4->Bomb = false;
    R1C4->Treasure = false;
    R1C4->FOV = false;
    R1C4->Mined = false;

    // Row 1 Column 5
    R1C5->Bomb = false;
    R1C5->Treasure = false;
    R1C5->FOV = false;
    R1C5->Mined = false;

    // Row 2 Column 1
    R2C1->Bomb = false;
    R2C1->Treasure = false;
    R2C1->FOV = false;
    R2C1->Mined = false;

    // Row 2 Column 2
    R2C2->Bomb = false;
    R2C2->Treasure = false;
    R2C2->FOV = false;
    R2C2->Mined = false;

    // Row 2 Column 3
    R2C3->Bomb = false;
    R2C3->Treasure = false;
    R2C3->FOV = false;
    R2C3->Mined = false;

    // Row 2 Column 4
    R2C4->Bomb = false;
    R2C4->Treasure = false;
    R2C4->FOV = false;
    R2C4->Mined = false;

    // Row 2 Column 5
    R2C5->Bomb = false;
    R2C5->Treasure = false;
    R2C5->FOV = false;
    R2C5->Mined = false;

    // Row 3 Column 1
    R3C1->Bomb = false;
    R3C1->Treasure = false;
    R3C1->FOV = false;
    R3C1->Mined = false;

    // Row 3 Column 2
    R3C2->Bomb = false;
    R3C2->Treasure = false;
    R3C2->FOV = false;
    R3C2->Mined = false;

    // Row 3 Column 3
    R3C3->Bomb = false;
    R3C3->Treasure = false;
    R3C3->FOV = true;
    R3C3->Mined = false;

    // Row 3 Column 4
    R3C4->Bomb = false;
    R3C4->Treasure = false;
    R3C4->FOV = false;
    R3C4->Mined = false;

    // Row 3 Column 5
    R3C5->Bomb = false;
    R3C5->Treasure = false;
    R3C5->FOV = false;
    R3C5->Mined = false;

    // Row 4 Column 1
    R4C1->Bomb = false;
    R4C1->Treasure = false;
    R4C1->FOV = false;
    R4C1->Mined = false;

    // Row 4 Column 2
    R4C2->Bomb = false;
    R4C2->Treasure = false;
    R4C2->FOV = false;
    R4C2->Mined = false;

    // Row 4 Column 3
    R4C3->Bomb = false;
    R4C3->Treasure = false;
    R4C3->FOV = false;
    R4C3->Mined = false;

    // Row 4 Column 4
    R4C4->Bomb = false;
    R4C4->Treasure = false;
    R4C4->FOV = false;
    R4C4->Mined = false;

    // Row 4 Column 5
    R4C5->Bomb = false;
    R4C5->Treasure = false;
    R4C5->FOV = false;
    R4C5->Mined = false;

    // Row 5 Column 1
    R5C1->Bomb = false;
    R5C1->Treasure = false;
    R5C1->FOV = false;
    R5C1->Mined = false;

    // Row 5 Column 2
    R5C2->Bomb = false;
    R5C2->Treasure = false;
    R5C2->FOV = false;
    R5C2->Mined = false;

    // Row 5 Column 3
    R5C3->Bomb = false;
    R5C3->Treasure = false;
    R5C3->FOV = false;
    R5C3->Mined = false;

    // Row 5 Column 4
    R5C4->Bomb = false;
    R5C4->Treasure = false;
    R5C4->FOV = false;
    R5C4->Mined = false;

    // Row 5 Column 5
    R5C5->Bomb = false;
    R5C5->Treasure = false;
    R5C5->FOV = false;
    R5C5->Mined = false;
}

//Reset the Level by Removing Mined Patch
void Level::Reset()
{
    // Row 1 Column 1
    R1C1->FOV = false;
    R1C1->Mined = false;

    // Row 1 Column 2
    R1C2->FOV = false;
    R1C2->Mined = false;

    // Row 1 Column 3
    R1C3->FOV = false;
    R1C3->Mined = false;

    // Row 1 Column 4
    R1C4->FOV = false;
    R1C4->Mined = false;

    // Row 1 Column 5
    R1C5->FOV = false;
    R1C5->Mined = false;

    // Row 2 Column 1
    R2C1->FOV = false;
    R2C1->Mined = false;

    // Row 2 Column 2
    R2C2->FOV = false;
    R2C2->Mined = false;

    // Row 2 Column 3
    R2C3->FOV = false;
    R2C3->Mined = false;

    // Row 2 Column 4
    R2C4->FOV = false;
    R2C4->Mined = false;

    // Row 2 Column 5
    R2C5->FOV = false;
    R2C5->Mined = false;

    // Row 3 Column 1
    R3C1->FOV = false;
    R3C1->Mined = false;

    // Row 3 Column 2
    R3C2->FOV = false;
    R3C2->Mined = false;

    // Row 3 Column 3
    R3C3->FOV = true;
    R3C3->Mined = false;

    // Row 3 Column 4
    R3C4->FOV = false;
    R3C4->Mined = false;

    // Row 3 Column 5
    R3C5->FOV = false;
    R3C5->Mined = false;

    // Row 4 Column 1
    R4C1->FOV = false;
    R4C1->Mined = false;

    // Row 4 Column 2
    R4C2->FOV = false;
    R4C2->Mined = false;

    // Row 4 Column 3
    R4C3->FOV = false;
    R4C3->Mined = false;

    // Row 4 Column 4
    R4C4->FOV = false;
    R4C4->Mined = false;

    // Row 4 Column 5
    R4C5->FOV = false;
    R4C5->Mined = false;

    // Row 5 Column 1
    R5C1->FOV = false;
    R5C1->Mined = false;

    // Row 5 Column 2
    R5C2->FOV = false;
    R5C2->Mined = false;

    // Row 5 Column 3
    R5C3->FOV = false;
    R5C3->Mined = false;

    // Row 5 Column 4
    R5C4->FOV = false;
    R5C4->Mined = false;

    // Row 5 Column 5
    R5C5->FOV = false;
    R5C5->Mined = false;
}