/*********************************************************************
 * ** Program name: Project 3
 * ** Author: Mikayla Friend
 * ** Date: 2-16-19
 * ** Description: Function implementation file for HarryPotter class which is a child of Character class.
 * Special ability is a single revive.
 * *********************************************************************/

#include "harrypotter.hpp"
#include "menu.hpp"
#include <iostream>
using std::cout;
using std::endl;

//Constructor, initializes necessary member variables
HarryPotter::HarryPotter()
{
	type = "Harry Potter";
	armor = 0;
	strength = 10;
	revive = 1;
}

//Destructor
HarryPotter::~HarryPotter()
{

}

//Attack function, simulates 2 six sided die
int HarryPotter::rollAttack()
{
	Menu menu;
	attack = menu.randomInt(1, 6) + menu.randomInt(1, 6);
	return attack;
}

//Defense function, simulates 2 six sided die, calculates damage and strength
void HarryPotter::rollDefense(int attack)
{
	Menu menu;
	
	defense = menu.randomInt(1, 6) + menu.randomInt(1, 6);
	
	damage = attack - defense - armor;
	
	if(damage > 0)
	{
		strength = strength - damage;
	}

	if(strength < 1 && revive == 1)
	{
		cout << "\nHarry Potter uses Hogwarts!\n" << endl;
		strength = 20;
		revive = 0;
		totalDamage = 0;
	}
}


