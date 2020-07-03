#pragma once 

#include<SFML/Graphics.hpp>

#include<utility> // std::pair
#include<vector>
#include<iostream>

class Piece{         
public:
	Piece() = default;
	// site of the sprite
	Piece(int size, std::string TexturePath, std::pair<int,int> position);
	virtual ~Piece();	

	// will return all moves that are possible
	virtual std::vector<std::pair<int,int>> possibleMoves();
 
	sf::RectangleShape sprite;
	sf::Texture texture;
private:            
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
