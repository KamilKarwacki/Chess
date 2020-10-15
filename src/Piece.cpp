#include "Piece.h" 
#include<iostream>

// CTOR and DTOR -------------------------------

Piece::Piece(Color color, int size, std::string texturePath, std::pair<int, int> position)
    : color(color)
{
	// handle texture stuff 	
	if(!texture.loadFromFile(texturePath))
	{
		std::cout << "A piece could not load the texture from disc" << std::endl;
	}	
	texture.setSmooth(true);
	texture.setRepeated(false);

	this->sprite.setTexture(&texture);
	this->sprite.setSize(sf::Vector2f(size, size));
	this->sprite.setOrigin(size/2, size/2);
    this->sprite.setPosition(size*position.first - size/2, size*position.second - size/2);
	// set the pieces position
	this->position = position;
}


// PUBLIC FUNCTIONS ----------------------------------


std::vector<std::pair<int,int>> Piece::possibleMoves()
{}





// PRIVATE FUNCTIONS ------------------------------------
bool Piece::canMoveTo(std::pair<int,int> newPos)
{}
