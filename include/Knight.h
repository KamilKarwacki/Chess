#pragma once 

#include<SFML/Graphics.hpp>

#include "Piece.h"
#include "Color.h"
#include<string>
#include<utility>

class Knight : public Piece{
public:

    Knight() = default;
    ~Knight() override;
    Knight(Color color, int size, std::string texturePath, BoardPosition position);

    std::vector<BoardPosition> possibleMoves() override;

private:

    bool canMoveTo(BoardPosition newPos) override;

};