/*********************************************************************
 * ** Program name: Project 3
 * ** Author: Mikayla Friend
 * ** Date: 2-16-19
 * ** Description: Function implementation file for Medusa class which is a child of Character.
 * Special ability is insta-kill if attack rolls a 12
 * *********************************************************************/
#include "medusa.hpp"
#include "menu.hpp"
#include <iostream>
using std::cout;
using std::endl;

//Constructor
Medusa::Medusa()
{
	type = "Medusa";
	armor = 3;
	strength = 8;
}


//Destructor
Medusa::~Medusa()
{

}


//Attack function, simulates 2 six sided die. If 12 is rolled, is insta-kill.
int Medusa::rollAttack()
{
	Menu menu;
	
	attack = menu.randomInt(1, 6) + menu.randomInt(1, 6);
	
	if(attack == 12)
	{	
		attack = 100;
		cout << "\nMedusa uses glare!\n" << endl;
	}
	
	return attack;
}


//Defense function, simulates 1 six sided die. Calculates damage and strength
void Medusa::rollDefense(int attack)
{
	Menu menu;
	
	defense = menu.randomInt(1, 6); //Defense roll

	damage = attack - defense - armor;
		
	if(damage > 0)
	{
		strength = strength - damage;
	}
}
