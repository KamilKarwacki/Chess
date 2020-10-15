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

class Board {         
public:
	Board(int cellSize, std::string texturePath);
	~Board();

	void snapPieceToGrid(Piece& piece);
    std::vector<std::shared_ptr<Piece>> pieces;

	sf::RectangleShape sprite;
private:           
	void initPieces();

	sf::Texture texture;

	int cellSize;	
	int boardSize;

	friend class sf::Mouse;
};
