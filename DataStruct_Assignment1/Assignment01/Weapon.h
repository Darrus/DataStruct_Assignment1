/****************************************************************************/
/*!
\file Weapon.h
\author Goh Zheng Yuan
\par email: 150377B\@mymail.nyp.edu.sg
\brief
Contains the class Weapon
*/
/****************************************************************************/

#ifndef H_WEAPON
#define H_WEAPON 

#include "Item.h"

/****************************************************************************/
/*!
	Class Weapon : public Item

\brief
A class of base class Item that holds weapon's attack value. 
*/
/****************************************************************************/
class Weapon : public Item
{
	const int kAttackDmg; ///< Weapon attack Damage
public:
	Weapon(const string& name = "", const int& durability = 0, const int& damage = 0); ///< Default Constructor
	virtual ~Weapon(); ///< Virtual Destructor
	
	//Getters
	const int getAttackDmg(); ///< Returns weapon attack damage

	//Setters
	virtual void receiveDamage(const int& damage); ///< Receives damage to weapon's durability
};

#endif

