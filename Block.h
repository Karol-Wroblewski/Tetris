#ifndef Block_H_
#define Block_H_
#include <SFML/Graphics.hpp>

class Block
{
private:
    sf::RectangleShape elements[4]; //Elements to movements
    int turn; // What shape have a position
public:
    int type; //Type of shape
    int tab[20][10];//Elements on the board
    bool was_rotated = 0; //Have user rotated a block
    Block(); //First Shape of a game
    Block(int a); // New Shape
    bool Draw_New_Block(sf::RenderWindow &W); //Drawing New Shape
    void Block_Movement(sf::RenderWindow &W); //Move Shape(down
    void Show_Blocks(sf::RenderWindow &W); //Draw current move blocks
    void Move_Left();
    void Move_Right();
    void Turn_Right(); //rotate block
    bool Check_Bottom(); //Check if shape have a "floor"
    void Draw_Rectangles(sf::RenderWindow &W); //Show all blocks
    int Check_Points(); //Add points
    bool Check_Finish(sf::RenderWindow &W); //Check finish of a game
};


#endif
