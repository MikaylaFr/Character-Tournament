/*********************************************************************
 * ** Program name: Project 3
 * ** Author: Mikayla Friend
 * ** Date: 2-16-19
 * ** Description: Header file for HarryPotter class which is a child of Character class
 * *********************************************************************/
#include "character.hpp"
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

class HarryPotter : public Character
{
	private:
		int revive;
	public:
		HarryPotter();
		~HarryPotter();
		int rollAttack();
		void rollDefense(int attack);
};
#endif
