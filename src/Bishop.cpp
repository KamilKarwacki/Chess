#include "Bishop.h" 

// CTOR AND DTOR ------------------------------------------
Bishop::Bishop(Color color, int size, std::string texturePath, BoardPosition position)
	: Piece(color, size, texturePath, position)
{}

Bishop::~Bishop(){}

// PUBLIC FUNCTIONS -------------------------------------
std::vector<BoardPosition> Bishop::possibleMoves()
{
    int X = position.X;
    int Y = position.Y;
    std::vector<BoardPosition> result;

    return result;
}


// PRIVATE FUNCTIONS ------------------------------------
bool Bishop::canMoveTo(BoardPosition newPos)
{

}
