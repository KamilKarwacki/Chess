#include "King.h"

// CTOR AND DTOR ------------------------------------------
King::King(Color color, int size, std::string texturePath, BoardPosition position)
        : Piece(color, size, texturePath, position)
{}

King::~King(){}

// PUBLIC FUNCTIONS -------------------------------------
std::vector<BoardPosition> King::possibleMoves()
{
    int X = position.X;
    int Y = position.Y;

    int lesserX = (X == 1 ? 1 : X - 1);
    int lesserY = (Y == 1 ? 1 : Y - 1);
    int biggerX = (X == 8 ? 8 : X + 1);
    int biggerY = (Y == 8 ? 8 : Y + 1);

    // fill vector with all possible new positions, CAUTION: duplicates can occur maybe use a set
    std::vector<BoardPosition> result;
    result.push_back(BoardPosition({lesserX, Y}));
    result.push_back(BoardPosition({lesserX, lesserY}));
    result.push_back(BoardPosition({lesserX, biggerY}));
    result.push_back(BoardPosition({X, lesserY}));
    result.push_back(BoardPosition({X, biggerY}));
    result.push_back(BoardPosition({biggerX, Y}));
    result.push_back(BoardPosition({biggerX, lesserY}));
    result.push_back(BoardPosition({biggerX, biggerY}));

    return result;
}


// PRIVATE FUNCTIONS ------------------------------------
bool King::canMoveTo(BoardPosition newPos)
{

}
