#pragma once 

#include<SFML/Graphics.hpp>

#include "Piece.h"
#include<string>
#include<utility>

class Bishop : public Piece {         
public:

	Bishop() = default;
	Bishop(int size, std::string texturePath, std::pair<int, int> position);
	~Bishop();

	std::vector<std::pair<int,int>> possibleMoves() override;

private:            

	bool canMoveTo(std::pair<int,int> newPos) override;
};
