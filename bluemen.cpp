/*********************************************************************
 * ** Program name: Project 3
 * ** Author: Mikayla Friend 
 * ** Date: 2-16-19
 * ** Description: File implementation of BlueMen class which is a child of Character class.
 * Special ability is amount of dice depending on strength
 * *********************************************************************/

#include "bluemen.hpp"
#include <iostream>
using std::cout;
using std::endl;
#include "menu.hpp"

//Constructor, initialize necessary variables
BlueMen::BlueMen()
{
	type = "Blue Men";
	armor = 3;
	strength = 12;
}

//Destructor
BlueMen::~BlueMen()
{

}

//Special abiliyt of BlueMen, amount of dice changes depending on strength
bool BlueMen::specialAbility()
{	
	Menu menu;
	if(totalDamage >= 0 && totalDamage <=4)
		defenseDie=3;
	else if(totalDamage>=5 && totalDamage <=8)
		defenseDie=2;
	else if(totalDamage >=9 && totalDamage <=12)
		defenseDie=3;

	if(defenseDie == 3) //3 die
		defense = menu.randomInt(1, 6) + menu.randomInt(1, 6) + menu.randomInt(1, 6);
	else if(defenseDie == 2) //2 die
		defense = menu.randomInt(1, 6) + menu.randomInt(1, 6);
	else if(defenseDie == 1) // 1 die
		defense = menu.randomInt(1, 6);
	
	return true;
}


//Attack function, represents 2 ten sided die
int BlueMen::rollAttack()
{
	Menu menu;
	attack = menu.randomInt(1, 10) + menu.randomInt(1, 10);
	return attack;
}


//Defense function, randomly rolls defense value, calculates damage and strength after
void BlueMen::rollDefense(int attack)
{
	specialAbility(); //defense roll
	
	damage = attack - defense - armor;
		
	if(damage > 0)
	{
		strength = strength - damage;
	}
}


void BlueMen::setDefenseDie(int d)
{
	defenseDie = d;
}

