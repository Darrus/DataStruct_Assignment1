/****************************************************************************/
/*!
\file Outfit.h
\author Goh Zheng Yuan
\par email: 150377B\@mymail.nyp.edu.sg
\brief 
Contains the class Outfit
*/
/****************************************************************************/

#ifndef H_OUTFIT
#define H_OUTFIT

#include "Item.h"

/****************************************************************************/
/*!
	Class Outfit : public Item

\brief A class that holds the Outfit's SPECIAL.
*/
/****************************************************************************/
class Outfit : public Item
{
	const int kSPECIAL = 0; ///< SPECIAL value with each letter representing a stat. Strength, Perception , Endurance, Charisma, Intelligence, Agility, Luck. Each Stat has a min value of 0 to max value of 9
public:
	
	Outfit(const string& name = "", const int& durability = 0, const int& special = 0); ///<Default Constructor
	virtual ~Outfit(); ///< Virtual Destructor 

	//Getters
	const int getSPECIAL(); ///< Gets the SPECIAL value of outfit.

	//Setters
	virtual void receiveDamage(const int& damage); ///< Receives damage to durability of outfit.
};

#endif

