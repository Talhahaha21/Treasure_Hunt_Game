#include "Functionalities.h"
using namespace std;
HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE); //For Changing Colour

//Check Content of a Patch
char PatchCheck(Patch* zone, char mode)
{
    //Player Location
    if (zone->FOV)
    {
        SetConsoleTextAttribute(colour, 15);
        return 'O';
    }

    //Mined Locations
    else if (zone->Mined)
    {
        SetConsoleTextAttribute(colour, 4);
        return 'X';
    }

    //For Creator and Tester Mode
    else if (mode == 'C' || mode == 'T')
    {
        //Loaction of Bombs
        if (zone->Bomb)
        {
            SetConsoleTextAttribute(colour, 8);
            return 'B';
        }

        //location of Treasure
        if (zone->Treasure)
        {
            SetConsoleTextAttribute(colour, 6);
            return 'T';
        }
    }

    //Empty Space
    else
    {
        return ' ';
    }
}

//Prints Title
void Title()
{
    SetConsoleTextAttribute(colour, 1);
    cout << "\t\t\t\t\t\t                   ____" << endl;
    cout << "\t\t\t\t\t\t                  (_  _)" << endl;
    SetConsoleTextAttribute(colour, 14);
    cout << "\t\t\t\t\t\t        .  .    ";
    SetConsoleTextAttribute(colour, 1);
    cout << "   / /" << endl;
    SetConsoleTextAttribute(colour, 14);
    cout << "\t\t\t\t\t\t     .`";
    SetConsoleTextAttribute(colour, 4);
    cout << "_";
    SetConsoleTextAttribute(colour, 14);
    cout << ".";
    SetConsoleTextAttribute(colour, 4);
    cout << "_";
    SetConsoleTextAttribute(colour, 14);
    cout << "'";
    SetConsoleTextAttribute(colour, 4);
    cout << "_";
    SetConsoleTextAttribute(colour, 14);
    cout << "..  ";
    SetConsoleTextAttribute(colour, 1);
    cout << "  / /" << endl;
    SetConsoleTextAttribute(colour, 4);
    cout << "\t\t\t\t\t\t     \\   o   / ";
    SetConsoleTextAttribute(colour, 1);
    cout << "  / /" << endl;
    SetConsoleTextAttribute(colour, 4);
    cout << "\t\t\t\t\t\t      \\ /   / ";
    SetConsoleTextAttribute(colour, 1);
    cout << " _/ /_ " << endl;
    SetConsoleTextAttribute(colour, 14);
    cout << "\t\t\t\t\t\t`. ~. `";
    SetConsoleTextAttribute(colour, 4);
    cout << "\\___/";
    SetConsoleTextAttribute(colour, 14);
    cout << "'.";
    SetConsoleTextAttribute(colour, 1);
    cout << "/";
    SetConsoleTextAttribute(colour, 14);
    cout << "~.'";
    SetConsoleTextAttribute(colour, 1);
    cout << " /";
    SetConsoleTextAttribute(colour, 14);
    cout << ".~'`." << endl;
    cout << "\t\t\t\t\t\t.`'`.`.'`'`.~.`'~.`'`.~`" << endl;

    cout << "\t\t\t   _________                                                    " << endl;
    cout << "\t\t\t  |___   ___|                                                 " << endl;
    cout << "\t\t\t      | |  _ __ ___  __ _ ___ _   _ _ __ ___ _ __ ___   __ _ _ __  " << endl;
    cout << "\t\t\t      | | | '__/ _ \\/ _` / __| | | | '__/ _ \\ '_ ` _ \\ / _` | '_ \\ " << endl;
    cout << "\t\t\t      | | | | |  __/ (_| \\__ \\ |_| | | |  __/ | | | | | (_| | |_) |" << endl;
    cout << "\t\t\t      |_| |_|  \\___|\\__,_|___/\\__,_|_|  \\___|_| |_| |_|\\__,_| .__/" << endl;
    cout << "\t\t\t                                                            | |    " << endl;
    cout << "\t\t\t                                                            |_|    " << endl;
    SetConsoleTextAttribute(colour, 15);
}

//Prints Player States
void PlayerStatus(Player user)
{
    SetConsoleTextAttribute(colour, 14);
    cout << "\t\t\t\t     ______________________________________________" << endl;

    // Prints Number of Lives
    cout << "\t\t\t\t     | | Lives: ";
    SetConsoleTextAttribute(colour, 4);
    cout << user.Lives;

    //Prints Number of Rounds
    SetConsoleTextAttribute(colour, 14);
    cout << "       Round: ";
    SetConsoleTextAttribute(colour, 2);
    cout << user.Rounds;

    //Prints Number Of Spades
    SetConsoleTextAttribute(colour, 14);
    cout << "      Spades: ";
    SetConsoleTextAttribute(colour, 8);
    cout << user.Spades;
    SetConsoleTextAttribute(colour, 14);
    cout << " | |" << endl;
}

//Prints The Map
void Map(Level lvl, char mode)
{
    SetConsoleTextAttribute(colour, 14);
    cout << "\t\t\t\t   __| |________________________________________| |__" << endl;
    cout << "\t\t\t\t  (__   ________________________________________   __)" << endl;

    //Row 1
    cout << "\t\t\t\t     | |\t|\t|\t|\t|\t| |" << endl;
    cout << "\t\t\t\t     | |   ";
    cout << PatchCheck(lvl.R1C1, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R1C2, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R1C3, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R1C4, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R1C5, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t| |" << endl;
    cout << "\t\t\t\t     | |________|_______|_______|_______|_______| |" << endl;

    //Row 2
    cout << "\t\t\t\t     | |\t|\t|\t|\t|\t| |" << endl;
    cout << "\t\t\t\t     | |   ";
    cout << PatchCheck(lvl.R2C1, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R2C2, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R2C3, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R2C4, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R2C5, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t| |" << endl;
    cout << "\t\t\t\t     | |________|_______|_______|_______|_______| |" << endl;

    //Row 3
    cout << "\t\t\t\t     | |\t|\t|\t|\t|\t| |" << endl;
    cout << "\t\t\t\t     | |   ";
    cout << PatchCheck(lvl.R3C1, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R3C2, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R3C3, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R3C4, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R3C5, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t| |" << endl;
    cout << "\t\t\t\t     | |________|_______|_______|_______|_______| |" << endl;

    //Row 4
    cout << "\t\t\t\t     | |\t|\t|\t|\t|\t| |" << endl;
    cout << "\t\t\t\t     | |   ";
    cout << PatchCheck(lvl.R4C1, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R4C2, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R4C3, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R4C4, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R4C5, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t| |" << endl;
    cout << "\t\t\t\t     | |________|_______|_______|_______|_______| |" << endl;

    //Row 5
    cout << "\t\t\t\t     | |\t|\t|\t|\t|\t| |" << endl;
    cout << "\t\t\t\t     | |   ";
    cout << PatchCheck(lvl.R5C1, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R5C2, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R5C3, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R5C4, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t|   ";
    cout << PatchCheck(lvl.R5C5, mode);
    SetConsoleTextAttribute(colour, 14);
    cout << "\t| |" << endl;
    cout << "\t\t\t\t   __| |________|_______|_______|_______|_______| |__" << endl;
    cout << "\t\t\t\t  (__   ________________________________________   __)" << endl;
    cout << "\t\t\t\t     | |                                        | |" << endl;
    SetConsoleTextAttribute(colour, 15);
}

//Prints Player Scores
void PlayerScore(Player user)
{
    //Prints Total Scores
    SetConsoleTextAttribute(colour, 14);
    cout << "\t\t\t\t     | | Scores : ";
    SetConsoleTextAttribute(colour, 11);
    cout << user.Scores;
    SetConsoleTextAttribute(colour, 14);
    cout << "\t                        | |" << endl;
    SetConsoleTextAttribute(colour, 15);
}

//Displays Comtrol Menu
void Controls()
{
    SetConsoleTextAttribute(colour, 14);
    cout << "\t\t\t\t\t     __________________________" << endl;
    cout << "\t\t\t\t\t   / \\                       X \\." << endl;
    cout << "\t\t\t\t\t  |   |       Controls         |." << endl;
    cout << "\t\t\t\t\t   \\_ |                        |." << endl;
    cout << "\t\t\t\t\t      |        W = Up          |." << endl;
    cout << "\t\t\t\t\t      |        A = Left        |." << endl;
    cout << "\t\t\t\t\t      |        S = Down        |." << endl;
    cout << "\t\t\t\t\t      |        D = Right       |." << endl;
    cout << "\t\t\t\t\t      |                        |." << endl;
    cout << "\t\t\t\t\t      |        M = Mine        |." << endl;
    cout << "\t\t\t\t\t      |        E = Exit        |." << endl;
    cout << "\t\t\t\t\t      |                        |." << endl;
    cout << "\t\t\t\t\t      |      Creator Mode      |." << endl;
    cout << "\t\t\t\t\t      |                        |." << endl;
    cout << "\t\t\t\t\t      |        B = Bomb        |." << endl;
    cout << "\t\t\t\t\t      |        T = Treasure    |." << endl;
    cout << "\t\t\t\t\t      |        R = Remove      |." << endl;
    cout << "\t\t\t\t\t      |   _____________________|___" << endl;
    cout << "\t\t\t\t\t      |  /                        /." << endl;
    cout << "\t\t\t\t\t      \\_/________________________/." << endl;
    SetConsoleTextAttribute(colour, 15);
}

//How To Play Menu
void HowTo()
{
    SetConsoleTextAttribute(colour, 14);
    cout << "\t\t\t\t\t\t   _____________________________" << endl;
    cout << "\t\t\t\t\t\t / \\                          X \\." << endl;
    cout << "\t\t\t\t\t\t|   |        How To Play        |." << endl;
    cout << "\t\t\t\t\t\t \\_ |                           |." << endl;
    cout << "\t\t\t\t\t\t    |                           |." << endl;
    cout << "\t\t\t\t\t\t    |           DON'T           |." << endl;
    cout << "\t\t\t\t\t\t    |           FIND            |." << endl;
    cout << "\t\t\t\t\t\t    |           THE             |." << endl;
    cout << "\t\t\t\t\t\t    |           BOMB            |." << endl;
    cout << "\t\t\t\t\t\t    |                           |." << endl;
    cout << "\t\t\t\t\t\t    |   ________________________|___" << endl;
    cout << "\t\t\t\t\t\t    |  /                           /." << endl;
    cout << "\t\t\t\t\t\t    \\_/___________________________/." << endl;
    SetConsoleTextAttribute(colour, 15);
}

//Display MainMenu
void MainMenu()
{
    cout << "\t\t\t\t.-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-." << endl;
    cout << "\t\t\t\t|                                                 |" << endl;
    cout << "\t\t\t\t|                                                 |" << endl;
    cout << "\t\t\t\t|                      Welcome                    |" << endl;
    cout << "\t\t\t\t!                                                 !" << endl;
    cout << "\t\t\t\t:                     1. Play                     :" << endl;
    cout << "\t\t\t\t:                     2. Create                   :" << endl;
    cout << "\t\t\t\t.                     3. Scoreboard               ." << endl;
    cout << "\t\t\t\t:                     4. Controls                 :" << endl;
    cout << "\t\t\t\t:                     5. How To                   :" << endl;
    cout << "\t\t\t\t!                     6. Setting                  !" << endl;
    cout << "\t\t\t\t|                     7. Quit                     |" << endl;
    cout << "\t\t\t\t|                                                 |" << endl;
    cout << "\t\t\t\t|                                                 |" << endl;
    cout << "\t\t\t\t`-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'" << endl;
}

//Display Play Options
void PlayMenu()
{
    cout << "\t\t\t\t.-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-." << endl;
    cout << "\t\t\t\t|                                                 |" << endl;
    cout << "\t\t\t\t|                                                 |" << endl;
    cout << "\t\t\t\t|                     Play Menu                   |" << endl;
    cout << "\t\t\t\t!                                                 !" << endl;
    cout << "\t\t\t\t:                                                 :" << endl;
    cout << "\t\t\t\t:                     1. Normal                   :" << endl;
    cout << "\t\t\t\t.                     2. Custom                   ." << endl;
    cout << "\t\t\t\t:                     3. Exit                     :" << endl;
    cout << "\t\t\t\t:                                                 :" << endl;
    cout << "\t\t\t\t!                                                 !" << endl;
    cout << "\t\t\t\t|                                                 |" << endl;
    cout << "\t\t\t\t|                                                 |" << endl;
    cout << "\t\t\t\t|                                                 |" << endl;
    cout << "\t\t\t\t`-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'" << endl;
}

//Display Type of Edits
void EditMenu()
{
    cout << "\t\t\t\t\t    _____________________________" << endl;
    cout << "\t\t\t\t\t   |/                           \\|" << endl;
    cout << "\t\t\t\t\t   |          Edit Mode          |" << endl;
    cout << "\t\t\t\t\t   |_____________________________|" << endl;
    cout << "\t\t\t\t\t   |  _________________________  |" << endl;
    cout << "\t\t\t\t\t   | |                         | |" << endl;
    cout << "\t\t\t\t\t   | |     1. Random Inputs    | |" << endl;
    cout << "\t\t\t\t\t   | |     2. Manual Inputs    | |" << endl;
    cout << "\t\t\t\t\t   | |     3. Exit             | |" << endl;
    cout << "\t\t\t\t\t   | |_________________________| |" << endl;
    cout << "\t\t\t\t\t   |_____________________________|" << endl;
}

//Show Difficulty Options
void DifficultyMenu()
{
    cout << "\t\t\t\t\t    _____________________________" << endl;
    cout << "\t\t\t\t\t   |/                           \\|" << endl;
    cout << "\t\t\t\t\t   |          Difficulty         |" << endl;
    cout << "\t\t\t\t\t   |_____________________________|" << endl;
    cout << "\t\t\t\t\t   |  _________________________  |" << endl;
    cout << "\t\t\t\t\t   | |                         | |" << endl;
    cout << "\t\t\t\t\t   | |         1. Easy         | |" << endl;
    cout << "\t\t\t\t\t   | |         2. Medium       | |" << endl;
    cout << "\t\t\t\t\t   | |         3. Hard         | |" << endl;
    cout << "\t\t\t\t\t   | |_________________________| |" << endl;
    cout << "\t\t\t\t\t   |_____________________________|" << endl;
}

//Show Settings
void SettingMenu(bool flag)
{
    string toggle = flag ? "Active  " : "Deactive";
    string msg = flag ? "Deactive" : "Active  ";

    cout << "\t\t\t\t.-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-." << endl;
    cout << "\t\t\t\t|                                                 |" << endl;
    cout << "\t\t\t\t|                                                 |" << endl;
    cout << "\t\t\t\t|                      Settings                   |" << endl;
    cout << "\t\t\t\t!                                                 !" << endl;
    cout << "\t\t\t\t:                                                 :" << endl;
    cout << "\t\t\t\t:   Tester Mode                        ";
    cout << toggle;
    cout << "   :" << endl;
    cout << "\t\t\t\t.                                                 ." << endl;
    cout << "\t\t\t\t:                                                 :" << endl;
    cout << "\t\t\t\t:                   Do You Want To                :" << endl;
    cout << "\t\t\t\t!                       ";
    cout << msg;
    cout << "                  !" << endl;
    cout << "\t\t\t\t|                        Y/N                      |" << endl;
    cout << "\t\t\t\t|                                                 |" << endl;
    cout << "\t\t\t\t|                                                 |" << endl;
    cout << "\t\t\t\t`-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'" << endl;
}

//Display Scores
void ScoreBoard(ScoreInfo& list)
{
    SetConsoleTextAttribute(colour, 14);
    cout << "\t\t\t\t\t   _____________________________" << endl;
    cout << "\t\t\t\t\t / \\                          X \\." << endl;
    cout << "\t\t\t\t\t|   |         Scoreboard        |." << endl;
    cout << "\t\t\t\t\t \\_ |                           |." << endl;
    cout << "\t\t\t\t\t    |                           |." << endl;
    list.Display();
    cout << "\t\t\t\t\t    |                           |." << endl;
    cout << "\t\t\t\t\t    |   ________________________|___" << endl;
    cout << "\t\t\t\t\t    |  /                           /." << endl;
    cout << "\t\t\t\t\t    \\_/___________________________/." << endl;
}

//Switch Tester Mode
void TesterMode(bool& tester)
{
    //Admin Security
    string username = "Admin123", password = "Admin123";
    string usernameInput, passwordInput;
    char input = '1';

    //Will Deactive Tester Mode
    if (tester)
    {
        cout << endl;
        cout << "\t\t\t\t\t\tTester mode Deactive";
        cout << endl;
        tester = false;
    }

    //Will Active Tester Mode
    else
    {
        //Verify Admin/Tester Details
        while (username != usernameInput && password != passwordInput && input != 27)
        {
            //Taking Username
            input = '1';
            cout << "\t\t\t\t\t\tEnter Username : ";
            while (input != 13)
            {
                input = _getch();
                if (input == 13)
                {
                    
                }
                else if (input == '\b')
                {
                    usernameInput += input;
                    cout << "\b";
                }
                else
                {
                    usernameInput += input;
                    cout << input;
                }
            }
            cout << endl;

            //Taking Password
            input = '1';
            cout << "\t\t\t\t\t\tEnter Password : ";
            while (input != 13)
            {
                input = _getch();
                if (input == 13)
                {

                }
                else if (input == '\b')
                {
                    passwordInput += input;
                    cout << "\b";
                }
                else
                {
                    passwordInput += input;
                    cout << "*";
                }
            }
            cout << endl;

            //Message for Wrong Username or Passward
            if (username != usernameInput && password != passwordInput)
            {
                cout << endl;
                cout << "\t\t\t\t\t\tInvalid Username or Password";
                cout << endl;
            }
            //Access granted
            else
            {
                cout << endl;
                cout << "\t\t\t\t\t\tTester mode Active";
                cout << endl;
                tester = true;
            }
        }
        //Exiting (Esc Key)
        if (input == 27)
        {
            cout << endl;
            cout << "\t\t\t\t\t\tExiting...";
            cout << endl;
        }
    }
}

//To Make Console Full Screen by Auto Calling (ALT + Tab)
void AltEnter()
{
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
    return;
}