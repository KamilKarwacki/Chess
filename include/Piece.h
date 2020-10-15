#pragma once 

#include<SFML/Graphics.hpp>

#include<utility> // std::pair
#include "Color.h"
#include<vector>
#include<iostream>

class Piece{         
public:
	Piece() = default;
    virtual ~Piece() = default;
    // site of the sprite
	Piece(Color color, int size, std::string TexturePath, std::pair<int,int> position);

	// will return all moves that are possible
	virtual std::vector<std::pair<int,int>> possibleMoves();
 
	sf::RectangleShape sprite;
	Color color;
private:
    sf::Texture texture;
	// did the mouse click on this piece?
	bool isFocused;
	// value for the engine
	int value;
	// current position
	std::pair<int,int> position;

	//sfml sprite holding rectangle and testure
	
	// for a position on the board return if the piece can move to it
	// needs to be overwritten for all pieces
	virtual bool canMoveTo(std::pair<int,int> newPos);
};
