#pragma once 

#include<SFML/Graphics.hpp>

#include "Piece.h"
#include<string>
#include<utility>

class Bishop : public Piece {         
public:

	Bishop() = default;
    ~Bishop() override;
	Bishop(Color color, int size, std::string texturePath, BoardPosition position);

	std::vector<BoardPosition> possibleMoves() override;

private:            

	bool canMoveTo(BoardPosition newPos) override;
};
