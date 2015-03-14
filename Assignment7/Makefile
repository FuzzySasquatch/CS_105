
CC = g++ -g -O0
LIBS = -lncurses

all: main.o GameObject.o PlayerShip.o EnemyShip.o PlayerProjectile.o EnemyProjectile.o
	${CC} main.cpp GameObject.cpp PlayerShip.cpp EnemyShip.cpp PlayerProjectile.cpp EnemyProjectile.cpp ${LIBS}


clean:
	rm *.o
	rm a.out
	rm -rf a.out.dSYM
