/*********************************************************************
 * ** Program name: Project 3
 * ** Author: Mikayla Friend
 * ** Date: 2-16-19
 * ** Description: Function implementation file for Barbarian class, child class of Character class
 * Represents a character to be chosen by a player.
 * *********************************************************************/

#include "barbarian.hpp"
#include "menu.hpp"
#include<iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

//Destructor
Barbarian::~Barbarian()
{

}


//Constructor, initialized necessary variables
Barbarian::Barbarian()
{
	type = "Barbarian";
	armor = 0;
	strength = 12;
}


//Attack function, represents two six sided dice
int Barbarian::rollAttack()
{
	Menu menu;
	attack = menu.randomInt(1, 6) + menu.randomInt(1, 6);
	return attack;
}

//Defense function, rolls two six sided dice, calculates total damage, calculates strength
void Barbarian::rollDefense(int attack)
{
	Menu menu;

	defense = menu.randomInt(1, 6) + menu.randomInt(1, 6); //Roll defense dice
	
	damage = attack - defense - armor; //Calculate damage
	
	if(damage > 0) //Calculates strength if damage is more than 0
	{
		strength = strength - damage;
	}
}


