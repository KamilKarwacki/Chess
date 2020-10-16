#include "Pawn.h"

// CTOR AND DTOR ------------------------------------------
Pawn::Pawn(Color color, int size, std::string texturePath, BoardPosition position)
        : Piece(color, size, texturePath, position)
{}

Pawn::~Pawn(){}

// PUBLIC FUNCTIONS -------------------------------------
std::vector<BoardPosition> Pawn::possibleMoves()
{
    int X = position.X;
    int Y = position.Y;
    std::vector<BoardPosition> result;

    if(color == Color::WHITE)
    {
        result.push_back(BoardPosition(X, Y+1));
        if(Y == 2)
            result.push_back(BoardPosition(X, Y+2));

    } else{
        result.push_back(BoardPosition(X, Y-1));
        if(Y == 7)
            result.push_back(BoardPosition(X, Y-2));
    }
    return result;
}

// PRIVATE FUNCTIONS ------------------------------------
bool Pawn::canMoveTo(BoardPosition newPos)
{

}
