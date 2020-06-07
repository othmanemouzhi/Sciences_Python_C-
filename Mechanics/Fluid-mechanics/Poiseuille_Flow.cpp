
// BEFORE COMPILE, INSTALL SFML via https://www.sfml-dev.org/download-fr.php
// THEN COMPILE WITH : g++ Poiseuille_Flow.cpp -o Poiseuille_Flow.exe sfml-app -lsfml-graphics -lsfml-window -lsfml-system
// EXECUTE WITH ./Poiseuille_Flow.exe

// TO CHANGE THE VELOCITY OF THE FLOW, CHANGE THE VARIABLE vmax LINE 34

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <time.h>

// ECOULEMENT DE POISEUILLE

using namespace sf;

int absolue(int n){
    if(n<0){
        return -n;
    }
    return n;
}

int main(){

    RenderWindow window(VideoMode(640,480),"Poiseuille",sf::Style::Default);
    window.setFramerateLimit(60);

    int number=30;
    float vmax=0.4f;
    float vitesse[number];
    for(int i=0;i<number;i++){
        vitesse[number]=vmax*(1-(i-number/2)*(i-number/2)/(window.getSize().y*window.getSize().y));

    }

    CircleShape particule(window.getSize().y/(2*(number-1)));
    //particule.setFillColor(Color::Blue);

    std::vector<CircleShape> particules_types;

    for(int i=0;i<number;i++){
        particule.setPosition(-2*particule.getRadius(),(2*i)*particule.getRadius());
        //particule.setFillColor(Color(255*(1-(number/2-i)*(number/2-i)/(number*number)),10,0));
        particule.setFillColor(Color(255,absolue(number/2-i)*500/number,0));
        particules_types.push_back(CircleShape(particule));
    }

    std::vector<CircleShape> particules1;
    particules1.push_back(particule);

    std::vector<std::vector<CircleShape>> particules;
    for(int i=0;i<number;i++){
        particules.push_back(particules1);
        particules[i][0].setPosition(-2*particule.getRadius(),(2*i)*particule.getRadius());
    }

    int timeinsert[number];
    for(int i=0;i<number;i++){
        timeinsert[i]=0;
    }

    bool gamePause=false;

    while(window.isOpen()){

        Event event;

        while(window.pollEvent(event) || gamePause){

            if(event.type==Event::Closed){
                window.close();
            }
            if(event.type==Event::KeyPressed && event.key.code ==sf::Keyboard::Escape){
                window.close();
            }
            if(event.type==Event::KeyPressed && event.key.code == sf::Keyboard::Space){
                if(gamePause){
                    gamePause=false;
                }
                else{
                    gamePause=true;
                }
            }
        }
        // update

        for(int i=0;i<number;i++){

            if(particules[i][particules[i].size()-1].getPosition().x>particule.getRadius()+window.getSize().x){
                particules[i].erase(particules[i].begin()+particules[i].size()-1);
                particules[i].push_back(particules_types[i]);
            }
            if(timeinsert[i]<=5){
                timeinsert[i]++;
            }
            else{
                particules[i].push_back(particules_types[i]);
                timeinsert[i]=0;
            }   
            for(int k=0;k<particules[i].size();k++){
                /*
                if(i<number/2){
                    particules[i][k].move(2.f*(1-i*i*0.2),0);
                    //particules[i][k].move(vitesse[i],0);
                }
                else{
                    particules[i][k].move(2.f*(1-(number-i)*(number-i)*0.2),0);
                    //particules[i][k].move(vitesse[i],0);
                }
                */
                particules[i][k].move(2.f*(1-(number/2-i)*(number/2-i)*400.f/(window.getSize().y*window.getSize().y)),0);
            }
        }
        
        window.clear(Color::White);
        // draw

        for(int i=0;i<number;i++){
            for(int k=0;k<particules[i].size();k++){
                window.draw(particules[i][k]);
            }
        }

        window.display();

    }

    return 0;
}
