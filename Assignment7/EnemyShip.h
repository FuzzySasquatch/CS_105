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
	static int movements;
	static int direction;
	static int moveDown;
	static int uFireRate;
	static int WFireRate;
public:
	EnemyShip(int,int,int);
	static void timeStep(int*, EnemyShip*[], int, EnemyProjectile*[], int*); // logic when the time increments
	static bool isCollision(EnemyShip*[], PlayerShip*, int, PlayerProjectile*, int*);
};

#endif