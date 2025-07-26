#ifndef SCOREINFO_H
#define SCOREINFO_H
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

class Info
{
public:
	int Score;
	string Name;

public:
	Info();
};

class ScoreInfo
{
private:
	Info ScoreList[11];
	fstream ScoreFile;
	string PlayerName, PlayerScore;
	int index = 0;

public:
	//Constructor for Loading Scores and Name from Database to the Program
	ScoreInfo();

	//Adding Scores and Name in an Array
	void AddScore(string name, int score);

	//Sort Scores in Descending Order
	void Sort();

	//Displaying Scores and Names
	void Display();

	//Destructor For Storing Scores and Names in Database 
	~ScoreInfo();
};

#endif // !SCOREINFO_H