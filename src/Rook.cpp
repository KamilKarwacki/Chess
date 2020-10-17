#include "Rook.h"

// CTOR AND DTOR ------------------------------------------
Rook::Rook(Color color, int size, std::string texturePath, BoardPosition position)
        : Piece(color, size, texturePath, position)
{
    type = Type::ROOK;
}

Rook::~Rook(){}

// PUBLIC FUNCTIONS -------------------------------------
std::vector<BoardPosition> Rook::possibleMoves()
{
    int X = position.X;
    int Y = position.Y;
    std::vector<BoardPosition> result;

    // go over all x directions
    for(int x = 1; x < 9; x++)
    {
        if(x == X)
            continue;
        result.emplace_back(x,Y);
    }

    // go over all Y directions
    for(int y = 1; y < 9; y++)
    {
        if(y == Y)
            continue;
        result.emplace_back(X,y);
    }

    return result;
}


// PRIVATE FUNCTIONS ------------------------------------
bool Rook::canMoveTo(BoardPosition newPos)
{

}
