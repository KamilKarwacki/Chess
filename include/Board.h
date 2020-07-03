#pragma once 

#include<SFML/Graphics.hpp>

#include<array>
#include<string>
#include<Piece.h>

class Board {         
public:
	Board(int cellSize, std::string texturePath);
	~Board();

	void snapPieceToGrid(Piece& piece);

	sf::Sprite sprite;
private:           
	void initPieces();

	std::vector<Piece> pieces;

	sf::Texture texture;

	int cellSize;	
	int boardSize;


	friend class sf::Mouse;
};
