/****************************************************************************/
/*!
\file Vec2D.h
\author Goh Zheng Yuan
\par email: 150377B\@mymail.nyp.edu.sg
\brief
Contains the struct Vec2D
*/
/****************************************************************************/

#ifndef H_VEC2D
#define H_VEC2D

/****************************************************************************/
/*!
struct Vec2D

\brief A struct to hold a 2D vector.
*/
/****************************************************************************/
struct Vec2D
{
	double x; ///< x value
	double y;///< y value
	Vec2D(double x = 0, double y = 0); ///< Default Constructor
};

#endif

