#include "Game.h"
#include "Block.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

Game::Game()
{

}

void Game::Draw_All_Boundaries(sf::RenderWindow &W)
{
W.clear(sf::Color::White);

sf::RectangleShape Bottom_Bar(sf::Vector2f(240,20));
Bottom_Bar.setFillColor(sf::Color::Black);
Bottom_Bar.setPosition(300, 500);
W.draw(Bottom_Bar);

sf::RectangleShape Right_Bar(sf::Vector2f(20,400));
Right_Bar.setFillColor(sf::Color::Black);
Right_Bar.setPosition(520, 100);
W.draw(Right_Bar);

sf::RectangleShape Left_Bar(sf::Vector2f(20,400));
Left_Bar.setFillColor(sf::Color::Black);
Left_Bar.setPosition(300, 100);
W.draw(Left_Bar);

sf::RectangleShape Next_Block(sf::Vector2f(120, 120));
Next_Block.setFillColor(sf::Color::White);
Next_Block.setOutlineThickness(20);
Next_Block.setOutlineColor(sf::Color::Black);
Next_Block.setPosition(600, 160);
W.draw(Next_Block);

sf::RectangleShape Hold_Block(sf::Vector2f(120, 120));
Hold_Block.setFillColor(sf::Color::White);
Hold_Block.setOutlineThickness(20);
Hold_Block.setOutlineColor(sf::Color::Black);
Hold_Block.setPosition(120, 160);
W.draw(Hold_Block);

sf::RectangleShape Points_Block(sf::Vector2f(180, 30));
Points_Block.setFillColor(sf::Color::White);
Points_Block.setOutlineThickness(20);
Points_Block.setOutlineColor(sf::Color::Black);
Points_Block.setPosition(60, 400);
W.draw(Points_Block);
///////////////////////////////////////
GlobalFont.loadFromFile("OpenSans-Bold.ttf");
///////////////////
sf::Text Points;
Points.setFont(GlobalFont);
Points.setCharacterSize(22);
Points.setColor(sf::Color::Black);
Points.setPosition(63, 403);
Points.setString("Points: ");
W.draw(Points);

sf::Text Hold;
Hold.setFont(GlobalFont);
Hold.setCharacterSize(22);
Hold.setColor(sf::Color::Black);
Hold.setPosition(100, 110);
Hold.setString("Hold (press 'c')");
W.draw(Hold);

sf::Text Next;
Next.setFont(GlobalFont);
Next.setCharacterSize(22);
Next.setColor(sf::Color::Black);
Next.setPosition(626, 110);
Next.setString("Next: ");
W.draw(Next);
}

bool Game::Draw_Start_Credits(sf::RenderWindow &W)
{
        sf::Event e;

        sf::Text Start;
        Start.setFont(GlobalFont);
        Start.setCharacterSize(22);
        Start.setColor(sf::Color::Black);
        Start.setPosition(375, 200);
        Start.setString("Welcome \n \t to \n  Tetris!");
        W.draw(Start);

        sf::RectangleShape Button(sf::Vector2f(140, 30));
        Button.setFillColor(sf::Color::White);
        Button.setOutlineThickness(10);
        Button.setOutlineColor(sf::Color::Black);
        Button.setPosition(355, 350);
        W.draw(Button);

        sf::Text Play;
        Play.setFont(GlobalFont);
        Play.setCharacterSize(22);
        Play.setColor(sf::Color::Black);
        Play.setPosition(357, 351);
        Play.setString("Start Game");
        W.draw(Play);
}

void Game::Play(sf::RenderWindow &W)
{

int hold = -1;

sf::Clock clock;
sf::Time time1;
Block *block = new Block;
int next_type = (std::rand() % 7);
sf::Event e;
    Game::Draw_Next(W, next_type);
    block->Draw_New_Block(W);
    Game::ShowPoints(W);
    while(true)
    {

        while(W.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
                W.close();
        }

        if( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ) //move left
        {
            block->Move_Left();
            sf::sleep(sf::milliseconds(60));
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) //mov right
        {
            block->Move_Right();
            sf::sleep(sf::milliseconds(60));
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) //turn right
        {
            block->Turn_Right();
            sf::sleep(sf::milliseconds(100));
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            sf::sleep(sf::milliseconds(30));
            for(int i = 0; i < 70; i++)
            {
                bool go = true;
                points += 2;

               if(block->Check_Bottom())
                {
                points += block->Check_Points();
                int temp[20][10];

                for(int a = 0; a < 20; a++)
                {
                    for(int b = 0; b < 10; b++)
                            temp[a][b] = block->tab[a][b];
                }

                delete block;
                block = new Block(next_type);
                go = false;
                for(int a = 0; a < 20; a++)
                {
                    for(int b = 0; b < 10; b++)
                            block->tab[a][b] = temp[a][b];
                }

                if(block->Check_Finish(W))
                {
                            W.display();
                            Finish_Game(W);
                            delete block;
                            block = new Block;
                            hold = -1;

                }
                 block->Draw_New_Block(W);
                 next_type = (std::rand() % 7);
                break;
                }
                if(go == true)
                {
                    block->Block_Movement(W);
                }
                go = true;

            }
            sf::sleep(sf::milliseconds(120));
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::C) && block->was_rotated == 0)
        {
            if(hold == -1)
                {
                    hold = block->type;

                    sf::sleep(sf::milliseconds(100));
                    int temp[20][10];
                        for(int a = 0; a < 20; a++)
                        {
                            for(int b = 0; b < 10; b++)
                                    temp[a][b] = block->tab[a][b];
                        }

                        delete block;
                        block = new Block(next_type);

                        next_type = (std::rand()%7);

                        for(int a = 0; a < 20; a++)
                        {
                            for(int b = 0; b < 10; b++)
                                    block->tab[a][b] = temp[a][b];
                        }
                        block->Draw_New_Block(W);

                        Game::Draw_Hold(W, hold);
                }
                else
                {
                    int t = hold;
                    hold = block->type;


                    sf::sleep(sf::milliseconds(100));
                    int temp[20][10];
                        for(int a = 0; a < 20; a++)
                        {
                            for(int b = 0; b < 10; b++)
                                    temp[a][b] = block->tab[a][b];
                        }

                        delete block;
                        block = new Block(t);

                        for(int a = 0; a < 20; a++)
                        {
                            for(int b = 0; b < 10; b++)
                                    block->tab[a][b] = temp[a][b];
                        }
                        block->Draw_New_Block(W);
                        Game::Draw_Hold(W, hold);
                }

                block->was_rotated = 1;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {

                        bool go = true;
                        points += 1;
            if(block->Check_Bottom())
            {
                points += block->Check_Points();
                int temp[20][10];

               for(int a = 0; a < 20; a++)
                {
                    for(int b = 0; b < 10; b++)
                            temp[a][b] = block->tab[a][b];
                }

                delete block;
                block = new Block(next_type);
                go = false;
                for(int a = 0; a < 20; a++)
                {
                    for(int b = 0; b < 10; b++)
                            block->tab[a][b] = temp[a][b];
                }

                if(block->Check_Finish(W))
                {
                            W.display();
                            Finish_Game(W);
                            delete block;
                            block = new Block;
                            hold = -1;

                }
                 block->Draw_New_Block(W);
                 next_type = (std::rand() % 7);

                }
                if(go == true)
                {
                    block->Block_Movement(W);
                }
                go = true;

        }

////////////////////////////////////////////////////

        ////////////////////////MOVE
        time1 = clock.getElapsedTime();
        if(time1.asMilliseconds() >= (600 - (points / 1000)))////////////// Do a move
        {
        bool go = true;
            if(block->Check_Bottom())
            {
                points += block->Check_Points();
                int temp[20][10];

               for(int a = 0; a < 20; a++)
                {
                    for(int b = 0; b < 10; b++)
                            temp[a][b] = block->tab[a][b];
                }

                delete block;
                block = new Block(next_type);
                go = false;
                for(int a = 0; a < 20; a++)
                {
                    for(int b = 0; b < 10; b++)
                            block->tab[a][b] = temp[a][b];
                }

                if(block->Check_Finish(W))
                {
                            W.display();
                            Finish_Game(W);
                            delete block;
                            block = new Block;
                            hold = -1;

                }
                 block->Draw_New_Block(W);
                 next_type = (std::rand() % 7);

            }
            clock.restart();
            if(go == true)
            {
                block->Block_Movement(W);
            }
            go = true;
        }
        ///////////////////////

        Game::Draw_All_Boundaries(W);
        Game::Draw_BackGround(W);
        Game::Draw_Next(W, next_type);
        block->Show_Blocks(W);
        block->Draw_Rectangles(W);
        if(hold != -1)
            Game::Draw_Hold(W, hold);
        Game::ShowPoints(W);

        W.display();

    }
}

void Game::Draw_Next(sf::RenderWindow &W, int a)
{
sf::RectangleShape pathern(sf::Vector2f(20, 20));
pathern.setFillColor(sf::Color::Black);

sf::RectangleShape elements[4];
elements[0] = pathern;
elements[1] = pathern;
elements[2] = pathern;
elements[3] = pathern;

    if(a == 0)
    {
        elements[0].setPosition(620, 210);
        elements[1].setPosition(640, 210);
        elements[2].setPosition(660, 210);
        elements[3].setPosition(680, 210);
    }

    else if(a == 1)
    {
        elements[0].setPosition(630, 190);
        elements[1].setPosition(630, 210);
        elements[2].setPosition(650, 210);
        elements[3].setPosition(670, 210);
    }

    else if(a == 2)
    {
        elements[0].setPosition(630, 220);
        elements[1].setPosition(650, 220);
        elements[2].setPosition(670, 220);
        elements[3].setPosition(670, 200);
    }

    else if(a == 3)
    {
        elements[0].setPosition(640, 200);
        elements[1].setPosition(640, 220);
        elements[2].setPosition(660, 200);
        elements[3].setPosition(660, 220);
    }

    else if(a == 4)
    {
        elements[0].setPosition(630, 220);
        elements[1].setPosition(650, 220);
        elements[2].setPosition(650, 200);
        elements[3].setPosition(670, 200);
    }

    else if(a == 5)
    {
        elements[0].setPosition(630, 210);
        elements[1].setPosition(650, 210);
        elements[2].setPosition(670, 210);
        elements[3].setPosition(650, 190);
    }

    else if(a == 6)
    {
        elements[0].setPosition(640, 190);
        elements[1].setPosition(660, 190);
        elements[2].setPosition(660, 210);
        elements[3].setPosition(680, 210);
    }


    for(int i = 0; i < 4; i++)
        W.draw(elements[i]);
}


void Game::Draw_Hold(sf::RenderWindow &W, int a)
{
sf::RectangleShape pathern(sf::Vector2f(20, 20));
pathern.setFillColor(sf::Color::Black);

sf::RectangleShape elements[4];
elements[0] = pathern;
elements[1] = pathern;
elements[2] = pathern;
elements[3] = pathern;

    if(a == 0)
    {
        elements[0].setPosition(140, 210);
        elements[1].setPosition(160, 210);
        elements[2].setPosition(180, 210);
        elements[3].setPosition(200, 210);
    }

    else if(a == 1)
    {
        elements[0].setPosition(150, 190);
        elements[1].setPosition(150, 210);
        elements[2].setPosition(170, 210);
        elements[3].setPosition(190, 210);
    }

    else if(a == 2)
    {
        elements[0].setPosition(150, 220);
        elements[1].setPosition(170, 220);
        elements[2].setPosition(190, 220);
        elements[3].setPosition(190, 200);
    }

    else if(a == 3)
    {
        elements[0].setPosition(160, 200);
        elements[1].setPosition(160, 220);
        elements[2].setPosition(180, 200);
        elements[3].setPosition(180, 220);
    }

    else if(a == 4)
    {
        elements[0].setPosition(150, 220);
        elements[1].setPosition(170, 220);
        elements[2].setPosition(170, 200);
        elements[3].setPosition(190, 200);
    }

    else if(a == 5)
    {
        elements[0].setPosition(150, 210);
        elements[1].setPosition(170, 210);
        elements[2].setPosition(190, 210);
        elements[3].setPosition(170, 190);
    }

    else if(a == 6)
    {
        elements[0].setPosition(160, 190);
        elements[1].setPosition(180, 190);
        elements[2].setPosition(180, 210);
        elements[3].setPosition(200, 210);
    }


    for(int i = 0; i < 4; i++)
        W.draw(elements[i]);

   // W.display();
}

void Game::ShowPoints(sf::RenderWindow &W)
{
    sf::Text P;
    std::string points_str;
    points_str = std::to_string(points);
    P.setString(points_str);
    P.setFont(GlobalFont);
    P.setFillColor(sf::Color::Black);
    P.setPosition(140, 396);
    W.draw(P);
   // W.display();
}

void Game::Finish_Game(sf::RenderWindow &W)
{
    sf::RenderWindow M( sf::VideoMode( 400, 300, 32 ), "End Game!" );
    M.setFramerateLimit(60);
    M.clear(sf::Color::Blue);

    sf::Text end;
        end.setFont(GlobalFont);
        end.setString("           Koniec gry!\n Zdobyte punkty: ");
        end.setPosition(30, 30);


        std::string str_points;
        str_points = std::to_string(points);

        sf::Text end1;
        end1.setFont(GlobalFont);
        end1.setString(str_points);
        end1.setPosition(288, 72);
        M.draw(end);
        M.draw(end1);

        sf::RectangleShape Button(sf::Vector2f(140, 30));
        Button.setFillColor(sf::Color::White);
        Button.setOutlineThickness(10);
        Button.setOutlineColor(sf::Color::Black);
        Button.setPosition(30, 130);
        M.draw(Button);

        sf::Text Play;
        Play.setFont(GlobalFont);
        Play.setCharacterSize(22);
        Play.setColor(sf::Color::Black);
        Play.setPosition(33, 133);
        Play.setString("Play Again");
        M.draw(Play);

        Button.setPosition(220, 130);
        M.draw(Button);

        sf::Text Exit;
        Exit.setFont(GlobalFont);
        Exit.setCharacterSize(22);
        Exit.setColor(sf::Color::Black);
        Exit.setPosition(223, 133);
        Exit.setString("Exit");
        M.draw(Exit);

        M.display();
    while(true)
    {
        sf::Event e;
        while(M.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
                {
                    M.close();
                    W.close();
                }
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(M).x > 30 && sf::Mouse::getPosition(M).x < 170 && sf::Mouse::getPosition(M).y > 130 && sf::Mouse::getPosition(M).y < 160)
        {
             M.close();
            points = 0;
            int next_type = rand()%7;
             Game::Draw_Next(W, next_type);
            Game::ShowPoints(W);
            break;
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(M).x > 220 && sf::Mouse::getPosition(M).x < 360 && sf::Mouse::getPosition(M).y > 130 && sf::Mouse::getPosition(M).y < 160)
        {
            W.close();
            M.close();
        }

    }
}

void Game::Draw_BackGround(sf::RenderWindow &W)
{
    sf::RectangleShape O(sf::Vector2f(20,20));
    O.setFillColor(sf::Color::White);
    O.setOutlineThickness(1);
    O.setOutlineColor(sf::Color::Black);
    for(int i = 0; i < 10; i++)
    {
        for(int a = 0; a < 20; a++)
            {
                O.setPosition(320 + i * 20, 100 + a * 20);
                W.draw(O);
            }
    }

}
