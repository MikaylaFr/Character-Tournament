/*********************************************************************
 * ** Program name: Project 3
 * ** Author: Mikayla Friend
 * ** Date: 2-16-19
 * ** Description: Header file for Medusa class which is a child of Character
 * *********************************************************************/
#include "character.hpp"
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

class Medusa : public Character
{
	public:
		Medusa();
		~Medusa();
		int rollAttack();
		void rollDefense(int attack);
};
#endif

