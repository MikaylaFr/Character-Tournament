/*********************************************************************
 * ** Program name: Project 4
 * ** Author: Mikayla Friend
 * ** Date: 3-3-19
 * ** Description: Main function, calls Game class and menu class to simulate game and ask user if they want to play again.
 * *********************************************************************/
#include "menu.hpp"
#include "game.hpp"
#include <iostream>
using std::cout;
using std::endl;


int main()
{
	Game game;
	Menu menu;
	bool loop = true;
	while(loop)
	{	
		if(!menu.begin())
			return 0;
		game.play();
		if(!menu.end())
			return 0;
	}

	return 0;
}
