#ifndef PLAYER_H
#define PLAYER_H
#include "Level.h"
#include <iostream>
#include <conio.h>
using namespace std;

class Player
{
private:
	int Lives;
	int Spades;
	int Rounds;
	int Scores;
	bool Won;
	bool Lost;
	Patch* Walk;

public:
	Player();

	//Player Movement
	void Move(Level& lvl, Player& user, char mode);

	//To Get Scores
	bool LostCheck();

	//Check If Player is Lost ot Not
	int GetScores();

	friend class Level;
	friend void PlayerStatus(Player);
	friend void PlayerScore(Player);
};

#endif // !PLAYER_H



