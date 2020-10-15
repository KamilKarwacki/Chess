#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "Bishop.h"
#include "Board.h"
#include "Color.h"


int main()
{

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	Board board(100, "res/chessboard.gif");

	bool isBeingGrabbed = false;

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
				    for(auto& piece : board.pieces)
					    board.snapPieceToGrid(*piece);
				    isBeingGrabbed = false;
				}
			}
		}

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            for(const auto& piece : board.pieces)
			    if(piece->sprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
		    	{
		    		piece->sprite.setPosition(mousePos.x, mousePos.y);
		    		isBeingGrabbed = true;
		    	}
		}

		window.clear();
		window.draw(board.sprite);
		for(const auto& piece : board.pieces)
		    window.draw(piece->sprite);
		window.display();	
	}

	return 0;
}
