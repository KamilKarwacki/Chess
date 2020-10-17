#include "ChessGame.h"
#include "SpecialRules.h"

#include <algorithm>

// PUBLIC FUNCTIONS -------------------------------------

void ChessGame::onLeftClick(Board& board, int x, int y)
{
    auto pred = [&](auto& p) // we will search for the piece which is hit by the mouse
    {
        return p->sprite.getGlobalBounds().contains(x,y) and (!isSomePieceGrabbed or p->isFocused);
    };
    auto piece = std::find_if(board.pieces.begin(), board.pieces.end(), pred);
    if(piece == board.pieces.end())
        return;

    std::shared_ptr<Piece> selectedPiece = *piece;

    if(selectedPiece->getColor() == turn) {
        selectedPiece->sprite.setPosition(x, y);
        selectedPiece->isFocused = true; // why is this grayed out CAUTION
        isSomePieceGrabbed = true;
    }
}

void ChessGame::onLeftClickReleased(Board& board)
{
    // gets the iterator of the piece which is selected
    auto pieceIt = std::find_if(board.pieces.begin(), board.pieces.end(), [](auto& p){return p->isFocused;});
    if(pieceIt == board.pieces.end())
        return;

    std::shared_ptr<Piece> selectedPiece = *pieceIt; // declare it as a variable to use it later in the code

    BoardPosition newPos = board.getBoardCoordinatesOfPiece(*selectedPiece);
    std::vector<BoardPosition> moves = selectedPiece->possibleMoves();
    SpecialRules::ApplyAllRules(board.getBoardConfiguration(), *selectedPiece, moves);
    if (std::find(moves.begin(), moves.end(), newPos) !=
        moves.end()) // only if its actually a valid move we set the new position
    {
        if (handleAlreadyUsedSquares(board, std::make_pair<BoardPosition, Color>(BoardPosition(newPos),
                                                                                 selectedPiece->getColor()))) {
            selectedPiece->setPosition(newPos);
            turn = (turn == Color::WHITE ? Color::BLACK : Color::WHITE);
        } else{
            selectedPiece->setPosition(selectedPiece->getPosition());
        }

    } else // sets its own position to its stored position which is the last position
        selectedPiece->setPosition(selectedPiece->getPosition());

    selectedPiece->isFocused = false;
    isSomePieceGrabbed = false;
}

// PRIVATE FUNCTIONS ------------------------------------

bool ChessGame::handleAlreadyUsedSquares(Board& board, std::pair<BoardPosition, Color> posColor)
{
    auto boardConfig = board.getBoardConfiguration();

    for(auto& piece : boardConfig)
    {
        if(piece.first == posColor.first)
        {
            if(piece.second == posColor.second)
            {
                return false;
            }else
            {
                board.deletePieceAt(posColor.first);
                return true;
            }
        }
    }
    return true;
}



