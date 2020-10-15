#include "Bishop.h" 

// CTOR AND DTOR ------------------------------------------
Bishop::Bishop(Color color, int size, std::string texturePath, std::pair<int, int> position)
	: Piece(color, size, texturePath, position)
{}

Bishop::~Bishop(){}

// PUBLIC FUNCTIONS -------------------------------------
std::vector<std::pair<int,int>> Bishop::possibleMoves()
{

}


// PRIVATE FUNCTIONS ------------------------------------
bool Bishop::canMoveTo(std::pair<int,int> newPos)
{

}
