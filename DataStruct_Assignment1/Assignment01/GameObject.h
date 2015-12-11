/****************************************************************************/
/*!
\file GameObject.h
\author Goh Zheng Yuan
\par email: 150377B\@mymail.nyp.edu.sg
\brief 
Abstract class GameObject.
*/
/****************************************************************************/
#ifndef H_GAMEOBJECT
#define H_GAMEOBJECT

#include <string>

using std::string;

/****************************************************************************/
/*!
	Class GameObject

\brief An abstract class for holding name of the object and count of object created.
*/
/****************************************************************************/
class GameObject
{
	string kName; ///< Name of Object
	static int count_; ///< Amount of Objects instantiated

protected:
	GameObject(const string& name = ""); ///< Default Constructor taking in a string

public:
	virtual ~GameObject(); ///< Virtual Destructor

	//Getters
	std::string getName(); ///< Get GameObject name
	static int getCount(); ///< Get count_ value
};

#endif

