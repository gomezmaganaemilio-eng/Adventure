#include "Player.h"
#include "Game.h"

Player::Player() : Character()
{
	this->agility = 8;
	this->intelligence = 8;
	this->dexterity = 8;
	this->luck = 8;
	this->strenght = 8;
}

void Player::InitPlayer(std::string name)
{
	InitCharacter(name);
	SetLevel(1);
	SetExp(0);
	SetHp((this->intelligence*2)/(this->dexterity-2));
	SetDamageMin(this->strenght / 2);
	SetDamageMax(this->strenght + 8);
	SetDefence((this->agility * 10) / (this->luck / 4));
	//SetDefence((this->strenght+1) - (this->intelligence));
	this->Maxesp = 10;

}


void Player::AddStats(int stat, int value)
{
	if (skillPoints < value)
	{
		std::cout << "Not Enought Points" << std::endl;
	}
	else
	{
		switch (stat)
		{
		case 1:
			this->strenght += value;
			skillPoints -= value;
			UpdateValues();
			break;
		case 2:
			this->agility += value;
			skillPoints -= value;
			UpdateValues();
			break;
		case 3:
			this->intelligence += value;
			skillPoints -= value;
			UpdateValues();
			break;
		case 4:
			this->dexterity += value;
			skillPoints -= value;
			UpdateValues();
			break;
		case 5:
			this->luck += value;
			skillPoints -= value;
			UpdateValues();
			break;

		default:
			std::cout << "This stat not Exist" << std::endl;
			break;
		}
	}
}
void Player::UpdateValues()
{
	SetHp((this->intelligence * 2) / (this->dexterity - 2));
	SetDamageMin(this->strenght / 2);
	SetDamageMax(this->strenght + 8);
	SetDefence((this->agility * 10) / (this->luck / 4));
}
Player::~Player()
{
}
void Player::PrintPlayerStats()
{
	PrintStats();
	std::cout << "-------------- " << std::endl;
	std::cout << "Strenght: " << this->strenght << std::endl;
	std::cout << "Agiliy: " << this->agility << std::endl;
	std::cout << "Intelligence: " << this->intelligence << std::endl;
	std::cout << "luck: " << this->luck << std::endl;
	std::cout << "Dexterity: " << this->dexterity << std::endl;
	std::cout << "Exp for next level: " << this->Maxesp << std::endl;
}

void Player::LevelUp()
{
	while (GetExp() >= Maxesp)
	{
		SetExp(GetExp() - Maxesp);
		SetLevel(GetLevel() + 1);
		Maxesp = GetLevel() * 10;
		skillPoints++;
	}
}


