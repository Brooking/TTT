#ifndef _COMPUTERPLAYER_H_
#define _COMPUTERPLAYER_H_

#include "iplayer.h"

class ComputerPlayer : iPlayer {
public:
    void Move(Board& board) override;
    string Name() override {return "Computer";}
    Spot GetSpot() override {return this->side;}

    static iPlayer* Create(Spot spot);

private:
    ComputerPlayer(Spot spot) : side(spot) {}

private:
    Spot side;
};
#endif // _COMPUTERPLAYER_H_