/****************************************************************************/
/*!
\file Dweller.cpp
\author Goh Zheng Yuan
\par email: 150377B\@mymail.nyp.edu.sg
\brief
Contains the functions of the class Dweller
*/
/****************************************************************************/

#include "Dweller.h"

/****************************************************************************/
/*!
\brief
Dweller default constructor.

Initalizes
position_ to 0,0
health_ to 100
radiation_ to 0
stimpak_ to 0
radAway_ to 0
outfit_ to nullptr
weapon_ to nullptr

\param name
	Name of dweller.

\param SPECIAL
	SPECIAL value of dweller.

*/
/****************************************************************************/
Dweller::Dweller(const string& name, const int& SPECIAL) :
GameObject(name),
position_(0, 0),
SPECIAL_(SPECIAL),
health_(100),
radiation_(0),
stimpak_(0),
radAway_(0),
outfit_(nullptr),
weapon_(nullptr)
{
}

/****************************************************************************/
/*!
\brief
Dweller Default Constructor
*/
/****************************************************************************/
Dweller::~Dweller()
{
}

/****************************************************************************/
/*!
\brief
Gets the SPECIAL value plus the outfit's SPECIAL value.

\return
	Returns SPECIAL value of Dweller plus the Outfit's SPECIAL value. If no outfit is assigned. Returns SPECIAL value of Dweller.
*/
/****************************************************************************/
const int Dweller::getSPECIAL()
{
	int store = 0;
	if (outfit_)
	{
		for (int i = 10; i <= 10000000; i *= 10)
		{
			if ((SPECIAL_ % i + outfit_->getSPECIAL() % i) - (SPECIAL_ % (i / 10) + outfit_->getSPECIAL() % (i / 10)) >= i)
				store += 9 * (i / 10);
			else
				store += (SPECIAL_ % i + outfit_->getSPECIAL() % i) - (SPECIAL_ % (i / 10) + outfit_->getSPECIAL() % (i / 10));
		}
		return store;
	}
	else
		return SPECIAL_;
}

/****************************************************************************/
/*!
\brief
Gets the SPECIAL value plus the outfit's SPECIAL value.

\return
	Returns SPECIAL value of Dweller plus the Outfit's SPECIAL value. If no outfit is assigned, returns SPECIAL value of Dweller.
*/
/****************************************************************************/
const int Dweller::getCurrentHealth()
{
	return health_;
}

/****************************************************************************/
/*!
\brief
Gets the radiation_ value.

\return
	Returns radiation_ value.
*/
/****************************************************************************/
const int Dweller::getCurrentRadDamage()
{
	return radiation_;
}

/****************************************************************************/
/*!
\brief
Gets dweller attack damage or weapon's attack damage.

\return
	Returns 1 if no weapon is assigned to dweller. Returns weapon's attack damage if dweller is assigned a weapon.
*/
/****************************************************************************/
const int Dweller::getAttackDmg()
{
	if (!weapon_)
	{
		return 1;
	}
	else
		return weapon_->getAttackDmg();
}

/****************************************************************************/
/*!
\brief
Gets the position of the dweller.

\return
	Returns the position of the dweller.
*/
/****************************************************************************/
const Vec2D Dweller::getPosition()
{
	return position_;
}

/****************************************************************************/
/*!
\brief
Sets the position of the dweller.

\param position
	Vec2D position.
*/
/****************************************************************************/
void Dweller::setPosition(const Vec2D& position)
{
	position_ = position;
}

/****************************************************************************/
/*!
\brief
Deals damage to dweller's health.

\param damage
	Deals damage to dweller's health_ value.
*/
/****************************************************************************/
void Dweller::receiveHealthDamage(const int& damage)
{
	health_ -= damage;
}

/****************************************************************************/
/*!
\brief
Increases the radiation value.

\param damage
	damage value to increase radiation's value.
*/
/****************************************************************************/
void Dweller::receiveRadDamage(const int& damage)
{
	radiation_ += damage;
}

/****************************************************************************/
/*!
\brief
Deals damage to weapon/outfit. Deals no damage if no weapon/outfit is currently assigned.

\param damage
	Amount of damage to deal to weapon/outfit.
*/
/****************************************************************************/
void Dweller::receiveEquipmentDamage(const int& damage)
{
	if (weapon_)
	{
		weapon_->receiveDamage(damage);
		if (weapon_->getDurability() <= 0)
			weapon_ = nullptr;
	}
	if (outfit_)
	{
		outfit_->receiveDamage(damage);
		if (outfit_->getDurability() <= 0)
			outfit_ = nullptr;
	}
}

/****************************************************************************/
/*!
\brief
Adds stimpak.

\param amount
	How many Stimpak are added.
*/
/****************************************************************************/
void Dweller::addStimpak(const int& amount)
{
	stimpak_ += amount;
}

/****************************************************************************/
/*!
\brief
Adds RadAway.

\param amount
	How many RadAway are added.
*/
/****************************************************************************/
void Dweller::addRadAway(const int& amount)
{
	radAway_ += amount;
}

/****************************************************************************/
/*!
\brief
Uses 1 stimpak to recover 20 health. Max Health is calculated by deducting radiation from 100.
Amount of health healed should not go above Max health.
*/
/****************************************************************************/
void Dweller::useStimpak()
{
	if (stimpak_ >= 1)
	{
		stimpak_ -= 1;
		int maxHealth = 100 - radiation_;
		if (health_ + 20 >= maxHealth)
		{
			health_ += (maxHealth - health_);
		}
		else
		{
			health_ += 20;
		}
	}
}

/****************************************************************************/
/*!
\brief
Uses 1 RadAway to decrease the amount of radiation by 10.
*/
/****************************************************************************/
void Dweller::useRadAway()
{
	if (radAway_ >= 1)
	{
		radAway_ -= 1;
		radiation_ -= 10;
	}
}

/****************************************************************************/
/*!
\brief
Assigns a new outfit.

\param outfit
	New outfit to be assigned to outfit_.

\return
	returns the old outfit.
*/
/****************************************************************************/
Outfit* Dweller::assignOutfit(Outfit* outfit)
{
	Outfit* old = outfit_;
	if (outfit->getDurability() > 0)
	{
		outfit_ = outfit;
		return old;
	}
	else
		return old;
	
}

/****************************************************************************/
/*!
\brief
Assigns a new weapon.

\param weapon
	New weapon to be assigned to weapon_.

\return
	returns the old weapon.
*/
/****************************************************************************/
Weapon* Dweller::assignWeapon(Weapon* weapon)
{
	Weapon* old = weapon_;
	if (weapon->getDurability() > 0)
	{
		weapon_ = weapon;
		return old;
	}
	else
		return old;
	
} 

/****************************************************************************/
/*!
\brief
Checks if dweller is dead. If dweller is dead, weapon and outfit are assigned to null pointer.

\return
	Returns true if dweller health is <= 0. Else returns false.
*/
/****************************************************************************/
bool Dweller::isDead()
{
	if (health_ <= 0)
	{
		weapon_ = nullptr;
		outfit_ = nullptr;
		return true;
	}
	else
		return false;
}
