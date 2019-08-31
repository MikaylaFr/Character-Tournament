/*********************************************************************
 * ** Program name: Project 3
 * ** Author: Mikayla Friend
 * ** Date: 2-16-19
 * ** Description: Header file of BlueMen class which is a child of Character class
 * *********************************************************************/

#include "character.hpp"
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

class BlueMen : public Character
{
	private:
		int defenseDie {3};
	public:
		BlueMen();
		~BlueMen();
		bool specialAbility();
		int rollAttack();
		void rollDefense(int attack);
		void setDefenseDie(int d);
};
#endif
