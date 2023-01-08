/* Chart Object project
Cosc 051-02
Aya Takegami, Cassie Clark, Nina Jennings*/

// chart definitions in chartobject.cpp
// set up
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using sf::Vector2f;
using sf::RectangleShape;
using sf::Color;
using sf::RenderWindow;

struct barwidthspace{
			float barwidth;
			float barspace;
		};
//declare class and class definition
class Chart {
	//list all private variables and functions
	private:
		float width = 800.f;
		float height = 600.f;
		int numberbars = 4;
		float barheight = 300.f;
		Color axiscolor = sf:: Color::White;
		RectangleShape xaxis;
		RectangleShape yaxis;
		int veryright = 800;
    	int veryleft = 0;
    	int verytop = 0;
    	int verybottom = 600;
    	int axisspace = 10;
		std::vector<RectangleShape> bars;
        void configaxis();
        void configbars();
        barwidthspace computebarwidthspacing();
        float computebarwidth();
        bool isvalidindex(int idx);
        sf::Text projectTitle;
        sf::Font Courier;

	//list all public functions with parameters
	public:
		Chart();
        Chart(int WID, int HIT, int number_bars);
        void setBarHeight(int barindex, int barheight);
		void setBarColor(int idx, Color c);
		void setTitle(string title);
		void setAxisColor(Color c);
        void draw(RenderWindow&window);

};
//create function that enforces invariant on indexes to specify bar in vector
//prevents user from using bad index when using color nad height functions
bool Chart::isvalidindex(int idx){
    bool valid = true;
    if(idx < -1){
        valid = false;
    }
    if(idx >= numberbars){
        valid = false;
    }
    return valid;
}

//create chart, the default constructor for class

Chart::Chart(){
    //bars = std::vector<RectangleShape>(5);
    configaxis();
    configbars(); 
    setTitle("Chart Object");
    //call member functions 
}

//how is this diff from chart above????
Chart::Chart(int WID, int HIT, int number_bars) {
    width = WID;
    height = HIT;
    numberbars = number_bars; 
    configaxis();
    configbars();
    setTitle("Chart Object");
    //bars = std::vector<RectangleShape>(numberbars);
}

//create function that returns structures with width and bar spaces
//how to make called by configabars??
//create struct with width of bars and space between at top of file
//
barwidthspace Chart::computebarwidthspacing(){
    barwidthspace bws;
    bws.barspace = (width / 2) / numberbars;
    bws.barwidth = bws.barspace;
    return bws;


}

//create function to set bar height at a certain point and color
void Chart::setBarHeight(int barindex, int barheight){
    barwidthspace barwidth = computebarwidthspacing();
    if(isvalidindex (barindex)) {
        sf::Vector2f size(barwidth.barwidth, barheight);
        bars[barindex].setSize(size);
        bars[barindex].setPosition(sf::Vector2f(bars[barindex].getPosition().x, (height - barheight - 100)));
    } else {
        cout << "Error, invalid index entered." << endl;
    }
}


//create function to set the color of the bar at an index //for some reason if statement is same
void Chart::setBarColor(int idx, Color c){
    if(isvalidindex (idx)) {
        bars[idx].setFillColor(c);
    } else {
        cout << "Error, invalid index entered." << endl;
    }
}

//create function to set title for the chart
void Chart::setTitle(string title){
    //download font
    Courier.loadFromFile("Courier New.ttf");
    if(!Courier.loadFromFile("Courier New.ttf")){
        cout << "failed" << endl;
    }
    int titleposx = (veryright/2);
    int titleposy = verybottom/12;
    projectTitle.setString(title);
    projectTitle.setFont(Courier);
    projectTitle.setCharacterSize(20);
    projectTitle.setPosition(titleposx, titleposy);
}

//create function to set the axis color
void Chart::setAxisColor(Color c){
    xaxis.setFillColor (c);
    yaxis.setFillColor (c);
}

//create function create axis width, height, color, position
void Chart::configaxis(){
    //declare variables needed for both axis
    setAxisColor(sf::Color::White);
    
    //X Axis
    xaxis.setPosition(100,500);
    Vector2f xaxissize(650,5);
    xaxis.setSize(xaxissize);
    
    //Y Axis
    yaxis.setPosition(100, 100);
    Vector2f yaxissize(5,400);
    yaxis.setSize(yaxissize);
}

//create function to configure each bar's width, height, color, position
//how to make this only accessible from member function??
void Chart::configbars(){
    //temp variables for position and size of bars
    float initialx = 100;
    
    barwidthspace bws = computebarwidthspacing();
    
    //go through vector of bars and set all the values
    for (int i = 0; i < numberbars; i++){
        float initialy = height - 100 - barheight;
        sf::RectangleShape shape;
        sf::Vector2f size(bws.barwidth, barheight);
        shape.setSize(size);
        sf::Vector2f position(initialx, initialy);
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(position);
        bars.push_back(shape);
        initialx += (bws.barwidth + bws.barspace);
    }
    
}




//create function used to draw objects on graphic screen
void Chart::draw(RenderWindow&window){
    for (int i = 0; i < bars.size(); i++){
        window.draw(bars[i]);
    }
    window.draw(xaxis);
    window.draw(yaxis);
    window.draw(projectTitle);
//axis, bars, text, etc.
}



//define all functions
int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
	int WID = 800;

	int HIT = 600;

	int BARNUM = 4;
	
	Chart graph1(WID,HIT, BARNUM);
	
	graph1.setBarColor(1, Color::Red);
	graph1.setBarHeight(1, 500.f);
	graph1.setBarColor(2, Color::Magenta);
	graph1.setBarHeight(2, 200.f);

	while (window.isOpen())
	{
		// run Chart and store result
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		graph1.draw(window);
		
		window.display();
	}

	return 0;
}