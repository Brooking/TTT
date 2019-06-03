#include <iostream>
#include <stdlib.h>
using namespace std;

#include "board.h"
#include "player.h"
#include "humanPlayer.h"
#include "computerPlayer.h"

int main() {
    cout << "Tic Tac Toe" << endl;
    Board board;

    vector<Player*> player;
    bool humanFirst = ((rand() % 2) == 0);
    if (humanFirst) {
        player.push_back(HumanPlayer::Create(Spot::X));
        player.push_back(ComputerPlayer::Create(Spot::O));
    } else {
        player.push_back(ComputerPlayer::Create(Spot::X));
        player.push_back(HumanPlayer::Create(Spot::O));
    }

    int current = 0;
    while(board.Winner() == Spot::empty) {
        cout << endl;
        cout << board.ToString(Format::both);
        player[current]->Move(board);
        current++;
        current %= 2;
    }

    for (auto& p : player) {
        delete p;
    }

    cout << board.ToString(Format::XO);
    if (board.Winner() == Spot::cat) {
        cout << "cat game" << endl;
    } else {
        cout << board.Winner() << " wins!" << endl;
    }
}