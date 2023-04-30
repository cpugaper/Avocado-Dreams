#ifndef __ENEMY_MECH_H__
#define __ENEMY_MECH_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Mech : public Enemy
{
public:
	// Constructor (x y coordinates in the world)
	// Creates animation and movement data and the collider
	Enemy_Mech(int x, int y);

	// The enemy is going to follow the different steps in the path
	// Position will be updated depending on the speed defined at each step
	void Update() override;

	void Attack();

	//Timer to control the enemy attack cooldown
	float timer = 0.0f;
	float SHOOT_INTERVAL = 3;
	int bullet_dir = 0;
private:
	// The path that will define the position in the world
	Path path;

	// Enemy animations
	Animation front, back;
};

#endif // __ENEMY_MECH_H__