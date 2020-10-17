#include "Queen.h"

// CTOR AND DTOR ------------------------------------------
Queen::Queen(Color color, int size, std::string texturePath, BoardPosition position)
        : Piece(color, size, texturePath, position)
{
    type = Type::QUEEN; // cant be done in initializer list I think, dont want to change piece constructor
}

Queen::~Queen(){}

// PUBLIC FUNCTIONS -------------------------------------
std::vector<BoardPosition> Queen::possibleMoves()
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


    while(X + 1 < 9 and Y + 1 < 9)
    {
        result.emplace_back(++X, ++Y);
    }
    X = position.X;
    Y = position.Y;

    while(X - 1 > 0 and Y - 1 > 0)
    {
        result.emplace_back(--X, --Y);
    }
    X = position.X;
    Y = position.Y;

    while(X + 1 < 9 and Y - 1 > 0)
    {
        result.emplace_back(++X, --Y);
    }
    X = position.X;
    Y = position.Y;

    while(X - 1 > 0 and Y + 1 < 9)
    {
        result.emplace_back(--X, ++Y);
    }
    X = position.X;
    Y = position.Y;

    return result;

}


// PRIVATE FUNCTIONS ------------------------------------
bool Queen::canMoveTo(BoardPosition newPos)
{

}
