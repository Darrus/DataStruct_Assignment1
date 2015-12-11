/****************************************************************************/
/*!
\file Dweller.h
\author Goh Zheng Yuan
\par email: 150377B\@mymail.nyp.edu.sg
\brief 
Contains the class Dweller
*/
/****************************************************************************/

#ifndef H_DWELLER
#define H_DWELLER

#include "GameObject.h"
#include "Vec2D.h"
#include "Outfit.h"
#include "Weapon.h"

/****************************************************************************/
/*!
	Class Dweller : public GameObject

\brief Contains the character's Health, Special, Radiation, Stimpak, radaway, outfit, weapon and position.
Uses outfit and weapon class. Uses struct vec2D.
*/
/****************************************************************************/
class Dweller : public GameObject
{
	Vec2D position_; ///< Contains Dweller's Position 
	int SPECIAL_; ///< SPECIAL value with each letter representing a stat. Strength, Perception , Endurance, Charisma, Intelligence, Agility, Luck. Each Stat has a min value of 0 to max value of 9
	int health_; ///< Dweller's health
	int radiation_; ///< Radiation lowers the Character's Max Health
	int stimpak_; ///< Stimpak heals the character by 20
	int radAway_; ///< RadAway decrease the radiation value
	Outfit* outfit_; ///< Outfit pointer to hold outfit of dweller
	Weapon* weapon_; ///< Weapon pointer to hold weapon of dweller

public:
	Dweller(const string& name = "", const int& SPECIAL = 0); ///< Default Constructor
	virtual ~Dweller(); ///< Virtual Destructor

	//Getters
	const int getSPECIAL(); ///< Gets SPECIAL value of dweller plus Outfit's SPECIAL value
	const int getCurrentHealth(); ///< Gets health_ value of dweller
	const int getCurrentRadDamage(); ///< Gets radiation_ value of dweller
	const int getAttackDmg(); ///< Gets damage of dweller from weapon class. returns 1 if no weapon is assigned.
	const Vec2D getPosition(); ///< Gets the position of the dweller.

	//Setters
	void setPosition(const Vec2D& position); ///< Sets position of the dweller.
	void receiveHealthDamage(const int& damage); ///< Decreases health_ value.
	void receiveRadDamage(const int& damage); ///< Increases radiation_ value.
	void receiveEquipmentDamage(const int& damage); ///< Decreases weapon/outfit durability_ value.
	void addStimpak(const int& amount); ///< Increases the amount of stimpak dweller holds.
	void addRadAway(const int& amount); ///< Increases the amount of radaway dweller holds.
	void useStimpak(); ///< Uses stimpak to heal the dweller.
	void useRadAway(); ///< Uses radaway to decrease amount of radiation.
	Outfit* assignOutfit(Outfit* outfit); ///< Assign outfit to dweller.
	Weapon* assignWeapon(Weapon* weapon); ///< Assign weapon to dweller.
	bool isDead(); ///< Checks if dweller is dead.
};
#endif
