/*
* @file barchart.cpp
* @author Nina Jennings nrj11@georgetown.edu
* @date 1/28/22
*/

//setup
#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
using namespace std;

const int window_width = 800;
const int window_height = 600;

int main(int argc, char *argv [])
{ 
    //// BOILER
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Bar Chart");

    //reading data from revenue.txt file
    ifstream storerevenues("revenue.txt");

    //define variables to set attributes of bar rectangles
    double rectwidth = 80.0;
    double rectspace = 25.0;
    double scaleheight = .0025;
    double positionmargin = 80.0;

    //set x axis
    sf::RectangleShape xaxis;
    xaxis.setFillColor (sf::Color::White);
    xaxis.setPosition(70,480);
    sf::Vector2f xaxissz(680,5);
    xaxis.setSize(xaxissz);

    //set y axis
    sf::RectangleShape yaxis;
    yaxis.setFillColor (sf::Color::White);
    yaxis.setPosition(70,0);
    sf::Vector2f yaxissz (5,480);
    yaxis.setSize(yaxissz);



    //set attributes of store 1's revenue bar
    double width1 = rectwidth;
    double store1revenue{};
    storerevenues >> store1revenue;
    double store1barheight = store1revenue * scaleheight;
    double store1hz = positionmargin;
    double store1vert = 480 - store1barheight;

    //create store 1 bar graph rectangle
    sf::RectangleShape store1bar;
    store1bar.setFillColor(sf::Color::Green);
    store1bar.setPosition(store1hz, store1vert);
    sf :: Vector2f store1sz(width1, store1barheight);
    store1bar.setSize(store1sz);

    //set attributes of store 2's revenue bar
    double width2 = rectwidth;
    double store2revenue{};
    storerevenues >> store2revenue;
    double store2barheight = store2revenue * scaleheight;
    double store2hz = positionmargin + rectwidth + rectspace;
    double store2vert = 480 - store2barheight;

    //create store 2 bar graph rectangle
    sf::RectangleShape store2bar;
    store2bar.setFillColor(sf::Color::Green);
    store2bar.setPosition(store2hz, store2vert);
    sf::Vector2f store2sz(width2, store2barheight);
    store2bar.setSize(store2sz);

    //set attributes of store 3's revenue bar
    double width3 = rectwidth;
    double store3revenue{};
    storerevenues >> store3revenue;
    double store3barheight = store3revenue * scaleheight;
    double store3hz = positionmargin + 2*rectwidth + 2*rectspace;
    double store3vert = 480 - store3barheight;

    //create store 3 bar graph rectangle
    sf :: RectangleShape store3bar;
    store3bar.setFillColor(sf::Color::Green);
    store3bar.setPosition(store3hz, store3vert);
    sf :: Vector2f store3sz(width3, store3barheight);
    store3bar.setSize(store3sz);

    //set attributes of store 4's revenue bar
    double width4 = rectwidth;
    double store4revenue{};
    storerevenues >> store4revenue;
    double store4barheight = store4revenue * scaleheight;
    double store4hz = positionmargin + 3*rectwidth + 3*rectspace;
    double store4vert = 480 - store4barheight;

    //create store 4 bar graph rectangle
    sf :: RectangleShape store4bar;
    store4bar.setFillColor(sf::Color::Green);
    store4bar.setPosition(store4hz, store4vert);
    sf :: Vector2f store4sz(width4, store4barheight);
    store4bar.setSize(store4sz);

    //set attributes of store 5's revenue bar
    double width5 = rectwidth;
    double store5revenue{};
    storerevenues >> store5revenue;
    double store5barheight = store5revenue * scaleheight;
    double store5hz = positionmargin + 4*rectwidth + 4*rectspace;
    double store5vert = 480 - store5barheight;

    //create store 5 bar graph rectangle
    sf :: RectangleShape store5bar;
    store5bar.setFillColor(sf::Color::Green);
    store5bar.setPosition(store5hz, store5vert);
    sf :: Vector2f store5sz(width5, store5barheight);
    store5bar.setSize(store5sz);

    //set attributes of total revenue bar
    double widtht = rectwidth;
    double totalrevenue = store1revenue + store2revenue + store3revenue + store4revenue + store5revenue;
    double totalstorebarheight = totalrevenue * scaleheight;
    double totalstorehz = positionmargin + 5*rectwidth + 5*rectspace;
    double totalstorevert = 480 - totalstorebarheight;

    //create total revenue bar graph rectangle
    sf :: RectangleShape totalrevbar;
    totalrevbar.setFillColor(sf::Color::Green);
    totalrevbar.setPosition(totalstorehz, totalstorevert);
    sf :: Vector2f totalstoresz(widtht, totalstorebarheight);
    totalrevbar.setSize(totalstoresz);

    //label all bars on bar chart
    int fontpositionvertical = 500;
        sf::Font courier;
        courier.loadFromFile("Courier New.ttf");

        //label store 1 revenue
        sf::Text store1word("Store 1", courier, 20);
        store1word.setPosition(store1hz, fontpositionvertical);
        store1word.setFillColor(sf::Color::White);
        //label store 2 revenue
        sf::Text store2word("Store 2", courier, 20);
        store2word.setPosition(store2hz, fontpositionvertical);
        store2word.setFillColor(sf::Color::White);
        //label store 3 revenue
        sf::Text store3word("Store 3", courier, 20);
        store3word.setPosition(store3hz, fontpositionvertical);
        store3word.setFillColor(sf::Color::White);
        //label store 4 revenue
        sf::Text store4word("Store 4", courier, 20);
        store4word.setPosition(store4hz, fontpositionvertical);
        store4word.setFillColor(sf::Color::White);
        //label store 5 revenue
        sf::Text store5word("Store 5", courier, 20);
        store5word.setPosition(store5hz, fontpositionvertical);
        store5word.setFillColor(sf::Color::White);
        //label total store revenue
        sf::Text totalword("Total Revenue", courier, 20);
        totalword.setPosition(totalstorehz, fontpositionvertical);
        totalword.setFillColor(sf::Color::White);



    //end of configuration
    //drawing shapes on graphic window
    while (window.isOpen())
    { 
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(store1bar);
        window.draw(store1bar);
        window.draw(store2bar);
        window.draw(store3bar);
        window.draw(store4bar);
        window.draw(store5bar);
        window.draw(totalrevbar);
        window.draw(store1word);
        window.draw(store2word);
        window.draw(store3word);
        window.draw(store4word);
        window.draw(store5word);
        window.draw(totalword);
        window.draw(xaxis);
        window.draw(yaxis);
        window.display();
    }
    return 0;

}