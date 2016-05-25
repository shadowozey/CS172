#ifndef DOG_H
#define DOG_H

#include <string>
#include "monster.h"

using namespace std;

class dog : public monster
{
public:
	dog(string n = "No name");

	//Methods of monster
	string getName() const;
	string getDescription() const;
	void basicAttack(monster * enemy);
	string basicName() const;
	void attackModeAttack(monster * enemy);
	string attackName() const;
	void specialAttack(monster * enemy);
	string specialName() const;
	int getHealth() const;
	void doDamage(int damage);
	void resetHealth();

protected:
	string name;
	int health;
	bool attack_mode;

};

dog::dog(string n)
{
	name = n;
	health = 150;
	attack_mode = false;
}

string dog::getName() const
{
	return name;
}

string dog::getDescription() const
{
	return "The dog is fast and is frothing from the mouth.";
}

void dog::basicAttack(monster * enemy)
{
	attack_mode = false;
	enemy->doDamage(40);
}

string dog::basicName() const
{
	return "bite";
}

void dog::attackModeAttack(monster * enemy)
{
	attack_mode = true;
}

string dog::attackName() const
{
	return "gives rabies";
}

void dog::specialAttack(monster * enemy)
{
	attack_mode = false;
	enemy->doDamage(50);
}

string dog::specialName() const
{
	return "tackles and bites throat";
}

int dog::getHealth() const
{
	return health;
}
void dog::doDamage(int damage)
{
	if (attack_mode)
	{
		health = health - (damage * 2);
	}
	else
	{
		health = health - damage;
	}
}

void dog::resetHealth()
{
	health = 150;
}
#endif