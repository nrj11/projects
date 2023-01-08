/* Pseudo Breakout Coding Assignment
author: Nina Jennings nrj11@georgetown.edu
COSC 051-02 
2/13/2022*/

//setup
#include <iostream>
#include <iomanip>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
using namespace std;

const int window_width = 600;
const int window_height = 600;
const int minleft = 5;
const int maxright = 550;
const int maxtop = 0;
const int minbottom = 545;
bool hit{};

int main(int argc, char const *argv[])
{
    ////BOILEr
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Pseudo Breakout Game");

    //create variables to draw ball
    double ballradius = 10;
    double xdirection = 10;
    double ydirection = 10;

    //draw ball
    sf::CircleShape ball(ballradius);
    ball.setFillColor(sf::Color::White);
    ball.setPosition(290, 230);

    //attributes for ball movement
    double ball_delta_x = 5;
    double ball_delta_y = 3;


    //draw paddle and set attributes
    sf::RectangleShape paddle;
    paddle.setPosition(290,500);
    paddle.setFillColor(sf::Color::Red);
    sf::Vector2f paddlesize (100,25);
    paddle.setSize(paddlesize);

    //attributes for brick wall
    vector <sf::RectangleShape> wall;
    int brickwidth = 60; //brickwidth = window width / 10, the number of bricks;
    int brickheight = 15;
    sf::RectangleShape brick;
    brick.setFillColor(sf::Color::Red);
    brick.setOutlineColor(sf::Color::White);
    brick.setOutlineThickness(5);
    sf::Vector2f bsize(brickwidth, brickheight);
    //set initial position for first brick
    double brick_initial_x = 5;
    double brick_initial_y = 200;
    
    //draw brick wall
    for(int i=0; i <= 10; i++){
        brick.setPosition(brick_initial_x, brick_initial_y);
        brick.setSize(bsize);
        wall.push_back(brick);
        brick_initial_x += brickwidth;
    }

    //variables to stop items from going off screen

    //set up game
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        int current_ball_x = ball.getPosition().x;
        int current_ball_y = ball.getPosition().y;


        //ball ricochet when reaches maxright
        if(current_ball_x > maxright){
            ball_delta_x = -1 * ball_delta_x;
        }
        //ball ricochet when reaches minleft
        if(current_ball_x < minleft){
            ball_delta_x = -1 * ball_delta_x;
        }
        if(current_ball_y < maxtop){
            ball_delta_y = -1 * ball_delta_y;
        }
        if(current_ball_y > minbottom){
            ball_delta_y = -1 * ball_delta_y;
        }
        if(ball.getGlobalBounds().intersects(paddle.getGlobalBounds())){
            ball_delta_x = -1 * ball_delta_x;
            ball_delta_y = -1.2 * ball_delta_y;
        }

        //move ball
        ball.move(ball_delta_x, ball_delta_y);

        //end game if ball goes below paddle
        if (current_ball_y > 500){
            cout << "Game over!" << endl;
            return 1;
        }        
        

        //move paddle with user keyboard input
        int left_delta_x = -10;
        int right_delta_x = 10;
        int currentx = paddle.getPosition().x;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                //stop the paddle from moving off screen
                if (currentx > minleft){
                paddle.move(left_delta_x, 0);
                }
                
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                //stop the paddle from moving off screen
                if (currentx < maxright){
                paddle.move(right_delta_x, 0);
                }
             }
    //clear window
    window.clear();
    //draw
    window.draw(ball);
    window.draw(paddle);
    for(int i = 0; i < wall.size(); i++){
        if (!ball.getGlobalBounds().intersects(wall[i].getGlobalBounds()))
        {
            window.draw(wall[i]);
        }
        else {
            ball_delta_y = -1 * ball_delta_y;
            wall.erase(wall.begin() + i);
        }

        
    }
    if (wall.size() == 0){
        cout << "You win!" << endl;
        return 0;
    }
    //display
    window.display();
    sf::sleep(sf::milliseconds(50));
        }
    
    
return 0;
}
