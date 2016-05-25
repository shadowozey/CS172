#ifndef TURTLE_H
#define TURTLE_H
#include <string>
#include "monster.h"

using namespace std;

class Turtle: public monster
{
	public:
		Turtle(string n = "No name");
		
		//Methods of monster
		string getName() const;
		string getDescription() const;
		void basicAttack(monster * enemy);
		string basicName() const;
		void defenseAttack(monster * enemy);
		string defenseName() const;
		void specialAttack(monster * enemy);
		string specialName() const;
		int getHealth() const;
		void doDamage(int damage);
		void resetHealth();
		
	protected:
		string name;
		int health;
		bool defense_mode;
		
};

Turtle::Turtle(string n)
{
	name = n;
	health=150;
	defense_mode=false;
}

string Turtle::getName() const
{
	return name;
}

string Turtle::getDescription() const
{
	return "The turtle is big and slow.";
}

void Turtle::basicAttack(monster * enemy)
{
	defense_mode=false;
	enemy->doDamage(52);
}

string Turtle::basicName() const
{
	return "Headbutt";
}

void Turtle::defenseAttack(monster * enemy)
{
	defense_mode=true;
}

string Turtle::defenseName() const
{
	return "Shell";
}

void Turtle::specialAttack(monster * enemy)
{
	defense_mode=false;//Can't defend and attack
	enemy->doDamage(64);
}

string Turtle::specialName() const
{
	return "Drown";
}

int Turtle::getHealth() const
{
	return health;
}
void Turtle::doDamage(int damage)
{
	if(defense_mode)
	{
		//Defense mode cuts damage in half
		health=health-(damage/2);
	}else
	{
		health=health-damage;
	}
}

void Turtle::resetHealth()
{
	health=150;
}
#endif