#pragma once 


#include "Piece.h"
#include<string>

class Bishop : public Piece {         
public:

	Bishop() = default;
    ~Bishop() override;
	Bishop(Color color, int size, std::string texturePath, BoardPosition position);

	std::vector<BoardPosition> possibleMoves() override;

private:            

	bool canMoveTo(BoardPosition newPos) override;
};
