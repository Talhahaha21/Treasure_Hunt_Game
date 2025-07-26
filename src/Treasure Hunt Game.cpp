#include "Functionalities.h"

int main()
{
    AltEnter();
    int rounds = 0, Scores = 0;
    char Opt, Mode;
    string Name;
    bool Custom = false, Tester = false;
    Level Levels[4];
    ScoreInfo Board;

    do
    {
        Mode = Tester ? 'T' : 'S';

        system("mode 650");
        Title();
        this_thread::sleep_for(chrono::milliseconds(1500));
        MainMenu();
        cout << "\t\t\t\t\t\t";
        Opt = _getch();
        cout << endl;

        switch (Opt)
        {
        //Play Mode
        case '1':
            system("mode 650");
            Title();
            PlayMenu();
            cout << "\t\t\t\t\t\t";
            do
            {
                Player* P1 = new Player;
                Opt = _getch();
                cout << endl;

                switch (Opt)
                {
                //Normal Game
                case '1':
                    while (!P1->LostCheck() && rounds <= 5)
                    {
                        if (rounds <= 2)
                        {
                            Levels[0].Edit(Levels[0], 'E');
                            P1->Move(Levels[0], *P1, Mode);
                        }
                        else if (rounds <= 4)
                        {
                            Levels[1].Edit(Levels[1], 'M');
                            P1->Move(Levels[1], *P1, Mode);
                        }
                        else
                        {
                            Levels[2].Edit(Levels[2], 'H');
                            P1->Move(Levels[2], *P1, Mode);
                        }
                        rounds++;
                    }

                    if (!P1->LostCheck())
                    {
                        cout << endl;
                        cout << "\t\t\t\t\t\tYou Won" << endl;
                        cout << endl;
                        for (int loop = 0; loop < 5; loop++)
                        {
                            system("color A0");
                            this_thread::sleep_for(chrono::milliseconds(100));
                            system("color B0");
                            this_thread::sleep_for(chrono::milliseconds(100));
                            system("color C0");
                            this_thread::sleep_for(chrono::milliseconds(100));
                            system("color D0");
                            this_thread::sleep_for(chrono::milliseconds(100));
                            system("color E0");
                            this_thread::sleep_for(chrono::milliseconds(100));
                            system("color F0");
                            this_thread::sleep_for(chrono::milliseconds(100));
                        }
                        system("color 07");
                    }

                    Scores = P1->GetScores();

                    if (Scores && !Tester)
                    {
                        cout << "\t\t\t\t\tEnter 3 Letters for The Name : ";
                        int loop = 0;
                        while (Opt != 13)
                        {
                            Opt = _getch();
                            if (Opt == 27)
                            {
                                break;
                            }
                            Opt = toupper(Opt);
                            if (Opt == '\b')
                            {
                                !loop ? loop-- : loop -= 2;
                            }
                            if (loop < 3)
                            {
                                Name += Opt;
                                cout << Opt;
                                loop++;
                            }
                        }
                        cout << endl;
                        if (Opt == 27)
                        {
                            break;
                        }
                        Board.AddScore(Name, Scores); 
                        Opt = '1';
                    }
                    break;

                //Custom Game
                case '2':
                    if (Custom)
                    {
                        system("mode 650");
                        P1->Move(Levels[3], *P1, Mode);
                    }
                    else
                    {
                        cout << endl;
                        cout << "\t\t\t\t\tYou Haven't Made a Custom Map" << endl;
                        cout << endl;
                        this_thread::sleep_for(chrono::seconds(1));
                    }
                    break;

                //Exiting Play Mode
                case '3':
                    cout << endl;
                    cout << "\t\t\t\t\tGoing to Main Menu" << endl;
                    cout << endl;
                    this_thread::sleep_for(chrono::seconds(1));
                    break;
                case 27:
                    cout << endl;
                    cout << "\t\t\t\t\tGoing to Main Menu" << endl;
                    cout << endl;
                    this_thread::sleep_for(chrono::seconds(1));
                    break;
                default:
                    break;
                }
                delete P1;
            } while (Opt <= '1' && Opt >= '3' && Opt != 27);
            cout << endl;
            break;

        //Edit Mode
        case '2':
            system("mode 650");
            Levels[3].Edit(Levels[3], 'C');
            Custom = true;
            break;

        //ScoreBoard
        case '3':
            system("mode 650");
            Title();
            ScoreBoard(Board);
            cout << "\t\t\t\t\t\t\t";
            while (Opt != 'X' && Opt != 27)
            {
                Opt = _getch();
                Opt = toupper(Opt);
            }
            cout << endl;
            break;

        //Controls
        case '4':
            system("mode 650");
            Title();
            Controls();
            cout << "\t\t\t\t\t\t\t";
            while (Opt != 'X' && Opt != 27)
            {
                Opt = _getch();
                Opt = toupper(Opt);
            }
            cout << endl;
            break;

        //How To Play
        case '5':
            system("mode 650");
            Title();
            HowTo();
            cout << "\t\t\t\t\t\t\t";
            while (Opt != 'X' && Opt != 27)
            {
                Opt = _getch();
                Opt = toupper(Opt);
            }
            cout << endl;
            break;
        //Settings
        case '6':
            system("mode 650");
            Title();
            SettingMenu(Tester);
            cout << "\t\t\t\t\t\t";
            while (Opt != 'N' && Opt != 'Y' && Opt != 27)
            {
                Opt = _getch();
                Opt = toupper(Opt);
            }
            cout << endl;
            if (Opt == 'Y')
            {
                TesterMode(Tester);
                this_thread::sleep_for(chrono::seconds(1));
            }

            break;

        //Exiting The Game
        case '7':
            cout << endl;
            cout << "\t\t\t\t\t\tDo Come Back Again" << endl;
            cout << endl;
            break;
        case 27:
            cout << endl;
            cout << "\t\t\t\t\t\tDo Come Back Again" << endl;
            cout << endl;
            break;
        default:
            break;
        }
    } while (Opt != '7' && Opt!= 27);

    return 0;
}
