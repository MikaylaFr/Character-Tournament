/*********************************************************************
 * ** Program name: Project 4
 * ** Author: Mikayla Friend
 * ** Date: 3-3-19
 * ** Description: Header file for Game class.
 * *********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "character.hpp"

class Game
{
	private:
		Character *losersCont = nullptr;
		int teamOnePoints {0};
		int teamTwoPoints {0};
		int round;
	public:
		void createContainers(Character *&head, int howMany);
		void deallocate(Character *&teamOne, Character *&teamTwo);
		void play();
		bool attackPhase(Character *attacker, Character *defender);
		void fight(Character *&teamOne, Character *&teamTwo);
		bool loserContainer(Character *&team);
		void end();
		void recovery(Character *winner);

};
#endif
