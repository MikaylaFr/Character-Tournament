/*********************************************************************
 * ** Program name: Project 3
 * ** Author: Mikayla Friend
 * ** Date: 2-16-19
 * ** Description: Function implementation file for Vampire class which is a child of Character.
 * Special ability is 50% chance to use "Charm" 
 * *********************************************************************/
#include "vampire.hpp"
#include "menu.hpp"
#include <iostream>
using std::cout;
using std::endl;

//Constructor
Vampire::Vampire()
{
	type = "Vampire";
	armor = 1;
	strength = 18;
}

//Destructor
Vampire::~Vampire()
{

}

//Attack function, simulates 1 twelve sided dice
int Vampire::rollAttack()
{
	Menu menu;
	attack = menu.randomInt(1, 12);
	return attack;
}

//returns true 50% time the function is called, if true special ability is used
bool Vampire::specialAbility()
{
	Menu menu;

	if(menu.randomInt(1, 100) < 51) //Uses charm
		return true;
	else //doesnt use charm
		return false;
}

//Defense function, if vampire uses charm ability, sets damage and defense to 0. Else it simulates 2 six sided die to roll
//defense and calculates damage. Also calculates strength.
void Vampire::rollDefense(int attack)
{
	Menu menu;
	
	if(specialAbility())
	{
		cout << "\nVampire uses charm\n" << endl;
		damage = 0;
		defense = 0;
	}
	else
	{
		defense = menu.randomInt(1, 6) + menu.randomInt(1, 6);
	
		damage = attack - defense - armor;
	}
	
	if(damage > 0)
	{
		strength = strength - damage;
	}
	
}
