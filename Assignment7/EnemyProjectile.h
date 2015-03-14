#ifndef ENEMY_PROJECTILE_5857573636343
#define ENEMY_PROJECTILE_5857573636343

#include "GameObject.h"
#include "PlayerShip.h"
#include "PlayerProjectile.h"

class EnemyProjectile : public GameObject {
public:
	EnemyProjectile(int,int,int);
	static void timeStep(EnemyProjectile*[], int, int);
	static bool isCollision(EnemyProjectile*[], PlayerShip*, int);
};

#endif