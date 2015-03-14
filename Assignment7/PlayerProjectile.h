#ifndef PLAYER_PROJECTILE_4574846846767
#define PLAYER_PROJECTILE_4574846846767

#include "GameObject.h"

class PlayerProjectile : public GameObject {
public:
	PlayerProjectile(int,int,int);
	static void timeStep(PlayerProjectile*[], int);	/// Move projectile
	static void isCollision(PlayerProjectile*[], int); /// Did the projectile go off screen?
};

#endif