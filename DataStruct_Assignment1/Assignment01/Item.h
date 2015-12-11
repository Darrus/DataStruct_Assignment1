/****************************************************************************/
/*!
\file Item.h
\author Goh Zheng Yuan
\par email: 150377B\@mymail.nyp.edu.sg
\brief 
Abstract class Item of base class GameObject.
*/
/****************************************************************************/

#ifndef H_ITEM
#define H_ITEM

#include "GameObject.h"

/****************************************************************************/
/*!
	Class Item : public GameObject

\brief An abstract class that holds the item's durability and passes in the name of the Item to GameObject.
*/
/****************************************************************************/
class Item : public GameObject
{
protected:
	int durability_; ///< Durability of an item

public:
	Item(const string& name = "", const int& durability = 0); ///< Default Constructor
	virtual ~Item(); ///< Virtual Destructor 

	//Getters
	const int getDurability(); ///< Returns durability of item.

	//Setters
	virtual void receiveDamage(const int& damage) = 0; ///< A pure virtual function for derived class(Outfit & Weapon) to use.
	
};

#endif

