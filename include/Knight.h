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
    Knight(Color color, int size, std::string texturePath, std::pair<int, int> position);

    std::vector<std::pair<int,int>> possibleMoves() override;

private:

    bool canMoveTo(std::pair<int,int> newPos) override;

};