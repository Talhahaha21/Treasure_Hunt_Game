#include "Functionalities.h"

Player::Player()
{
	Lives = 3;
	Spades = 4;
	Rounds = 1;
	Scores = 0;
	Won = false;
	Lost = false;
	Walk = nullptr;
}

//Player Movement
void Player::Move(Level& lvl, Player& user, char mode)
{
	//Values reset for each Rounds
	Walk = lvl.Start;
	Walk->FOV = true;
	char move;
	Spades = 4;
	Won = false;
	Lost = false;
	bool delay = true;

	system("mode 650");
	while (!Lost && !Won)
	{
		Title();
		if (delay)
		{
			this_thread::sleep_for(chrono::milliseconds(1500));
			delay = false;
		}
		cout << endl;
		if (mode != 'C') //Creator Mode Check
		{
			PlayerStatus(user);
		}
		Map(lvl, mode);
		if (mode != 'C') //Creator Mode Check
		{
			PlayerScore(user);
		}

		move = _getch();
		move = toupper(move);
		cout << endl << endl;

		switch (move)
		{
		case 'W': //Move Up
			if (Walk->Up)
			{
				Walk->FOV = false;
				Walk = Walk->Up;
				Walk->FOV = true;
			}
			else
			{
				cout << endl;
				cout << "\t\t\t\t\t\tDead End" << endl;
				cout << endl;
				this_thread::sleep_for(chrono::seconds(1));
			}

			break;
		case 'D': //Move Right
			if (Walk->Right)
			{
				Walk->FOV = false;
				Walk = Walk->Right;
				Walk->FOV = true;
			}
			else
			{
				cout << endl;
				cout << "\t\t\t\t\t\tDead End" << endl;
				cout << endl;
				this_thread::sleep_for(chrono::seconds(1));
			}

			break;
		case 'S': //Move Down
			if (Walk->Down)
			{
				Walk->FOV = false;
				Walk = Walk->Down;
				Walk->FOV = true;
			}
			else
			{
				cout << endl;
				cout << "\t\t\t\t\t\tDead End" << endl;
				cout << endl;
				this_thread::sleep_for(chrono::seconds(1));
			}

			break;
		case 'A': //Move Left
			if (Walk->Left)
			{
				Walk->FOV = false;
				Walk = Walk->Left;
				Walk->FOV = true;
			}
			else
			{
				cout << endl;
				cout << "\t\t\t\t\t\tDead End" << endl;
				cout << endl;
				this_thread::sleep_for(chrono::seconds(1));
			}

			break;
		case 'M': //Mining
			if (mode != 'C') //Creator Mode Check
			{
				if (Walk->Mined)
				{
					cout << endl;
					cout << "\t\t\t\t\t\tYou Already Have Mined here" << endl;
					cout << endl;
					this_thread::sleep_for(chrono::seconds(1));
				}
				else
				{
					cout << endl;
					cout << "\t\t\t\t\t\t    Mining";
					this_thread::sleep_for(chrono::milliseconds(750));
					cout << ".";
					this_thread::sleep_for(chrono::milliseconds(750));
					cout << ".";
					this_thread::sleep_for(chrono::milliseconds(750));
					cout << "." << endl;

					//Found Bomb
					if (Walk->Bomb) 
					{
						Lives--;
						Spades--;
						Walk->Mined = true;
						cout << "\t\t\t\t\t\tKaaaBooooooooom" << endl;
						cout << endl;
						Walk->FOV = false;
						Walk = lvl.Start;
						this_thread::sleep_for(chrono::seconds(1));
						Walk->FOV = true;
						system("color C0");
						this_thread::sleep_for(chrono::milliseconds(50));
						system("color F7");
						this_thread::sleep_for(chrono::milliseconds(100));
					}

					//Found Treasure
					else if (Walk->Treasure)
					{
						cout << "";
						Walk->Mined = true;
						Won = true;
						Rounds++;
						Spades--;
						Scores += Spades * 50;
						Scores += 100;
						cout << "\t\t\t\t\t\tYou Found the Treasure" << endl;
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
						if (!Spades)
						{
							Spades++;
						}
					}

					//Found Noting
					else
					{
						Walk->Mined = true;
						Spades--;
						cout << "\t\t\t\t\t\tlooks Like There is Nothing Here" << endl;
						cout << endl;
						this_thread::sleep_for(chrono::seconds(1));
					}
				}
			}

			break;
		case 'T': //Placing Treasure
			if (mode == 'C') //Creator Mode Check
			{
				if (!Walk->Treasure && !Walk->Bomb)
				{
					Walk->Treasure = true;
					cout << endl;
					cout << "\t\t\t\t\t\tTreasure Placed" << endl;
					cout << endl;
					this_thread::sleep_for(chrono::seconds(1));
				}
				else
				{
					cout << endl;
					cout << "\t\t\t\t\t\tThere is Already Something Here" << endl;
					cout << endl;
					this_thread::sleep_for(chrono::seconds(1));
				}
			}

			break;
		case 'B': //Placing Bomb
			if (mode == 'C') //Creator Mode Check
			{
				if (!Walk->Bomb && !Walk->Treasure)
				{
					Walk->Bomb = true;
					cout << endl;
					cout << "\t\t\t\t\t\tBomb Placed" << endl;
					cout << endl;
					this_thread::sleep_for(chrono::seconds(1));
				}
				else
				{
					cout << endl;
					cout << "\t\t\t\t\t\tThere is Already Something Here" << endl;
					cout << endl;
					this_thread::sleep_for(chrono::seconds(1));
				}
			}

			break;
		case 'R': //Removing Treasure and Bomb
			if (mode == 'C') //Creator Mode Check
			{
				if (Walk->Bomb || Walk->Treasure)
				{
					Walk->Bomb = false;
					Walk->Treasure = false;
					cout << endl;
					cout << "\t\t\t\t\t\tCleared" << endl;
					cout << endl;
					this_thread::sleep_for(chrono::seconds(1));
				}
				else
				{
					cout << endl;
					cout << "\t\t\t\t\t\tNothing Is Here" << endl;
					cout << endl;
					this_thread::sleep_for(chrono::seconds(1));
				}
			}

			break;
		case 'E': //Exiting Game
			Walk->FOV = false;
			Walk = lvl.Start;

			Lost = true;
			cout << endl;
			cout << "\t\t\t\t\t\tExiting the Game" << endl;
			cout << endl;
			this_thread::sleep_for(chrono::seconds(1));

			break;
		case 27: //Exiting Game (Esc Key)
			Walk->FOV = false;
			Walk = lvl.Start;

			Lost = true;
			cout << endl;
			cout << "\t\t\t\t\t\tExiting the Game" << endl;
			cout << endl;
			this_thread::sleep_for(chrono::seconds(1));

			break;
		default:
			break;
		}

		//Reason of Lost
		if (!Lives || !Spades)
		{
			Lost = true;
			string text = !Lives ? "Game Over" : "Out Of Spades";
			cout << endl;
			cout << "\t\t\t\t\t\t" << text;
			cout << endl;
			system("color C0");
			this_thread::sleep_for(chrono::milliseconds(500));
		}
	}
	lvl.Reset();
}

//To Get Scores
int Player::GetScores()
{
	return Scores;
}

//Check If Player is Lost ot Not
bool Player::LostCheck()
{
	return Lost;
}
