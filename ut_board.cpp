#include "board.h"
#include <cassert>
#include <iostream>
using namespace std;

#define bassert(condition) {bool _c=(condition);if (!(_c)) {cout << board.ToString(Format::XO) << endl; cout << "(" << #condition << ") is false!" << endl; assert(_c);}}

//
// Empty board
//
void Construct() {
    Board board;

    bassert(board.Winner() == Spot::empty);
    bassert(board.Get(0,0) == Spot::empty);
    bassert(board.Get(0,1) == Spot::empty);
    bassert(board.Get(0,2) == Spot::empty);
    bassert(board.Get(1,0) == Spot::empty);
    bassert(board.Get(1,1) == Spot::empty);
    bassert(board.Get(1,2) == Spot::empty);
    bassert(board.Get(2,0) == Spot::empty);
    bassert(board.Get(2,1) == Spot::empty);
    bassert(board.Get(2,2) == Spot::empty);
}

//
// set + get + no reset
//
void SetGet() {
    Board board;

    bassert(board.Set(1,1,Spot::O));
    bassert(board.Set(2,1,Spot::X) == true);

    bassert(board.Winner() == Spot::empty);
    bassert(board.Get(0,0) == Spot::empty);
    bassert(board.Get(0,1) == Spot::empty);
    bassert(board.Get(0,2) == Spot::empty);
    bassert(board.Get(1,0) == Spot::empty);
    bassert(board.Get(1,1) == Spot::O);
    bassert(board.Get(1,2) == Spot::empty);
    bassert(board.Get(2,0) == Spot::empty);
    bassert(board.Get(2,1) == Spot::X);
    bassert(board.Get(2,2) == Spot::empty);

    bassert(board.Set(1,1,Spot::X) == false);
    bassert(board.Get(1,1) == Spot::O);
}

//
// set using location
//
void SetLocation() {
    Board board;

    bassert(board.Set(5,Spot::O));
    bassert(board.Set(1,1,Spot::X) == false);
    bassert(board.Get(1,1) == Spot::O);
}

//
// winning!
//
void Wins() {
    Board board;

    //  O | X |  
    // ---+---+---
    //  X | O | X 
    // ---+---+---
    //    |   | O
    bassert(board.Set(2,1,Spot::X));
    bassert(board.Set(0,0,Spot::O));
    bassert(board.Set(0,1,Spot::X));
    bassert(board.Set(1,1,Spot::O));
    bassert(board.Set(1,0,Spot::X));
    bassert(board.Set(2,2,Spot::O));

    bassert(board.Winner() == Spot::O);
}

//
// both lose
//
void Cats() {
    Board board;

    //  O | X | O
    // ---+---+---
    //    | O | X 
    // ---+---+---
    //  X | O | X
    bassert(board.Set(0,1,Spot::X));
    bassert(board.Set(0,0,Spot::O));
    bassert(board.Set(2,0,Spot::X));
    bassert(board.Set(0,2,Spot::O));
    bassert(board.Set(1,2,Spot::X));
    bassert(board.Set(1,1,Spot::O));
    bassert(board.Set(2,2,Spot::X));
    bassert(board.Winner() == Spot::empty);
    bassert(board.Set(2,1,Spot::O));

    bassert(board.Winner() == Spot::cat);
}

void ToString() {
    Board board;

    //  X | O |  
    // ---+---+---
    //  X | O | X 
    // ---+---+---
    //    |   | O
    bassert(board.Set(0,0,Spot::X));
    bassert(board.Set(0,1,Spot::O));
    bassert(board.Set(1,0,Spot::X));
    bassert(board.Set(1,1,Spot::O));
    bassert(board.Set(1,2,Spot::X));
    bassert(board.Set(2,2,Spot::O));

    string noneString = board.ToString(Format::none);
    assert(noneString == "   |   |  \n---+---+---\n   |   |  \n---+---+---\n   |   |  \n");
    string indexString = board.ToString(Format::index);
    assert(indexString == "   |   | 3\n---+---+---\n   |   |  \n---+---+---\n 7 | 8 |  \n");
    string xoString = board.ToString(Format::XO);
    assert(xoString == " X | O |  \n---+---+---\n X | O | X\n---+---+---\n   |   | O\n");
    string bothString = board.ToString(Format::both);
    assert(bothString == " X | O | 3\n---+---+---\n X | O | X\n---+---+---\n 7 | 8 | O\n");
}

int main() {
    Construct();
    SetGet();
    SetLocation();
    Wins();
    Cats();
    ToString();
    cout << "All tests completed successfully" << endl;
}