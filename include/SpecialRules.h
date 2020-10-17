#pragma once

#include <vector>
#include "BoardPosition.h"
#include "Piece.h"
#include "Color.h"


// this class applies different rules to figure out other possible moves
class SpecialRules {         
public:

   static void ApplyAllRules(const std::vector<std::pair<BoardPosition, Color>>& boardConfig, const Piece& piece,
                             std::vector<BoardPosition>& possibleMoves);
   static void SetEnPassantSquare(BoardPosition square);
   static BoardPosition GetEnPassantSquare();

   static void EnPassant(const std::vector<std::pair<BoardPosition, Color>>& boardConfig, const Piece& piece,
            std::vector<BoardPosition>& possibleMoves);
   static void Castle(const std::vector<std::pair<BoardPosition, Color>>& boardConfig, const Piece& piece,
            std::vector<BoardPosition>& possibleMoves);
   static void PawnHit(const std::vector<std::pair<BoardPosition, Color>>& boardConfig, const Piece& piece,
            std::vector<BoardPosition>& possibleMoves);

private:
    static BoardPosition EnPassantSquare;
    static std::pair<bool, bool> KingMoved;
};

