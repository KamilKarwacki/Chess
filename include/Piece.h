#pragma once 

#include<SFML/Graphics.hpp>

#include<utility> // std::pair
#include "Color.h"
#include "BoardPosition.h"
#include<vector>
#include<iostream>

class Piece{         
public:
	Piece() = default;
    virtual ~Piece() = default;
    // site of the sprite
	Piece(Color color, int size, std::string TexturePath, BoardPosition position);

	// will return all moves that are possible
	virtual std::vector<BoardPosition> possibleMoves();

	// sets the physical position on the window aswell as the artificial integer position
	void setPosition(BoardPosition pos);
	BoardPosition getPosition() const;
	Color getColor() const;
 
	sf::RectangleShape sprite;
	// did the mouse click on this piece?
	bool isFocused;
protected:
    sf::Texture texture;
	// value for the engine
	int value;
    Color color;
	// current position
	BoardPosition position;

	//sfml sprite holding rectangle and testure
	
	// for a position on the board return if the piece can move to it
	// needs to be overwritten for all pieces
	virtual bool canMoveTo(BoardPosition newPos); // TODO: delete this
};
