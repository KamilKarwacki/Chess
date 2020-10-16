#include "Knight.h"

// CTOR AND DTOR ------------------------------------------
Knight::Knight(Color color, int size, std::string texturePath, BoardPosition position)
        : Piece(color, size, texturePath, position)
{}

Knight::~Knight(){}

// PUBLIC FUNCTIONS -------------------------------------
std::vector<BoardPosition> Knight::possibleMoves()
{
    int X = position.X;
    int Y = position.Y;

    // declare all possible increments that can be done for a knight
    std::vector<BoardPosition> increments{{1,2}, {1,-2}, {2,1}, {2,-1},
                                          {-1,2}, {-1,-2}, {-2,1}, {-2,-1}};

    std::vector<BoardPosition> result;

     for(const auto& inc : increments)
     {
         // if the new point is inside the board
         if(X + inc.X > 0 and X + inc.X < 9 and Y + inc.Y > 0 and Y + inc.Y < 9)
             result.push_back(BoardPosition(X + inc.X, Y + inc.Y));
     }
     return result;
}


// PRIVATE FUNCTIONS ------------------------------------
bool Knight::canMoveTo(BoardPosition newPos)
{

}
