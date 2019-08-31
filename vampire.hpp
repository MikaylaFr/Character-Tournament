/*********************************************************************
 * ** Program name: Project 3
 * ** Author: Mikayla Friend
 * ** Date: 2-16-19
 * ** Description: Header file for Vampire class which is a child of Character
 * *********************************************************************/
#include "character.hpp"
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

class Vampire : public Character
{
	public:
		Vampire();
		~Vampire();
		bool specialAbility();
		int rollAttack();
		void rollDefense(int attack);
};
#endif
