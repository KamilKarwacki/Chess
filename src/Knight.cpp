#include "Knight.h"

// CTOR AND DTOR ------------------------------------------
Knight::Knight(Color color, int size, std::string texturePath, std::pair<int, int> position)
        : Piece(color, size, texturePath, position)
{}

Knight::~Knight(){}

// PUBLIC FUNCTIONS -------------------------------------
std::vector<std::pair<int,int>> Knight::possibleMoves()
{

}


// PRIVATE FUNCTIONS ------------------------------------
bool Knight::canMoveTo(std::pair<int,int> newPos)
{

}
