#ifndef _board_h_
#define _board_h_

#include <vector>
#include <string>
using namespace std;

//
// Spot ownership (or game resolution)
// 
enum Spot {
    empty,
    X,
    O,
    cat // only used for determining winner
};

//
// How to format the matrix
//
enum Format {
    none,
    XO,
    index,
    both
};

//
// The gameboard
//
class Board {
public:
    Board();
    Spot Get(int row, int cell);
    bool Set(int row, int cell, Spot spot);
    Spot Winner() {return this->winner_;}
    string ToString(Format format);

private:
    void CheckForWinner();
    void CheckLane(vector<pair<int,int>>& lane, int& xwins, int& owins, int& blocks);
    string RowToString(int i, Format format);
    string CellToString(int row, int cell, Format format);

private:
    vector<vector<Spot>> grid_;
    Spot winner_;
};

#endif // _board_h_