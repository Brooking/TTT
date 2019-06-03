#ifndef _HUMANPLAYER_H_
#define _HUMANPLAYER_H_

#include "player.h"

class HumanPlayer : Player {
public:
    void Move(Board& board) override;
    string Name() override {return "Human";}

    static Player* Create(Spot spot);

private:
    HumanPlayer(Spot spot) : side(spot) {}

private:
    Spot side;
};
#endif // _HUMANPLAYER_H_