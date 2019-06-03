CC=g++
CFLAGS=-Wall -ggdb3

all : ut_board.out game.out

ut_board.out : board.h board.cpp ut_board.cpp
	$(CC) $(CFLAGS) -o ut_board.out board.cpp ut_board.cpp

game.out : game.cpp board.h board.cpp player.h computerPlayer.h computerPlayer.cpp humanPlayer.h humanPlayer.cpp
	$(CC) $(CFLAGS) -o game.out game.cpp board.cpp computerPlayer.cpp humanPlayer.cpp
