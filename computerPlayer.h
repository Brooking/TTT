#ifndef _COMPUTERPLAYER_H_
#define _COMPUTERPLAYER_H_

#include "player.h"

class ComputerPlayer : Player {
public:
    void Move(Board& board) override;
    string Name() override {return "Computer";}

    static Player* Create(Spot spot);

private:
    ComputerPlayer(Spot spot) : side(spot) {}

private:
    Spot side;
};
#endif // _COMPUTERPLAYER_H_