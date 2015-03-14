#ifndef ENEMY_PROJECTILE_5857573636343
#define ENEMY_PROJECTILE_5857573636343

#include "GameObject.h"

class EnemyProjectile : public GameObject {
public:
	EnemyProjectile(int,int,int);
	static void timeStep(EnemyProjectile*[], int, int);
};

#endif