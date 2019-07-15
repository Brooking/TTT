#include <iostream>
#include "computerPlayer.h"
using namespace std;

iPlayer* ComputerPlayer::Create(Spot spot) {
    return new ComputerPlayer(spot);
}

void ComputerPlayer::Move(Board& board) {
    // the computer is stupid for now...putting its mark in the first open slot
    for (int i = 1; i < 10; i++) {
        if (board.Set(i, this->side)) {
            cout << "Computer (" << ((this->side == X)?"X":"O") << ") moves:" << i << endl;            
            return;
        }
    }
}