#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "Bishop.h"
#include "Board.h"


int main()
{

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	Board board(9, "res/chessboard.gif");
	Bishop bishop(100, "res/Chess_blt60.png", std::make_pair<int,int>(1,1));


	while (window.isOpen())
	{					
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if(event.type == sf::Event::MouseButtonReleased)
			{
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					board.snapPieceToGrid(bishop);
				}
			}
		}

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if(bishop.sprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
			{
				bishop.sprite.setPosition(mousePos.x, mousePos.y);
			}
		}


		window.clear();
		window.draw(board.sprite);
		window.draw(bishop.sprite);
		window.display();

	
	}

	return 0;
}
