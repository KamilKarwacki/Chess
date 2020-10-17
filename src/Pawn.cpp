#include "Pawn.h"

// CTOR AND DTOR ------------------------------------------
Pawn::Pawn(Color color, int size, std::string texturePath, BoardPosition position)
        : Piece(color, size, texturePath, position)
{
    type = Type::PAWN; // cant be done in initializer list I think, dont want to change piece constructor
}

Pawn::~Pawn(){}

// PUBLIC FUNCTIONS -------------------------------------
std::vector<BoardPosition> Pawn::possibleMoves()
{
    int X = position.X;
    int Y = position.Y;
    std::vector<BoardPosition> result;

    if(color == Color::WHITE)
    {
        result.emplace_back(X, Y+1);
        if(Y == 2)
            result.emplace_back(X, Y+2);

    } else{
        result.emplace_back(X, Y-1);
        if(Y == 7)
            result.emplace_back(X, Y-2);
    }
    return result;
}

// PRIVATE FUNCTIONS ------------------------------------
bool Pawn::canMoveTo(BoardPosition newPos)
{

}
