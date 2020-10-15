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
	// set origin to middle
	this->sprite.setOrigin(this->sprite.getTextureRect().width/2,
				   	this->sprite.getTextureRect().height/2);
	// move board so upper left corner matches with window
	this->sprite.move(this->sprite.getTextureRect().width/2,
				   	this->sprite.getTextureRect().height/2);

    initPieces();
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

    pieces.push_back(std::move(std::shared_ptr<Piece>(new Bishop(Color::WHITE, 100, "res/Bishop.png", std::make_pair<int, int>(3,1)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Bishop(Color::WHITE, 100, "res/Bishop.png", std::make_pair<int, int>(6,1)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Bishop(Color::BLACK, 100, "res/Bishop_B.png", std::make_pair<int, int>(3,8)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Bishop(Color::BLACK, 100, "res/Bishop_B.png", std::make_pair<int, int>(6,8)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Rook(Color::WHITE, 100, "res/Rook.png", std::make_pair<int, int>(1,1)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Rook(Color::WHITE, 100, "res/Rook.png", std::make_pair<int, int>(8,1)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Rook(Color::BLACK, 100, "res/Rook_B.png", std::make_pair<int, int>(1,8)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Rook(Color::BLACK, 100, "res/Rook_B.png", std::make_pair<int, int>(8,8)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Knight(Color::WHITE, 100, "res/Knight.png", std::make_pair<int, int>(2,1)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Knight(Color::WHITE, 100, "res/Knight.png", std::make_pair<int, int>(7,1)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Knight(Color::BLACK, 100, "res/Knight_B.png", std::make_pair<int, int>(2,8)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Knight(Color::BLACK, 100, "res/Knight_B.png", std::make_pair<int, int>(7,8)))));

    pieces.push_back(std::move(std::shared_ptr<Piece>(new Queen(Color::WHITE, 100, "res/Queen.png", std::make_pair<int, int>(5,1)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Queen(Color::BLACK, 100, "res/Queen_B.png", std::make_pair<int, int>(5,8)))));

    pieces.push_back(std::move(std::shared_ptr<Piece>(new Knight(Color::WHITE, 100, "res/King.png", std::make_pair<int, int>(4,1)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Knight(Color::BLACK, 100, "res/King_B.png", std::make_pair<int, int>(4,8)))));

    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::WHITE, 100, "res/Pawn.png", std::make_pair<int, int>(1,2)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::WHITE, 100, "res/Pawn.png", std::make_pair<int, int>(2,2)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::WHITE, 100, "res/Pawn.png", std::make_pair<int, int>(3,2)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::WHITE, 100, "res/Pawn.png", std::make_pair<int, int>(4,2)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::WHITE, 100, "res/Pawn.png", std::make_pair<int, int>(5,2)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::WHITE, 100, "res/Pawn.png", std::make_pair<int, int>(6,2)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::WHITE, 100, "res/Pawn.png", std::make_pair<int, int>(7,2)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::WHITE, 100, "res/Pawn.png", std::make_pair<int, int>(8,2)))));

    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::BLACK, 100, "res/Pawn_B.png", std::make_pair<int, int>(1,7)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::BLACK, 100, "res/Pawn_B.png", std::make_pair<int, int>(2,7)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::BLACK, 100, "res/Pawn_B.png", std::make_pair<int, int>(3,7)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::BLACK, 100, "res/Pawn_B.png", std::make_pair<int, int>(4,7)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::BLACK, 100, "res/Pawn_B.png", std::make_pair<int, int>(5,7)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::BLACK, 100, "res/Pawn_B.png", std::make_pair<int, int>(6,7)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::BLACK, 100, "res/Pawn_B.png", std::make_pair<int, int>(7,7)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::BLACK, 100, "res/Pawn_B.png", std::make_pair<int, int>(8,7)))));
}
