/****************************************************************************/
/*!
\file GameObject.cpp
\author Goh Zheng Yuan
\par email: 150377B\@mymail.nyp.edu.sg
\brief
Contains the functions of Abstract class GameObject.
*/
/****************************************************************************/

#include "GameObject.h"

int GameObject::count_ = 0; //Initialize count_ as 0

/****************************************************************************/
/*!
\brief
GameObject Default Constructor, increases count by 1.

\param	name
	Name of object.
*/
/****************************************************************************/
GameObject::GameObject(const std::string& name) : kName(name)
{
	count_++;
}

/****************************************************************************/
/*!
\brief 
GameObject virtual Destructor, decreases count by 1.
*/
/****************************************************************************/
GameObject::~GameObject()
{
	count_--;
}

/****************************************************************************/
/*!
\brief
A getter for returning kName.

\return
	Returns string kName of this class.
*/
/****************************************************************************/
std::string GameObject::getName()
{
	return kName;
}

/****************************************************************************/
/*!
\brief
A getter for getting the value of count_.

\return
	Returns count_ value from this class.
*/
/****************************************************************************/
int GameObject::getCount()
{
	return count_;
}
