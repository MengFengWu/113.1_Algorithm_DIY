CC = g++
CFLAGS = -g

all:
	make A
	make B1
	make B2
A:
	${CC} ${CFLAGS} ./src/A.cpp -o ./bin/A_Greedy
B1:
	${CC} ${CFLAGS} -D BU ./src/B1.cpp -o ./bin/B1_Bottom_Up
	${CC} ${CFLAGS} -D DC ./src/B1.cpp -o ./bin/B1_Divide_And_Conquer
B2:
	${CC} ${CFLAGS} -D DC ./src/B2.cpp -o ./bin/B2_Divide_And_Conquer
	${CC} ${CFLAGS} -D DP ./src/B2.cpp -o ./bin/B2_Dynamic_Programming
B3:
	${CC} ${CFLAGS} ./src/B3.cpp -o ./bin/B3_DP_With_Bitmasking

clean:
	rm -rf ./bin/*