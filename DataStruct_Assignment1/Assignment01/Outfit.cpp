/****************************************************************************/
/*!
\file Outfit.cpp
\author Goh Zheng Yuan
\par email: 150377B\@mymail.nyp.edu.sg
\brief
Contains the functions of the class Outfit.
*/
/****************************************************************************/

#include "Outfit.h"

/****************************************************************************/
/*!
\brief
Outfit default constructor.
\param name
	Name of outfit.
\param durability
	Durability of outfit.
\param special
	SPECIAL value of outfit.
*/
/****************************************************************************/
Outfit::Outfit(const string& name, const int& durability, const int& special) : Item(name, durability), kSPECIAL(special)
{
}

/****************************************************************************/
/*!
\brief
Outfit virtual destructor.
*/
/****************************************************************************/
Outfit::~Outfit()
{
}

/****************************************************************************/
/*!
\brief
Gets the SPECIAL value of the outfit.

\return
	returns kSPECIAL value.
*/
/****************************************************************************/
const int Outfit::getSPECIAL()
{
	return kSPECIAL;
}


/****************************************************************************/
/*!
\brief
Receive damage to durability of outfit.

\param damage
	Damage value to deal to durability.
*/
/****************************************************************************/
void Outfit::receiveDamage(const int& damage)
{
	durability_ -= damage;
}
