#ifndef ENEMY_SHIP_0000433191238374
#define ENEMY_SHIP_0000433191238374

#include "GameObject.h"
#include "EnemyProjectile.h"
#include "PlayerShip.h"
#include "PlayerProjectile.h"

class PlayerProjectile;
class EnemyProjectile;

class EnemyShip : public GameObject {
private:
	/// Deals with movement
	static int movements;
	static int totalMovements;
	static int direction;
	static int moveDown;
	static int movementSpeed;

	/// Firerate
	static int uFireRate;
	static int WFireRate;
public:
	EnemyShip(int,int,int);
	static void timeStep(int*, EnemyShip*[], int, EnemyProjectile*[], int*); /// logic when the time increments
	static bool isCollision(EnemyShip*[], int, PlayerProjectile*, int*, bool*); /// Player projectile collisions
	static bool isCollision(EnemyShip*[], PlayerShip*, int); /// Base/Player collisions
};

#endif