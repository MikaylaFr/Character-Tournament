/*********************************************************************
 * ** Program name: Project 3
 * ** Author: Mikayla Friend
 * ** Date: 2-16-19
 * ** Description: Function implementation file for Character class. Defines getters and setters for
 * member variables.
 * *********************************************************************/

#include <string>
#include "character.hpp"

void Character::setRevive(int r)
{
	revive = r;
}


void Character::setTotalDamage(int t)
{
	totalDamage = t;
}


int Character::getTotalDamage()
{
	return totalDamage;
}


void Character::setStrength(int s)
{
	strength = s;
}


Character* Character::getNext()
{
	return next;
}

Character* Character::getPrev()
{
	return prev;
}

void Character::setNext(Character *&n)
{
	next = n;
}

void Character::setPrev(Character *&p)
{
	prev = p;
}


std::string Character::getType()
{
	return type;
}

int Character::getAttack()
{
	return attack;
}


int Character::getDefense()
{
	return defense;
}


int Character::getArmor()
{	
	return armor;
}


int Character::getStrength()
{
	return strength;
}


int Character::getDamage()
{
	return damage;
}


std::string Character::getName()
{
	return name;
}


void Character::setName(std::string n)
{
	name = n;
}
