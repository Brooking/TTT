#ifndef _HUMANPLAYER_H_
#define _HUMANPLAYER_H_

#include "iplayer.h"

class HumanPlayer : iPlayer {
public:
    void Move(Board& board) override;
    string Name() override {return "Human";}
    Spot GetSpot() override {return this->side;}

    static iPlayer* Create(Spot spot);

private:
    HumanPlayer(Spot spot) : side(spot) {}

private:
    Spot side;
};
#endif // _HUMANPLAYER_H_