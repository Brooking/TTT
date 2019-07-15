#ifndef _IPLAYER_H_
#define _IPLAYER_H_

#include "board.h"

class iPlayer {
public:    
    iPlayer() {}
    virtual ~iPlayer() {}
    virtual void Move(Board& board) = 0;
    virtual string Name() = 0;
    virtual Spot GetSpot() = 0;
};

#endif // _IPLAYER_H_