#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include "pendulum.hpp"
#define PI 3.14159265

using namespace sf;

///*
void tracer(RenderWindow &window,CircleShape first,CircleShape second, CircleShape center);

int main(){

    sf::RenderWindow window(sf::VideoMode(1000,1000),"Pendulum",sf::Style::Default);
    window.setFramerateLimit(60);
    //window.setVerticalSyncEnabled(true);
    // changement de la position de la fenêtre (relativement au bureau)
    //window.setPosition(sf::Vector2i(10,50));
    int number(30);
    CircleShape center(window.getSize().y/(2*(number-1)));
    center.setPosition(window.getSize().x/2-center.getRadius(),window.getSize().y/2-center.getRadius());
    center.setFillColor(Color(102,255,255,255));
    CircleShape first(window.getSize().y/(2*(number-1)));
    first.setFillColor(Color(102,255,255,255));
    CircleShape second(window.getSize().y/(2*(number-1)));
    second.setFillColor(Color(102,255,255,255));

    long double position_x,position_y,theta1,theta2,dtheta1,dtheta2,l1,l2,m1,m2,J1,J2;
    /*
    std::cout << "put the lenght of the first pendulum \n" <<std::endl;
    std::cin >> l1;
    std::cout << "put the lenght of the second pendulum \n" <<std::endl;
    std::cin >> l2;
    std::cout << "put the weight of the first pendulum \n" <<std::endl;
    std::cin >> m1;
    std::cout << "put the weight of the second pendulum \n" <<std::endl;
    std::cin >> m2;
    std::cout << "put the inerti mass of the first pendulum \n" <<std::endl;
    std::cin >> J1;
    std::cout << "put the inerti mass of the second pendulum \n" <<std::endl;
    std::cin >> J2;
    std::cout << "put the initial angle of the first pendulum \n" <<std::endl;
    std::cin >> theta1;
    std::cout << "put the initial angle velocity of the first pendulum" <<std::endl;
    std::cin >> dtheta1;
    std::cout << "put the initial angle of the second pendulum \n" <<std::endl;
    std::cin >> theta2;
    std::cout << "put the initial angle velocity of the second pendulum" <<std::endl;
    std::cin >> dtheta2;
    */

    theta1=50;
    theta2=50;
    dtheta1=0;
    dtheta2=0;
    l1=100;
    l2=50;
    m1=100;
    m2=10;
    J1=1;
    J2=1;

    long double h=0.3;
    bool Pause=false;
    Pendulum pendulum(theta1,theta2,dtheta1,dtheta2,l1,l2,m1,m2,J1,J2);
    
    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event) || Pause){

            if(event.type==sf::Event::Closed){
                window.close();
            }
            if(event.type==Event::KeyPressed && event.key.code == sf::Keyboard::Space){
                if(Pause){
                    Pause=false;
                }
                else{
                    Pause=true;
                }
            }
        }

        // Update
        theta1=pendulum.get_theta1();
        theta2=pendulum.get_theta2();
        std::cout<< "t1" <<theta1 << std::endl;
        std::cout << "t2"<<theta2 << std::endl;
        l1=pendulum.get_l1();
        l2=pendulum.get_l2();
        position_x=window.getSize().x/2-first.getRadius()+l1*sin(theta1*PI/180);
        position_y=window.getSize().y/2-first.getRadius()+l1*cos(theta1*PI/180);
        long double position_x1=window.getSize().x/2-first.getRadius()+l1*sin(theta1*PI/180)+l2*sin(theta2*PI/180);
        long double position_y1=window.getSize().y/2-first.getRadius()+l1*cos(theta1*PI/180)+l2*cos(theta2*PI/180);
        std::cout<<"x"<<position_x<<"y"<<position_y<<std::endl;
        std::cout<<"x1"<<position_x1<<"y1"<<position_y1<<std::endl;
        first.setPosition(position_x,position_y);
        second.setPosition(position_x1,position_y1);

        pendulum.pas_euler(h);
        // Draw
        
        window.clear(Color(96, 80, 220,255));

        
        sf::Vertex line_abscisse[] ={
            sf::Vertex(sf::Vector2f(0,window.getSize().y/2),sf::Color::Black),
            sf::Vertex(sf::Vector2f(window.getSize().x,window.getSize().y/2),sf::Color::Black)
        };
        sf::Vertex line_ordonnee[] ={
            sf::Vertex(sf::Vector2f(window.getSize().x/2,0),sf::Color::Black),
            sf::Vertex(sf::Vector2f(window.getSize().x/2,window.getSize().y),sf::Color::Black)
        };
        window.draw(line_abscisse,2,sf::Lines);
        window.draw(line_ordonnee,2,sf::Lines);

        window.draw(center);
        window.draw(first);
        window.draw(second);


        tracer(window,first,second,center);
        // fin de la frame courante, affichage de tout ce qu'on a dessiné
        window.display();
        }

    return 0;
}
///*
void tracer(RenderWindow &window, CircleShape first, CircleShape second, CircleShape center){


        sf::Vertex line[] ={
            sf::Vertex(sf::Vector2f(center.getPosition().x+center.getRadius(),center.getPosition().y+center.getRadius()),sf::Color::Black),
            sf::Vertex(sf::Vector2f(first.getPosition().x+center.getRadius(),first.getPosition().y+center.getRadius()),sf::Color::Black)
        };

        window.draw(line,2,sf::Lines);

        sf::Vertex line2[]={
            sf::Vertex(sf::Vector2f(first.getPosition().x+center.getRadius(), first.getPosition().y+center.getRadius()),sf::Color::Black),
            sf::Vertex(sf::Vector2f(second.getPosition().x+center.getRadius(), second.getPosition().y+center.getRadius()),sf::Color::Black)
        };
    
        window.draw(line2,2,sf::Lines);
    
}
//*/
