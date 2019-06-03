#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "board.h"

class Player {
public:    
    Player() {}
    virtual ~Player() {}
    virtual void Move(Board& board) = 0;
    virtual string Name() = 0;
};

#endif // _PLAYER_H_