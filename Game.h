#ifndef Game_H_
#define Game_H_
#include <SFML/Graphics.hpp>

class Game
{
private:
    sf::Font GlobalFont; //Font to drawing
    int points = 0; //points
public:
    Game(); //Start game
    void Draw_All_Boundaries(sf::RenderWindow &W); //Draw Graphics
    bool Draw_Start_Credits(sf::RenderWindow &W); //Draw Start of a game
    void Play(sf::RenderWindow &W); //Here is action of a game
    void Draw_Next(sf::RenderWindow &W, int a); //draw next shape(right side)
    void Draw_Hold(sf::RenderWindow &W, int a); //draw help shape(left side)
    void ShowPoints(sf::RenderWindow &W); //Show Current Points
    void Finish_Game(sf::RenderWindow &W); //End of game
    void Draw_BackGround(sf::RenderWindow &W); //Drawing background (grille)
};

#endif
