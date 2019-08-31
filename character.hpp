/*********************************************************************
 * ** Program name: Project 3
 * ** Author: Mikayla Friend
 * ** Date: 2-16-19
 * ** Description: Header file for Character class which is an abstract class
 * *********************************************************************/

#include<string>
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character
{
	protected:
		int attack;
		int defense;
		int armor;
		int strength;
		int damage;
		int totalDamage {0};
		std::string name;
		Character *next;
		Character *prev;
		int damageTaken;
		std::string type;
		int revive;
	public:
		void setRevive(int r);
		void setTotalDamage(int t);
		int getTotalDamage();
		void setNext(Character *&n);
		Character* getNext();
		void setPrev(Character *&p);
		Character* getPrev();
		std::string getType();
		int getAttack();
		int getDefense();
		int getArmor();
		int getStrength();
		void setStrength(int s);
		int getDamage();
		std::string getName();
		void setName(std::string n);
		virtual int rollAttack() = 0;
		virtual void rollDefense(int attack) = 0;
		virtual ~Character() {};
};
#endif
