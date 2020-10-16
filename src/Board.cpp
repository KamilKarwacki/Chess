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

BoardPosition Board::getBoardCoordinatesOfPiece(Piece& piece)
{
	sf::Vector2f pos = piece.sprite.getPosition();
	int x, y;
	int PieceX = pos.x;
	int PieceY = pos.y;

	x = cellSize*8 <= PieceX ? 8 : PieceX/cellSize + 1;
	y = cellSize*8 <= PieceY ? 8 : PieceY/cellSize + 1;

	return {x,y};
}

std::vector<std::pair<BoardPosition, Color>> Board::getBoardConfiguration()
{
    std::vector<std::pair<BoardPosition, Color>> result;
    for(const auto& piece : pieces)
        result.push_back(std::make_pair<BoardPosition, Color>(piece->getPosition(), piece->getColor()));

    return result;
}

void Board::deletePieceAt(BoardPosition position)
{
    for(auto it = pieces.begin(); it != pieces.end(); it++)
        if(it->get()->getPosition() == position)
            pieces.erase(it);

/*
    pieces.erase(std::remove_if(pieces.begin(),
                   pieces.end(),
                   [position](Piece& p){return p.getPosition() == position;}), pieces.end());
*/
}

// PRIVATE FUNCTIONS ----------------------------------------------------

void Board::initPieces()
{
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Bishop(Color::WHITE, 100, "res/Bishop.png", BoardPosition(3,1)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Bishop(Color::WHITE, 100, "res/Bishop.png", BoardPosition(6,1)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Bishop(Color::BLACK, 100, "res/Bishop_B.png", BoardPosition(3,8)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Bishop(Color::BLACK, 100, "res/Bishop_B.png", BoardPosition(6,8)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Rook(Color::WHITE, 100, "res/Rook.png", BoardPosition(1,1)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Rook(Color::WHITE, 100, "res/Rook.png", BoardPosition(8,1)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Rook(Color::BLACK, 100, "res/Rook_B.png", BoardPosition(1,8)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Rook(Color::BLACK, 100, "res/Rook_B.png", BoardPosition(8,8)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Knight(Color::WHITE, 100, "res/Knight.png", BoardPosition(2,1)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Knight(Color::WHITE, 100, "res/Knight.png", BoardPosition(7,1)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Knight(Color::BLACK, 100, "res/Knight_B.png", BoardPosition(2,8)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Knight(Color::BLACK, 100, "res/Knight_B.png", BoardPosition(7,8)))));

    pieces.push_back(std::move(std::shared_ptr<Piece>(new Queen(Color::WHITE, 100, "res/Queen.png", BoardPosition(5,1)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Queen(Color::BLACK, 100, "res/Queen_B.png", BoardPosition(5,8)))));

    pieces.push_back(std::move(std::shared_ptr<Piece>(new King(Color::WHITE, 100, "res/King.png", BoardPosition(4,1)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new King(Color::BLACK, 100, "res/King_B.png", BoardPosition(4,8)))));

    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::WHITE, 100, "res/Pawn.png", BoardPosition(1,2)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::WHITE, 100, "res/Pawn.png", BoardPosition(2,2)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::WHITE, 100, "res/Pawn.png", BoardPosition(3,2)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::WHITE, 100, "res/Pawn.png", BoardPosition(4,2)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::WHITE, 100, "res/Pawn.png", BoardPosition(5,2)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::WHITE, 100, "res/Pawn.png", BoardPosition(6,2)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::WHITE, 100, "res/Pawn.png", BoardPosition(7,2)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::WHITE, 100, "res/Pawn.png", BoardPosition(8,2)))));

    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::BLACK, 100, "res/Pawn_B.png", BoardPosition(1,7)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::BLACK, 100, "res/Pawn_B.png", BoardPosition(2,7)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::BLACK, 100, "res/Pawn_B.png", BoardPosition(3,7)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::BLACK, 100, "res/Pawn_B.png", BoardPosition(4,7)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::BLACK, 100, "res/Pawn_B.png", BoardPosition(5,7)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::BLACK, 100, "res/Pawn_B.png", BoardPosition(6,7)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::BLACK, 100, "res/Pawn_B.png", BoardPosition(7,7)))));
    pieces.push_back(std::move(std::shared_ptr<Piece>(new Pawn(Color::BLACK, 100, "res/Pawn_B.png", BoardPosition(8,7)))));
}
