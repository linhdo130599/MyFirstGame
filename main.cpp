#include<iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include<sstream>
#include <string>
#include<cstdlib>
#include<ctime>

using namespace sf;
using namespace std;
struct point
{ int x,y;};

int main()
{

    srand(time(0));
//Basic Settings
    RenderWindow app(VideoMode(400, 533), "Rocket GO !!!");
    app.setFramerateLimit(60);

    Texture t1,t2,t3,t4;
    t1.loadFromFile("images/galaxy.png");
    t2.loadFromFile("images/bacthem.png");
    t3.loadFromFile("images/rocketplay.png");
    t4.loadFromFile("images/explosion_game.png ");

    Sprite sBackground(t1), sPlat(t2), sPers(t3), sExplosion(t4);
//Set plat
    point plat[20];

    for (int i=0;i<10;i++)
      {
       plat[i].x=rand()%400;
       plat[i].y=rand()%533;
      }

	int x=100,y=100,h=200;
    float dx=0,dy=0;

    while (app.isOpen())
    {

        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }
//Control Keyboard
    if (Keyboard::isKeyPressed(Keyboard::Right)) x+=3;
    if (Keyboard::isKeyPressed(Keyboard::Left)) x-=3;
//Jumping by Rocket
    dy+=0.2;
    y+=dy;
    if (y>500)  {dy=-10;
    app.close();}

//Pull the screen up
	if (y<h)
    for (int i=0;i<10;i++)
    {
      y=h;
      plat[i].y=plat[i].y-dy;
      if (plat[i].y>533) {plat[i].y=0; plat[i].x=rand()%400;}
    }
//Set speed of Rocket
	for (int i=0;i<10;i++)
    if ((x+50>plat[i].x) && (x+20<plat[i].x+68)
    && (y+70>plat[i].y) && (y+70<plat[i].y+14) && (dy>0))  dy=-10;

//Score Objects
    int score = 0;

    sf::Font arial;
    arial.loadFromFile("images/arial.ttf");

    std::ostringstream ssScore;
    ssScore << "Score: " << score;

    sf::Text lblScore;
    lblScore.setCharacterSize(30);
    lblScore.setPosition({ 10, 10 });
    lblScore.setFont(arial);
    lblScore.setString(ssScore.str());
    app.draw(lblScore);
    //end

	sPers.setPosition(x,y);

    app.draw(sBackground);
    app.draw(sPers);
    for (int i=0;i<10;i++)
    {
    sPlat.setPosition(plat[i].x,plat[i].y);
    app.draw(sPlat);
    }

    app.display();
}
    return 0;
}
