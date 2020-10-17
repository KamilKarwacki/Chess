#include "King.h"

// CTOR AND DTOR ------------------------------------------
King::King(Color color, int size, std::string texturePath, BoardPosition position)
        : Piece(color, size, texturePath, position)
{
    type = Type::KING; // cant be done in initializer list I think, dont want to change piece constructor
}

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
    result.emplace_back(lesserX, Y);
    result.emplace_back(lesserX, lesserY);
    result.emplace_back(lesserX, biggerY);
    result.emplace_back(X, lesserY);
    result.emplace_back(X, biggerY);
    result.emplace_back(biggerX, Y);
    result.emplace_back(biggerX, lesserY);
    result.emplace_back(biggerX, biggerY);

    return result;
}


// PRIVATE FUNCTIONS ------------------------------------
bool King::canMoveTo(BoardPosition newPos)
{

}
