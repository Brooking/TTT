#include "board.h"
#include <cassert>

//
// Lanes for winning
//
static vector<vector<pair<int,int>>> lanes = {
    {{0,0},{0,1},{0,2}},
    {{1,0},{1,1},{1,2}},
    {{2,0},{2,1},{2,2}},
    {{0,0},{1,0},{2,0}},
    {{0,1},{1,1},{2,1}},
    {{0,2},{1,2},{2,2}},
    {{0,0},{1,1},{2,2}},
    {{0,2},{1,1},{2,0}}
};

//
// Standard constructor
//
Board::Board() : grid_(vector<vector<Spot>>(3,vector<Spot>(3,Spot::empty))), 
                 winner_(Spot::empty) {}

//
// Get a spot
//
Spot Board::Get(int row, int cell) {
    if (row < 0 || cell < 0 || row >=3 || cell >= 3) {
        return Spot::empty;
    }
    return this->grid_[row][cell];
}

//
// Set a spot by row + cell
//
bool Board::Set(int row, int cell, Spot spot) {
    if (this->winner_ != Spot::empty) {
        // this game is over
        return false;
    }

    Spot current = Get(row, cell);
    if (current != Spot::empty) {
        // this spot is already taken
        return false;
    }

    this->grid_[row][cell] = spot;
    CheckForWinner();
    return true;
}

//
// Set a spot by location
//
bool Board::Set(int location, Spot spot) {
    return this->Set((location-1)/3, (location-1)%3, spot);
}

//
// Evaluate the board and put conclusions in the class
//
void Board::CheckForWinner() {
    int xwins = 0;
    int owins = 0;
    int blocks = 0;
    assert(this->winner_ == Spot::empty);

    for (auto& lane : lanes) {
        CheckLane(lane, xwins, owins, blocks);
    }

    if (xwins > 0) {
        assert(owins == 0);
        this->winner_ = Spot::X;
    }
    if (owins > 0) {
        this->winner_ = Spot::O;
    }
    if (blocks == 8) {
        this->winner_ = Spot::cat;
    }
}

//
// Check a single row/column/diagonal
//
void Board::CheckLane(vector<pair<int,int>>& lane, int& xwins, int& owins, int& blocks) {
    int xcount = 0;
    int ocount = 0;
    for (int i = 0; i < 3; i++) {
        Spot spot = this->grid_[lane[i].first][lane[i].second];
        if (spot == Spot::X) {
            xcount++;
        } else if (spot == Spot::O) {
            ocount++;
        }
    }
    if (xcount == 3) {
        xwins++;
    } else if (ocount == 3) {
        owins++;
    } else if (xcount > 0 && ocount > 0) {
        blocks++;
    }
}

//
// Print the board
//
string Board::ToString(Format format) {
    string result;
    for (int row = 0; row < 3; row++) {
        result += this->RowToString(row, format);
        if (row < 2) {
            result += "---+---+---\n";
        }
    }

    return result;
}

//
// Print a row
//
string Board::RowToString(int row, Format format) {
    string result;
    result += " ";
    for (int cell = 0; cell < 3; cell++) {
        result += CellToString(row, cell, format);;
        if (cell < 2) {
            result += " | ";
        }
    }
    result += "\n";
    return result;
}

//
// print a cell
//
string Board::CellToString(int row, int cell, Format format) {
    int cellNumber = (row * 3) + cell + 1;
    Spot spot = this->grid_[row][cell];
    switch(spot) {
        case Spot::empty:
            switch (format) {
                case Format::index:
                case Format::both:
                    return to_string(cellNumber);
                case Format::XO:
                case Format::none:
                    return " ";
            }
        case Spot::X:
        case Spot::O:
            switch (format) {
                case Format::XO:
                case Format::both:
                    return (spot == Spot::X)?"X":"O";
                case Format::index:
                case Format::none:
                    return " ";
            }

        default:
            assert(spot != Spot::cat);      
            return string();      
    }

    return string();
}
