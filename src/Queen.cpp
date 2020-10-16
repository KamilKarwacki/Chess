#include "Queen.h"

// CTOR AND DTOR ------------------------------------------
Queen::Queen(Color color, int size, std::string texturePath, BoardPosition position)
        : Piece(color, size, texturePath, position)
{}

Queen::~Queen(){}

// PUBLIC FUNCTIONS -------------------------------------
std::vector<BoardPosition> Queen::possibleMoves()
{
    int X = position.X;
    int Y = position.Y;
    std::vector<BoardPosition> result;
    return result;

}


// PRIVATE FUNCTIONS ------------------------------------
bool Queen::canMoveTo(BoardPosition newPos)
{

}
