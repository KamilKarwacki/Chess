#include "Rook.h"

// CTOR AND DTOR ------------------------------------------
Rook::Rook(Color color, int size, std::string texturePath, std::pair<int, int> position)
        : Piece(color, size, texturePath, position)
{}

Rook::~Rook(){}

// PUBLIC FUNCTIONS -------------------------------------
std::vector<std::pair<int,int>> Rook::possibleMoves()
{

}


// PRIVATE FUNCTIONS ------------------------------------
bool Rook::canMoveTo(std::pair<int,int> newPos)
{

}
