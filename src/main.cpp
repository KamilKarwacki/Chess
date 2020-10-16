#include <SFML/Graphics.hpp>
#include "ChessGame.h"
#include "Board.h"


int main()
{

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	Board board(100, "res/chessboard.gif");

	ChessGame game;

	bool isSomePieceGrabbed = false;

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
					game.onLeftClickReleased(board);
				}
			}
		}

		// code for starting movement
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			game.onLeftClick(board, mousePos.x, mousePos.y);
		}

		window.clear();
		window.draw(board.sprite);
		for(const auto& piece : board.pieces)
		    window.draw(piece->sprite);
		window.display();	
	}

	return 0;
}
