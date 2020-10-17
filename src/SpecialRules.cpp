#include "SpecialRules.h"


BoardPosition SpecialRules::EnPassantSquare = {0,0};
std::pair<bool, bool> SpecialRules::KingMoved = std::make_pair<bool, bool>(false, false);

void SpecialRules::ApplyAllRules(const std::vector<std::pair<BoardPosition, Color>>& boardConfig, const Piece& piece,
                          std::vector<BoardPosition>& possibleMoves)
{
    SpecialRules::EnPassant(boardConfig, piece, possibleMoves);
    SpecialRules::PawnHit(boardConfig, piece, possibleMoves);
    SpecialRules::Castle(boardConfig, piece, possibleMoves);
}

void SpecialRules::SetEnPassantSquare(BoardPosition square)
{
    EnPassantSquare = square;
}

BoardPosition SpecialRules::GetEnPassantSquare()
{
    return EnPassantSquare;
}

void SpecialRules::EnPassant(const std::vector<std::pair<BoardPosition, Color>>& boardConfig,const Piece& piece, std::vector<BoardPosition>& possibleMoves)
{
    if(piece.getType() != Type::PAWN)
        return;
}

// this will turn out ugly cause I dont know a nice way to figure out if a square is empty
void SpecialRules::Castle(const std::vector<std::pair<BoardPosition, Color>>& boardConfig, const Piece& piece, std::vector<BoardPosition>& possibleMoves)
{
    if(piece.getType() != Type::KING)
    {
        if(piece.getColor() == Color::BLACK and piece.getPosition() == BoardPosition(4,8))
        {

            std::find(possibleMoves.begin(), possibleMoves.end(), BoardPosition(5,8));
            std::find(possibleMoves.begin(), possibleMoves.end(), BoardPosition(5,8));
            std::find(possibleMoves.begin(), possibleMoves.end(), BoardPosition(5,8));
        }else
        {

        }
    }

}

void SpecialRules::PawnHit(const std::vector<std::pair<BoardPosition, Color>>& boardConfig, const Piece& piece, std::vector<BoardPosition>& possibleMoves)
{
    if(piece.getType() != Type::PAWN) // only consider pawns
        return;

    BoardPosition PossibleHit1{};
    BoardPosition PossibleHit2{};

    if(piece.getColor() == Color::WHITE)
    {
        PossibleHit1 = {piece.getPosition().X + 1, piece.getPosition().Y + 1};
        PossibleHit2 = {piece.getPosition().X - 1, piece.getPosition().Y + 1};
    }
    else
    {
        PossibleHit1 = {piece.getPosition().X + 1, piece.getPosition().Y - 1};
        PossibleHit2 = {piece.getPosition().X - 1, piece.getPosition().Y - 1};
    }

    for(const auto& p : boardConfig)
    {
        if(p.second != piece.getColor())  // consider only other colored pieces
        {
            if(p.first == PossibleHit1)
                possibleMoves.emplace_back(PossibleHit1.X, PossibleHit1.Y);

            if(p.first == PossibleHit2)
                possibleMoves.emplace_back(PossibleHit2.X, PossibleHit2.Y);
        }
    }
}
