#ifndef PLAYER_PROJECTILE_4574846846767
#define PLAYER_PROJECTILE_4574846846767

#include "Projectile.h"

class PlayerProjectile : public Projectile {
public:
	PlayerProjectile(int,int,int);
	static void timeStep(PlayerProjectile*[], int);	
};

#endif