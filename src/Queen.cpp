#include "Queen.h"

// CTOR AND DTOR ------------------------------------------
Queen::Queen(Color color, int size, std::string texturePath, std::pair<int, int> position)
        : Piece(color, size, texturePath, position)
{}

Queen::~Queen(){}

// PUBLIC FUNCTIONS -------------------------------------
std::vector<std::pair<int,int>> Queen::possibleMoves()
{

}


// PRIVATE FUNCTIONS ------------------------------------
bool Queen::canMoveTo(std::pair<int,int> newPos)
{

}
