#include "Pawn.h"

// CTOR AND DTOR ------------------------------------------
Pawn::Pawn(Color color, int size, std::string texturePath, std::pair<int, int> position)
        : Piece(color, size, texturePath, position)
{}

Pawn::~Pawn(){}

// PUBLIC FUNCTIONS -------------------------------------
std::vector<std::pair<int,int>> Pawn::possibleMoves()
{

}

// PRIVATE FUNCTIONS ------------------------------------
bool Pawn::canMoveTo(std::pair<int,int> newPos)
{

}
