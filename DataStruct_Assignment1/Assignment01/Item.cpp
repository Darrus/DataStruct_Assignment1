/****************************************************************************/
/*!
\file Item.cpp
\author Goh Zheng Yuan
\par email: 150377B\@mymail.nyp.edu.sg
\brief
Contains the functions of Abstract class Item.
*/
/****************************************************************************/
#include "Item.h"

/****************************************************************************/
/*!
\brief
Item Default Constructor.

\param name
	Name of the item.

\param durability
	Durability of the item.
*/
/****************************************************************************/
Item::Item(const std::string& name, const int& durability) : durability_(durability), GameObject(name)
{
}

/****************************************************************************/
/*!
\brief
Item virtual Destructor.
*/
/****************************************************************************/
Item::~Item()
{
}

/****************************************************************************/
/*!
\brief
Gets the durability of the item.

\return
	Returns durability_.
*/
/****************************************************************************/
const int Item::getDurability()
{
	return durability_;
}