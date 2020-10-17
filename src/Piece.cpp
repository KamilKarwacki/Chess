#include "Piece.h" 
#include<iostream>

// CTOR and DTOR -------------------------------

Piece::Piece(Color color, int size, std::string texturePath, BoardPosition position)
    : color(color), isFocused(false)
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
    this->sprite.setPosition(size*position.X - size/2, size*position.Y- size/2);
	// set the pieces position
	this->position = position;
}


// PUBLIC FUNCTIONS ----------------------------------

std::vector<BoardPosition> Piece::possibleMoves()
{}


void Piece::setPosition(BoardPosition pos)
{
    int size = sprite.getSize().x;
    sprite.setPosition(pos.X * size - size/2.f, pos.Y * size - size/2.f);
    position = pos;
}

BoardPosition Piece::getPosition() const
{
    return position;
}

Color Piece::getColor() const
{
    return color;
}

Type Piece::getType() const
{
    return type;
}


// PRIVATE FUNCTIONS ------------------------------------
bool Piece::canMoveTo(BoardPosition newPos)
{}
