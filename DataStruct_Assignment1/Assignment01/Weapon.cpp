/****************************************************************************/
/*!
\file Weapon.cpp
\author Goh Zheng Yuan
\par email: 150377B\@mymail.nyp.edu.sg
\brief
Contains the functions of the class Weapon.
*/
/****************************************************************************/

#include "Weapon.h"

/****************************************************************************/
/*!
\brief
Weapon default constructor.

\param name
	Name of weapon.

\param durability
	Durability of weapon.

\param damage
	Weapon attack damage value.
*/
/****************************************************************************/
Weapon::Weapon(const string& name, const int& durability, const int& damage) : Item(name, durability), kAttackDmg(damage > 0 ? damage : 0)
{
}

/****************************************************************************/
/*!
\brief
Weapon virtual destructor.
*/
/****************************************************************************/
Weapon::~Weapon()
{
}

/****************************************************************************/
/*!
\brief
	Gets the attack damage of weapon.

\return
	returns kAttackDmg of this class.
*/
/****************************************************************************/
const int Weapon::getAttackDmg()
{
	return kAttackDmg;
}

/****************************************************************************/
/*!
\brief
Weapons receive halve of damage value to durability_.

\param damage
	Amount of damage to deal to durability_.
*/
/****************************************************************************/
void Weapon::receiveDamage(const int& damage)
{
	durability_ -= damage / 2;
}