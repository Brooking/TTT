#include <iostream>
#include "humanPlayer.h"
using namespace std;


Player* HumanPlayer::Create(Spot spot) {
    return new HumanPlayer(spot);
}

void HumanPlayer::Move(Board& board) {
    bool done = false;
    while (!done) {
        cout << "Human (" << ((this->side == X)?"X":"O") << ") move:";
        int cell;
        cin >> cell;
        done = board.Set(cell, this->side);
    }
}