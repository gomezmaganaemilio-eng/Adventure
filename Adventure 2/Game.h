#pragma once
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Event.h"
class Game
{
private: 
	Player player;
	/* al escribir Player y las clases con un nombre sencillo
	las podemos llamar y ponerles un punto para informar una funcion
	que tienen esas clases desde ptra clase, muy fácil.*/
	Enemy* enemy;
	int choice;
	bool playing;
	Event v;
public:


	Game();
	virtual ~Game();
	void InitGame();
	void mainMenu();

	void Travel();

	void SavePlayer();
	void LoadPlayer();
	void NewPlayer();
	void NewEnemy();
	void PrintPlayerStats();

	void Levelup();
	void Skillup();

	bool GetPlaying();
};

