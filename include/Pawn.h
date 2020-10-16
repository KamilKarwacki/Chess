#pragma once 

#include<SFML/Graphics.hpp>

#include "Piece.h"
#include "Color.h"
#include<string>
#include<utility>

class Pawn : public Piece {
public:
    Pawn() = default;
    ~Pawn() override;
    Pawn(Color color, int size, std::string texturePath, BoardPosition position);

    std::vector<BoardPosition> possibleMoves() override;

private:

    bool canMoveTo(BoardPosition newPos) override;

};
