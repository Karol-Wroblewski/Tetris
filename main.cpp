#include <SFML/Graphics.hpp>
#include "Block.h"//New Blocks
#include "Game.h" //cotrol game


int main()
{
    sf::RenderWindow W( sf::VideoMode( 800, 600, 32 ), "Tetris" );
    W.setFramerateLimit(60); //MAX FPS
    Game game;
    game.Draw_All_Boundaries(W);
    while( W.isOpen() )
    {
        game.Draw_All_Boundaries(W);
        game.Draw_Start_Credits(W);
        sf::Event e;

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(W).x > 355 && sf::Mouse::getPosition(W).x < 495 && sf::Mouse::getPosition(W).y > 350 && sf::Mouse::getPosition(W).y < 380)
        {
            game.Draw_All_Boundaries(W);
            game.Play(W);
        }
        while( W.pollEvent( e ) )
        {
            if(e.type == sf::Event::Closed)
                W.close();
        }

        W.display();
    }
    return 0;
}
