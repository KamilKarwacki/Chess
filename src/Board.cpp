#include "Board.h" 
#include <iostream>


// CTOR AND DTOR -------------------------------------------------------
Board::Board(int cellSize, std::string texturePath) 
		: cellSize(cellSize), boardSize(cellSize*8)
{
		
	// handle texture stuff 	
	if(!texture.loadFromFile(texturePath))
	{
		std::cout << "The Board could not load the texture from disc" << std::endl;
	}	
	texture.setSmooth(true);
	texture.setRepeated(false);

	// bind texture
	this->sprite.setTexture(&texture);
	this->sprite.setSize(sf::Vector2f(cellSize*8,cellSize*8));
	//this->sprite.setScale(cellSize/10.f,cellSize/10.f);
	// set origin to middle
	this->sprite.setOrigin(this->sprite.getTextureRect().width/2,
				   	this->sprite.getTextureRect().height/2);
	// move board so upper left corner matches with window
	this->sprite.move(this->sprite.getTextureRect().width/2,
				   	this->sprite.getTextureRect().height/2);
}

Board::~Board(){};

// PUBLIC FUNCTIONS -----------------------------------------------------

void Board::snapPieceToGrid(Piece& piece)
{
	sf::Vector2f pos = piece.sprite.getPosition();
	int x, y;
	int PieceX = pos.x;
	int PieceY = pos.y;

	x = cellSize*8 <= PieceX ? 8 : PieceX/cellSize + 1;
	y = cellSize*8 <= PieceY ? 8 : PieceY/cellSize + 1;

	//scale with cellsize to transform it into the right place on the board
	piece.sprite.setPosition(x*cellSize -cellSize/2.f,y*cellSize - cellSize/2.f);
}

// PRIVATE FUNCTIONS ----------------------------------------------------

void Board::initPieces()
{
		
}
