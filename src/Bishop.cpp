#include "Bishop.h"

#include<SFML/Graphics.hpp>

// CTOR AND DTOR ------------------------------------------
Bishop::Bishop(Color color, int size, std::string texturePath, BoardPosition position)
	: Piece(color, size, texturePath, position)
{
   type = Type::BISHOP; // cant be done in initializer list I think, dont want to change piece constructor
}

Bishop::~Bishop(){}

// PUBLIC FUNCTIONS -------------------------------------
std::vector<BoardPosition> Bishop::possibleMoves()
{
    int X = position.X;
    int Y = position.Y;
    std::vector<BoardPosition> result;

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
bool Bishop::canMoveTo(BoardPosition newPos)
{

}
