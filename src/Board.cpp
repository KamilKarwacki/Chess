#include "Board.h" 


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
	this->sprite.setTexture(texture);
	this->sprite.setScale(cellSize/10.f,cellSize/10.f);
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

	x = cellSize*8 > x ? cellSize*8 : x%cellSize;
	y = cellSize*8 > y ? cellSize*8 : y%cellSize;

	piece.sprite.setPosition(x,y);
}


// PRIVATE FUNCTIONS ----------------------------------------------------

void Board::initPieces()
{
		

}
