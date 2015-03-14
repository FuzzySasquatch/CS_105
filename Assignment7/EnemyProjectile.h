#ifndef ENEMY_PROJECTILE_5857573636343
#define ENEMY_PROJECTILE_5857573636343

#include "Projectile.h"

class EnemyProjectile : public Projectile {
public:
	EnemyProjectile(int,int,int);
	static void timeStep(EnemyProjectile*[], int);	
};

#endif