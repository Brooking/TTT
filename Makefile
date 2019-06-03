CC=g++
CFLAGS=-Wall -ggdb3

all : ut_board.out

ut_board.out : board.h board.cpp ut_board.cpp
	$(CC) $(CFLAGS) -o ut_board.out board.cpp ut_board.cpp