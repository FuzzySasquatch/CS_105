
CC = g++ -g -O0
LIBS = -lncurses

all: main.o GameObject.o Ship.o PlayerShip.o EnemyShip.o Projectile.o PlayerProjectile.o 
	${CC} main.cpp GameObject.cpp Ship.cpp PlayerShip.cpp EnemyShip.cpp Projectile.cpp PlayerProjectile.cpp ${LIBS}


clean:
	rm *.o
	rm a.out
	rm -rf a.out.dSYM
