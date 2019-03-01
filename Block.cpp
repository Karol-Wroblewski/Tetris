#include <cstdlib>
#include <iostream>
#include "Game.h"
#include "Block.h"
Block::Block()
{
    srand(time(NULL));
    type = (std::rand()%7);
    turn = 0;

    for(int a = 0; a < 20; a++)
    {
        for(int b = 0; b < 10; b++)
            tab[a][b] = 0;
    }

}

Block::Block(int a)
{
    type = a;
   //type = 5;
    turn = 0;
}

bool Block::Draw_New_Block(sf::RenderWindow &W)
{
sf::RectangleShape pathern(sf::Vector2f(20, 20));
elements[0] = pathern;
elements[1] = pathern;
elements[2] = pathern;
elements[3] = pathern;

switch(Block::type)
    {
        case 0:
            elements[0].setPosition(380, 100);
            elements[1].setPosition(400, 100);
            elements[2].setPosition(420, 100);
            elements[3].setPosition(440, 100);
            break;
        case 1:
            elements[0].setPosition(400, 100);
            elements[1].setPosition(400, 120);
            elements[2].setPosition(420, 120);
            elements[3].setPosition(440, 120);
            break;
        case 2:
            elements[1].setPosition(440, 100);
            elements[0].setPosition(400, 120);
            elements[2].setPosition(420, 120);
            elements[3].setPosition(440, 120);
            break;
        case 3:
            elements[0].setPosition(400, 100);
            elements[1].setPosition(400, 120);
            elements[2].setPosition(420, 120);
            elements[3].setPosition(420, 100);
            break;
        case 4:
            elements[3].setPosition(440, 100);
            elements[0].setPosition(400, 120);
            elements[2].setPosition(420, 120);
            elements[1].setPosition(420, 100);
            break;
        case 5:
            elements[1].setPosition(420, 100);
            elements[0].setPosition(400, 120);
            elements[2].setPosition(420, 120);
            elements[3].setPosition(440, 120);
            break;
        case 6:
            elements[2].setPosition(400, 100);
            elements[1].setPosition(400, 120);
            elements[3].setPosition(420, 120);
            elements[0].setPosition(380, 100);
            break;

}

for(int i = 0; i < 4; i++)
{

    elements[i].setFillColor(sf::Color::Black);
    W.draw(elements[i]);
}
return false;


}

void Block::Block_Movement(sf::RenderWindow &W)
{

    for(int i = 0; i < 4; i++)
    {
        Block::elements[i].move(0, 20);
    }
}

void Block::Show_Blocks(sf::RenderWindow &W)
{

for(int i = 0; i < 4; i++)
    W.draw(Block::elements[i]);
}

void Block::Move_Left()
{
    bool move = true;

    for(int i = 0; i < 4; i++)
    {
    if(elements[i].getPosition().x <= 320)
        move = false;

    if( tab[((int)((elements[i].getPosition().y - 100) / 20))][((int)((elements[i].getPosition().x - 340) / 20))] == 1)
        move = false;

    }
        if(move == true)
        {
            for(int i = 0; i < 4; i++)
                Block::elements[i].move(-20, 0);
        }
}

void Block::Move_Right()
{
bool move = true;
for(int i = 0; i < 4; i++)
{
    if(elements[i].getPosition().x >= 500)
      move = false;

    if( tab[((int)((elements[i].getPosition().y - 100) / 20))][((int)((elements[i].getPosition().x - 300) / 20))] == 1)
        move = false;
}
    if(move == true)
    {
    for(int i = 0; i < 4; i++)
        Block::elements[i].move(20, 0);
    }

}

void Block::Turn_Right()
{

if(type == 0)
{
    if(turn == 0)
    {
        if(elements[0].getPosition().y >=160 )
            {
                elements[0].move(40, -40);
                elements[1].move(20, -20);
                elements[3].move(-20, -60);
                turn = 1;
            }
        else
        {
            int d = 160 - elements[0].getPosition().y;

                elements[0].move(40, -40 + d);
                elements[1].move(20, -20 + d);
                elements[3].move(-20, -60 + d);
                elements[2].move(0, d);
                turn = 1;
        }
    }
    else if(turn == 1)
    {
        if((tab[(int) ((elements[2].getPosition().y - 100)/20)][(int) ((elements[2].getPosition().x - 300)/20)] == 0 ) && (tab[(int) ((elements[2].getPosition().y - 100)/20)][(int) ((elements[2].getPosition().x - 340)/20)] == 0) && (tab[(int) ((elements[2].getPosition().y - 100)/20)][(int) ((elements[2].getPosition().x - 360)/20)] == 0) && (elements[2].getPosition().x >=360) && (elements[2].getPosition().x <= 500))
        {
        std::cout << tab[(int) ((elements[2].getPosition().x - 300)/20)][(int) ((elements[2].getPosition().y - 100)/20)] << std::endl;
        std::cout << tab[(int) ((elements[2].getPosition().x - 340)/20)][(int) ((elements[2].getPosition().y - 100)/20)] << std::endl;
        std::cout << tab[(int) ((elements[2].getPosition().x - 360)/20)][(int) ((elements[2].getPosition().y - 100)/20)] << std::endl;
        elements[0].move(-40, 40);
        elements[1].move(-20, 20);
        elements[3].move(20, 60);
        turn = 0;
        }
    }
}
if(type == 1)
{
    if(turn == 0)
    {
        elements[0].move(20, 0);
        elements[1].move(20, 0);
        elements[3].move(0, -40);
        elements[2].move(0, -40);
        turn = 1;
    }
    else if(turn == 1)
    {
         if((tab[(int) ((elements[2].getPosition().y - 80)/20)][(int) ((elements[2].getPosition().x - 340)/20)] == 0 ) && (tab[(int) ((elements[2].getPosition().y - 80)/20)][(int) ((elements[2].getPosition().x - 300)/20)] == 0) && (tab[(int) ((elements[2].getPosition().y - 60)/20)][(int) ((elements[2].getPosition().x - 300)/20)] == 0) && (elements[2].getPosition().x >=340) )
            {
                elements[3].move(0, 20);
                elements[2].move(0, 20);
                elements[0].move(20, 20);
                elements[1].move(-20, -20);
                turn = 2;
            }
    }
    else if(turn == 2)
    {
        elements[2].move(0, 20);
        elements[1].move(40, -20);
        turn = 3;
    }
    else if(turn == 3)
    {
         if((tab[(int) ((elements[2].getPosition().y - 120)/20)][(int) ((elements[2].getPosition().x - 320)/20)] == 0 ) && (tab[(int) ((elements[2].getPosition().y - 120)/20)][(int) ((elements[2].getPosition().x - 280)/20)] == 0) && (tab[(int) ((elements[2].getPosition().y - 120)/20)][(int) ((elements[2].getPosition().x - 260)/20)] == 0) && (elements[2].getPosition().x <= 500))
        {
            elements[0].move(-20, -20);
            elements[1].move(-20, 40);
            elements[2].move(20, 0);
            elements[3].move(20, 20);
            turn = 0;
        }
    }


}
if(type == 2)
{
    if(turn == 0)
    {
        elements[1].move(-20, 0);
        elements[0].move(20, -40);
        turn = 1;
    }
    else if(turn == 1)
    {
         if((tab[(int) ((elements[1].getPosition().y - 100)/20)][(int) ((elements[2].getPosition().x - 280)/20)] == 0 ) && (elements[2].getPosition().x <= 480))
        {
            elements[3].move(0, -20);
            elements[0].move(40, 20);
            turn = 2;
        }
    }
    else if(turn == 2)
    {
        elements[3].move(-20, -20);
        elements[0].move(-60, -20);
        turn = 3;
    }
    else if(turn == 3)
    {
         if((tab[(int) ((elements[2].getPosition().y - 100)/20)][(int) ((elements[2].getPosition().x - 300)/20)] == 0 ) && (tab[(int) ((elements[2].getPosition().y - 100)/20)][(int) ((elements[2].getPosition().x - 280)/20)] == 0) && (elements[2].getPosition().x >=360))
        {
            elements[2].move(-20, 0);
            elements[3].move(0, 40);
            elements[0].move(-20, 40);
            turn = 0;
        }
    }
}
//type = 3 in not changing
if(type == 4)
{
    if(turn == 0)
    {
        elements[0].move(0, -20);
        elements[3].move(-40, -20);
        turn = 1;
    }
    else if(turn == 1)
    {
         if((tab[(int) ((elements[1].getPosition().y - 100)/20)][(int) ((elements[1].getPosition().x - 300)/20)] == 0 ) && (tab[(int) ((elements[2].getPosition().y - 100)/20)][(int) ((elements[2].getPosition().x - 300)/20)] == 0) && (elements[1].getPosition().x <= 500))
            {
                elements[0].move(0, 20);
                elements[3].move(40, 20);
                turn = 0;
            }
    }

}

if(type == 5)
{
    if(turn == 0)
    {
        elements[3].move(0, -20);
        elements[0].move(20, -40);
        turn = 1;
    }
    else if(turn == 1)
    {
        if((tab[(int) ((elements[1].getPosition().y - 100)/20)][(int) ((elements[1].getPosition().x - 340)/20)] == 0 ) && (elements[1].getPosition().x >=340))
        {
            elements[0].move(-20, 20);
            turn = 2;
        }
    }
    else if(turn == 2)
    {
        elements[3].move(-20, -20);
        turn = 3;
    }
    else if(turn == 3)
    {
        if((tab[(int) ((elements[0].getPosition().y - 80)/20)][(int) ((elements[0].getPosition().x - 320)/20)] == 0 ) && (tab[(int) ((elements[2].getPosition().y - 100)/20)][(int) ((elements[2].getPosition().x - 300)/20)] == 0) && (elements[2].getPosition().x <=500))
        {
            elements[0].move(0, 20);
            elements[3].move(20, 40);
            turn = 0;
        }
    }

}

if(type == 6)
{
    if(turn == 0)
    {
        elements[3].move(0, -20);
        elements[0].move(40, -20);
        turn = 1;
    }
    else if(turn == 1)
    {
        if((tab[(int) ((elements[2].getPosition().y - 100)/20)][(int) ((elements[2].getPosition().x - 340)/20)] == 0 ) && (tab[(int) ((elements[1].getPosition().y - 100)/20)][(int) ((elements[1].getPosition().x - 300)/20)] == 0) && (elements[2].getPosition().x >= 340))
        {
        elements[3].move(0, 20);
        elements[0].move(-40, 20);
        turn = 0;
        }
    }

}


///////////////////////////////////////
for(int i = 3; i >= 0; i--)
{
if(elements[i].getPosition().x < 320)
        {
            for(int i = 0; i < 4; i++)
            {
                elements[i].move(20, 0);
            }
        }

        if(elements[i].getPosition().x > 500)
        {
            for(int i = 0; i < 4; i++)
            {
                elements[i].move(-20, 0);
            }
        }
}
//from back
for(int i = 3; i >=0 ; i--)
{
    while(tab[(int) ((elements[i].getPosition().x)-320) / 20][(int) ((elements[i].getPosition().y)/100) / 20] != 0 )
        {
            for(int i = 0; i < 4; i++)
            {
                elements[i].move(-20, 0);
            }
        }

}

////////////////////////////////////////
}


bool Block::Check_Bottom()
{
    for(int i = 0; i < 4; i++)
    {
        //Bottom
        if(elements[i].getPosition().y == 480)
            {
                tab[((int)((elements[0].getPosition().y - 100) / 20))][((int)((elements[0].getPosition().x - 320) / 20))] = 1;
                tab[((int)((elements[1].getPosition().y - 100) / 20))][((int)((elements[1].getPosition().x - 320) / 20))] = 1;
                tab[((int)((elements[2].getPosition().y - 100) / 20))][((int)((elements[2].getPosition().x - 320) / 20))] = 1;
                tab[((int)((elements[3].getPosition().y - 100) / 20))][((int)((elements[3].getPosition().x - 320) / 20))] = 1;
                return true;
            }
        //Block under


                ///////////////////////////////////- 80
       if(tab[((int)((elements[i].getPosition().y - 80) / 20))][((int)((elements[i].getPosition().x - 320) / 20))] == 1)
            {
                tab[((int)((elements[0].getPosition().y - 100) / 20))][((int)((elements[0].getPosition().x - 320) / 20))] = 1;
                tab[((int)((elements[1].getPosition().y - 100) / 20))][((int)((elements[1].getPosition().x - 320) / 20))] = 1;
                tab[((int)((elements[2].getPosition().y - 100) / 20))][((int)((elements[2].getPosition().x - 320) / 20))] = 1;
                tab[((int)((elements[3].getPosition().y - 100) / 20))][((int)((elements[3].getPosition().x - 320) / 20))] = 1;
                return true;
            }
    }
    return false;
}

void Block::Draw_Rectangles(sf::RenderWindow &W)
{
sf::RectangleShape O(sf::Vector2f(20, 20));
O.setFillColor(sf::Color::Black);
    for(int a = 0; a < 20; a++)
    {
        for(int b = 0; b < 10; b++)
            {
                if(tab[a][b] == 1)
                    {
                        O.setPosition(320 + b * 20, 100 + a * 20);
                        W.draw(O);
                    }
            }
    }
}

int Block::Check_Points()
{
int amount = 0;
    for(int a = 0; a < 20; a++)
    {
        for(int b = 0; b < 10; b++)
            {
                if(tab[a][b] != 1)
                    break;
                if( b == 9)
                {
                    amount++;
                    for(int s = 0; s < 10; s++)
                        tab[a][s] = 0;


                    for(int c = a; c > 0 ; c--)
                        {
                            for(int d = 0; d < 10; d++)
                                {
                                    tab[c][d] = tab[c - 1][d];
                                }
                        }


                }
            }
    }

    if(amount == 1)
        amount = 100;
    else if(amount == 2)
        amount = 300;
    else if(amount == 3)
        amount = 500;
    else if(amount == 4)
        amount = 800;
    else
        amount = 0;

    return amount;
}

bool Block::Check_Finish(sf::RenderWindow &W)
{

    if(Block::type == 0)
    {
        if(tab[0][4] == 1 || tab[0][5] == 1 || tab[0][6] == 1 || tab[0][7] == 1)
        {
                    return true;
        }
    }
    else if(Block::type == 1)
    {
        if(tab[0][5] == 1 || tab[1][6] == 1 || tab[1][7] == 1 || tab[1][5] == 1)
            {
                if(tab[0][5] == 0 && tab[0][4] == 0 && tab[0][6] == 0 && tab[0][7] == 0)
                    {
                        sf::RectangleShape pathern(sf::Vector2f(20, 20));
                        elements[0] = pathern;
                        elements[1] = pathern;
                        elements[2] = pathern;
                        elements[0].setPosition(400, 100);
                        elements[1].setPosition(420, 100);
                        elements[2].setPosition(440, 100);

                        for(int i = 0; i < 3; i++)
                        {
                            elements[i].setFillColor(sf::Color::Black);
                            W.draw(elements[i]);
                        }
                    }

                    return true;
            }
    }
    else if(Block::type == 2)
    {
        if(tab[0][7] == 1 || tab[1][5] == 1 || tab[1][6] == 1 || tab[1][7] == 1)
            {
                    if(tab[0][5] == 0 && tab[0][4] == 0 && tab[0][6] == 0 && tab[0][7] == 0)
                    {
                        sf::RectangleShape pathern(sf::Vector2f(20, 20));
                        elements[0] = pathern;
                        elements[1] = pathern;
                        elements[2] = pathern;
                        elements[0].setPosition(400, 100);
                        elements[2].setPosition(420, 100);
                        elements[3].setPosition(440, 100);

                        for(int i = 0; i < 3; i++)
                        {
                            elements[i].setFillColor(sf::Color::Black);
                            W.draw(elements[i]);
                        }
                    }
                    return true;
            }
    }
    else if (Block::type == 3)
    {
        if(tab[0][5] == 1 || tab[1][5] == 1 || tab[1][6] == 1 || tab[0][6] == 1)
            {
                    if(tab[0][5] == 0 && tab[0][4] == 0 && tab[0][6] == 0 && tab[0][7] == 0)
                    {
                        sf::RectangleShape pathern(sf::Vector2f(20, 20));
                        elements[0] = pathern;
                        elements[1] = pathern;
                        elements[2] = pathern;
                        elements[0].setPosition(400, 100);
                        elements[1].setPosition(420, 100);

                        for(int i = 0; i < 2; i++)
                        {

                            elements[i].setFillColor(sf::Color::Black);
                            W.draw(elements[i]);
                        }
                    }

                    return true;
            }
    }
    else if (Block::type == 4)
    {
        if(tab[0][7] == 1 || tab[1][5] == 1 || tab[1][6] == 1 || tab[0][6] == 1)
            {
                   if(tab[0][5] == 0 && tab[0][4] == 0 && tab[0][6] == 0 && tab[0][7] == 0)
                    {
                        sf::RectangleShape pathern(sf::Vector2f(20, 20));
                        elements[0] = pathern;
                        elements[1] = pathern;
                        elements[2] = pathern;
                        elements[0].setPosition(400, 100);
                        elements[1].setPosition(420, 100);

                        for(int i = 0; i < 2; i++)
                        {

                            elements[i].setFillColor(sf::Color::Black);
                            W.draw(elements[i]);
                        }
                    }
                    return true;
            }
    }
    else if (Block::type == 5)
    {
        if(tab[0][6] == 1 || tab[1][5] == 1 || tab[1][6] == 1 || tab[1][7] == 1)
            {
                   if(tab[0][5] == 0 && tab[0][4] == 0 && tab[0][6] == 0 && tab[0][7] == 0)
                    {
                        sf::RectangleShape pathern(sf::Vector2f(20, 20));
                        elements[0] = pathern;
                        elements[1] = pathern;
                        elements[2] = pathern;
                        elements[0].setPosition(400, 100);
                        elements[1].setPosition(420, 100);
                        elements[1].setPosition(440, 100);
                        for(int i = 0; i < 3; i++)
                        {

                            elements[i].setFillColor(sf::Color::Black);
                            W.draw(elements[i]);
                        }
                    }
                    return true;
            }
    }
    else if (Block::type == 6)
    {
        if(tab[0][5] == 1 || tab[1][5] == 1 || tab[1][6] == 1 || tab[0][4] == 1)
            {
                   if(tab[0][5] == 0 && tab[0][4] == 0 && tab[0][6] == 0 && tab[0][7] == 0)
                    {
                        sf::RectangleShape pathern(sf::Vector2f(20, 20));
                        elements[0] = pathern;
                        elements[1] = pathern;
                        elements[2] = pathern;
                        elements[0].setPosition(400, 100);
                        elements[1].setPosition(420, 100);
                        for(int i = 0; i < 2; i++)
                        {

                            elements[i].setFillColor(sf::Color::Black);
                            W.draw(elements[i]);
                        }
                    }
                    return true;
            }
    }

    return false;
}

