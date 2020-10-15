#include "King.h"

// CTOR AND DTOR ------------------------------------------
King::King(Color color, int size, std::string texturePath, std::pair<int, int> position)
        : Piece(color, size, texturePath, position)
{}

King::~King(){}

// PUBLIC FUNCTIONS -------------------------------------
std::vector<std::pair<int,int>> King::possibleMoves()
{

}


// PRIVATE FUNCTIONS ------------------------------------
bool King::canMoveTo(std::pair<int,int> newPos)
{

}
