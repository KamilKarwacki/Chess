#pragma once 

#include<SFML/Graphics.hpp>

#include<array>
#include<string>
#include<memory>

#include<Piece.h>
#include<Bishop.h>
#include<Pawn.h>
#include<Knight.h>
#include<Rook.h>
#include<Queen.h>
#include<King.h>
#include "BoardPosition.h"

class Board {         
public:
	Board(int cellSize, std::string texturePath);
	~Board();

	BoardPosition getBoardCoordinatesOfPiece(Piece& piece);
	// returns a list with all current pieces and their colors
	std::vector<std::pair<BoardPosition, Color>> getBoardConfiguration();
    void deletePieceAt(BoardPosition position);
    std::vector<std::shared_ptr<Piece>> pieces;

	sf::RectangleShape sprite;
private:           
	void initPieces();

	sf::Texture texture;

	int cellSize;	
	int boardSize;

	friend class sf::Mouse;
};
