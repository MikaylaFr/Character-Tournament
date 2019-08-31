/*********************************************************************
 * ** Program name: Project 4
 * ** Author: Mikayla Friend
 * ** Date: 3-3-19
 * ** Description: Function implementation file for Game class. Acts as test driving functions for
 * Character child classes. Called by main. Organizes game play and prints to screen.
 * *********************************************************************/

#include "menu.hpp"
#include "game.hpp"
#include "barbarian.hpp"
#include "vampire.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
#include <cmath>


//Called by main, prompts users for number of characters per container, calls member functions to create containers, calls member function to simulate tournament 
//deallocate memory 
void Game::play()
{
	Character *teamOne = nullptr; //head of each container
	Character *teamTwo = nullptr;
	Menu menu;
	string input;
	int howMany;
	bool loop = true;

	cout << "Character Tournament!" << endl;
	cout << "Rules:\nWinning team from the previous round attacks first \nFor each round, winner +2 points and loser -1 point\n\n" << endl;
	cout << "Player One, how many Characters do you want on your team? Max: 15" << endl;
	while(loop) //input validation loop
	{
		getline(cin, input);
		howMany = menu.validateInt(input);
		if(howMany > 15 || howMany < 1)
			cout << "Invalid input. Max is 15 and min is 1." << endl;
		else
			loop = false;
	}
	loop = true;
	createContainers(teamOne, howMany);

	cout << "Player Two, how many Characters do you want on your team? Max: 15" << endl;
	while(loop) //input validation loop
	{
		getline(cin, input);
		howMany = menu.validateInt(input);
		if(howMany > 15 || howMany < 1)
			cout << "Invalid input. Max is 15 and min is 1." << endl;
		else
			loop = false;
	}
	createContainers(teamTwo, howMany);
	
	fight(*&teamOne, *&teamTwo);

	end();

	deallocate(*&teamOne, *&teamTwo);

}


//Displays final score and loser container if user chooses to display
void Game::end()
{
	cout << "\n\n\n" << endl;
	cout << "Final Score: " << endl;
	cout << "Team One: " << teamOnePoints << endl;
	cout << "Team Two: " << teamTwoPoints << endl;

	if(teamOnePoints > teamTwoPoints)
	{
		cout << "\nTeam One wins with " << teamOnePoints << endl;
	}
	else if(teamOnePoints < teamTwoPoints)
	{
		cout << "\nTeam Two wins with " << teamTwoPoints << endl;
	}
	else
	{	
		cout << "\nIt is a tie!" << endl;
	}

	cout << "\n\nWould you like to view the loser container?" << endl;
	cout << "(1) Yes " << endl;
	cout << "(2) No" << endl;
	string input;
	bool loop = true;
	while(loop) //Player one input validation
		{
			getline(std::cin, input);	
			if(input.length() > 1)
			{	
				cout << string(20, '=') << "! error !" << string(20, '=') <<  endl;
				cout << "Invalid input" << endl;
				cout << string(49, '=') << endl;
			}
			else if(input[0] == '1') //Print container
			{
				loop=false;
				int i = 1;
				Character *print = losersCont;
				cout << "\n\n" << i << ". " << print->getName() << " the " << print->getType() << endl;
				i++;
				print = print->getNext();

				while(print != losersCont)
				{
					cout << i << ". " << print->getName() << " the " << print->getType() << endl;
					i++;
					print = print->getNext();
				}
			}
			else if(input[0] == '2')
			{	
				loop=false;
			}
			else
			{
				cout << string(20, '=') << "! error !" << string(20, '=') <<  endl;
				cout << "Invalid input" << endl;
				cout << string(49, '=') << endl;
			}
		}


}

//Calls member functions to organize gameplay. Determines who attacks first with random function. Uses while loop to keep
//game going until a death of a character.
void Game::fight(Character *&teamOne, Character *&teamTwo)
{
	Menu menu;
	bool loop = true;
	int totalDamage = 0;

	int turn = menu.randomInt(1, 2);//Randomly pick who attacks first.
	round = 1;

	while(teamOne != nullptr || teamTwo != nullptr) //Ends when one container is empty
	{
		cout << string(40, '=') << endl;
		cout << string(40, '=') << endl;
		cout << "\nTeam One: " << teamOnePoints << " Points" << endl;
		cout << "Team Two: " << teamTwoPoints << " Points" << endl;
		teamOne->setTotalDamage(0);//reset total damage counter
		teamTwo->setTotalDamage(0);
		
		while(loop) //Gameplay
		{
			if(turn == 1) //Player one attacking
			{		
				cout << string(40, '=') << endl;
				cout << "Team one attacking" << endl;
				loop = attackPhase(teamOne, teamTwo);
				if(teamTwo->getDamage() > 0) //Add how much damage taken
				{	
					totalDamage = teamTwo->getTotalDamage() + teamTwo->getDamage();
					teamTwo->setTotalDamage(totalDamage);
				}

				if(!loop)
				{	cout << string(40, '-') << endl;
			 		cout << string(40, '=') << endl;
					cout << teamOne->getName() << " the " << teamOne->getType() << " from Team One wins\n" << endl;
					loop = false;
				}
				else
					turn = 2;
			}

			if(turn == 2) //Player two attacking
			{	
				cout << string(40, '=') << endl;
				cout << "Team two attacking" << endl;
				loop = attackPhase(teamTwo, teamOne);
				if(teamOne->getDamage() > 0)
				{
					totalDamage = teamOne->getTotalDamage() + teamOne->getDamage();
					teamOne->setTotalDamage(totalDamage);
				}

				if(!loop)
				{	cout << string(40, '-') << endl;
			 		cout << string(40, '=') << endl;
					cout << teamTwo->getName() << " the " << teamTwo->getType() << " from Team Two wins\n" << endl;
					loop = false;
				}
				else
					turn = 1;
			}
		}
		loop = true;

		if(turn == 1) //if team one wins round
		{
			teamOnePoints += 2;
			teamTwoPoints--;
			if(loserContainer(teamTwo) == false)
				return;
			else
				recovery(teamOne);
			teamOne = teamOne->getNext(); //move to next fighter in queue
		}
		else //If team two wins round
		{
			teamTwoPoints += 2;
			teamOnePoints --;
			if(loserContainer(teamOne) == false)
				return;
			else
				recovery(teamTwo);
			teamTwo = teamTwo->getNext(); //Move to next fighter in queue
		}

	}
	
	return;
}

//Recovers a random percentage of health to the winner, recovers harry potters special ability
void Game::recovery(Character *winner)
{
	if(winner->getTotalDamage() < 1)
	{
		cout << "The winner took no damage this battle" << endl;
	}
	else
	{	
		Menu menu;
		int roll = menu.randomInt(1, 10);
		roll = roll * 10;
		cout << winner->getName() << " the " << winner->getType() << " recovers " << roll << "% of " << winner->getTotalDamage() << " damage taken" << endl;
		double recovery = roll * winner->getTotalDamage();
		recovery = recovery / 100;
		recovery = std::round(recovery);
		cout << recovery << " strength points restored\n\n" << endl;
		recovery = winner->getStrength() + recovery;
		winner->setStrength(recovery);

	}
	
	if(winner->getType() == "Harry Potter") //reset Harry Potters ability
	{
		winner->setRevive(1);
	}
}

//Adds losers to the loser container
bool Game::loserContainer(Character *&team)
{
	Character *prevTemp = team->getPrev();
	Character *nextTemp = team->getNext();
	Character *loser = team;
	Character *loserTemp;
	
	if(losersCont == nullptr) //add to loser list
	{
		losersCont = loser;
		losersCont->setNext(loser); //points to itself
		losersCont->setPrev(loser);
	}
	else //If container is not empty
	{
		loserTemp = losersCont->getPrev();
		loser->setNext(losersCont);
		loser->setPrev(loserTemp);
		loserTemp->setNext(loser);
		losersCont->setPrev(loser);
	}
	
	if(prevTemp != team) //More than one fighter left
	{
		prevTemp->setNext(nextTemp); //take current fighter out of list
		nextTemp->setPrev(prevTemp);

		team = nextTemp; //team header to next fighter
		return true;
	}
	else //If one fighter left
	{
		team = nullptr;
		return false;
	}
}


//Menu for user to pick a character. Creates dynamically created object depending on choice and assigns it to pointers that are
//member variables. Includes input validation
void Game::createContainers(Character *&head, int howMany)
{
	
	bool loop = true;
	string input;
	Character *newNode=nullptr;
	Menu menu;
	
	for(int i=0; i<howMany; i++)
	{
		cout << "Choose your character: " << endl;
		cout << "(1) Barbarian" << endl;
		cout << "(2) Vampire" << endl;
		cout << "(3) Blue Men" << endl;
		cout << "(4) Medusa" << endl;
		cout << "(5) Harry Potter" << endl;
			
		while(loop) //Player one input validation
		{
			getline(std::cin, input);	
			if(input.length() > 1)
			{	
				cout << string(20, '=') << "! error !" << string(20, '=') <<  endl;
				cout << "Invalid input" << endl;
				cout << string(49, '=') << endl;
			}
			else if(input[0] == '1')
			{
				loop=false;
				newNode = new Barbarian;
			}
			else if(input[0] == '2')
			{	
				loop=false;
				newNode = new Vampire;
			}
			else if(input[0] == '3')
			{	
				loop=false;
				newNode = new BlueMen;
			}
			else if(input[0] == '4')
			{	
				loop=false;
				newNode = new Medusa;
			}
			else if(input[0] == '5')
			{
				loop=false;
				newNode = new HarryPotter;
			}
			else
			{
				cout << string(20, '=') << "! error !" << string(20, '=') <<  endl;
				cout << "Invalid input" << endl;
				cout << string(49, '=') << endl;
			}
		}
		
		loop = true;
		cout << "Enter a name for your chosen character: ";
		getline(cin, input);
		newNode->setName(menu.validateName(input));
		cout << endl;
		Character *temp;

		if(head == nullptr) //No node
		{
			head = newNode;
			newNode->setNext(head);
			newNode->setPrev(head);
		}
		else
		{
			temp = head->getPrev();
			newNode->setNext(head);
			newNode->setPrev(temp);
			temp->setNext(newNode);
			head->setPrev(newNode);
		}

	}

	cout << "\nHere are your champions:" << endl; //print team
	Character *print = head;
	int i = 1;
	cout << i << ". " << print->getName() << " the " << print->getType() << endl;
	print = print->getNext();
	i++;

	while(print != head)
	{
		cout << i << ". " << print->getName() << " the " << print->getType() << endl;
		print = print->getNext();
		i++;
	}
	cout << "\n\n" << endl;
	
}


//Simulates attack phase in game, attacker will attack twice. Displays stats. Determines if defender is dead.
bool Game::attackPhase(Character *attacker, Character *defender)
{
	cout << "Round: " << round << endl;
	for(int i=0; i < 2; i++)
	{
		cout << string(40, '-') << endl;
		cout << "\nAttacker Type: " << attacker->getName() << " the " << attacker->getType() << endl;
		cout << "Defender Type: " << defender->getName() << " the " << defender->getType() << endl;
		cout << "    Armor: " << defender->getArmor() << endl;
		cout << "    Strength: " << defender->getStrength() << endl;
		cout << "Attacker's attack dice roll: " << attacker->rollAttack() << endl;
		
		defender->rollDefense(attacker->getAttack());
		
		cout << "Defender's defense dice roll: " << defender->getDefense() << endl;
		
		cout << "Total damage: " << defender->getDamage() << endl;
		
		if((attacker->getAttack() - defender->getDefense() - defender->getArmor()) < 1)
			cout << "\nAttacker's attack had no effect\n" << endl;

		cout << "Defender's updated strength: " << defender->getStrength() << endl;

		if(defender->getStrength() < 1)
		{
			cout << "\n" << defender->getName() << " the " << defender->getType() << " has been defeated" << endl;
			return false;
		}
	}
	
	round++;
	cout << string(40, '-') << endl;
	cout << string(40, '=') << endl;

	return true;
}


//Deallocates dynamically allocated memory
void Game::deallocate(Character *&teamOne, Character *&teamTwo)
{
	Character *last;
	Character *temp;
	if(teamOne != nullptr)
	{
		last = teamOne->getPrev();

		while(teamOne != last)
		{
			temp = teamOne->getNext();
			delete teamOne;
			teamOne = temp;
		}

		delete last;
		teamOne = nullptr;
	}

	if(teamTwo != nullptr)
	{
		last = teamTwo->getPrev();

		while(teamTwo != last)
		{
			temp = teamOne->getNext();
			delete teamTwo;
			teamTwo = temp;
		}

		delete last;
		teamTwo = nullptr;
	}

	last = losersCont->getPrev();

	while(losersCont != last)
	{
		temp = losersCont->getNext();
		delete losersCont;
		losersCont = temp;
	}

	delete last;
	losersCont = nullptr;
	temp = nullptr;
	last = nullptr;
}
