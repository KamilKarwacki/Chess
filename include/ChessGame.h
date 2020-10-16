#pragma once 

#include "Board.h"
#include "Piece.h"
#include "Color.h"
#include "BoardPosition.h"

// implements game logic, used the board to get all piece locations and other info
class ChessGame {         
public:

    void onLeftClick(Board& board, int x, int y);
    void onLeftClickReleased(Board& board);
         
private:
    // returns true if the square can be moved to, deletes the enemies piece if needed
    bool handleAlreadyUsedSquares(Board& board, std::pair<BoardPosition, Color> piece);

    bool isSomePieceGrabbed = false;
    Color turn = Color::WHITE;

};