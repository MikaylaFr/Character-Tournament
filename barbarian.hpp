/*********************************************************************
 * ** Program name: Project 3
 * ** Author: Mikayla Friend
 * ** Date: 2-16-19
 * ** Description: Header file for Barbarian class which is a child of Character class
 * *********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "character.hpp"

class Barbarian : public Character
{
	public:
		~Barbarian();
		Barbarian();
		int rollAttack();
		void rollDefense(int attack);

};
#endif


