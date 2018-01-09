#ifndef PLAYER_H
#define PLAYER_H

#include "Niveau.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
class Player{

    private :

        int vie;
        int vieMax=500;
        int attack;
        int speed;
        sf::Sprite sprite;
        sf::Texture texturePp;
        bool isDead;
        bool isJumping = true;
        float yVelocity;

    public :

        Player(std::string filename,sf::Vector2f scale,sf::Vector2f selfOrigin,sf::Vector2f startPosition,int attack, int speed);

        void move(sf::Vector2f dir,float speed,sf::Time deltaTime);
        void jump();
        void updateYMovement(Niveau &currentLevel);

        sf::Sprite& getSprite();
        int getSpeed();
        int getAttack();
        bool getJumping();
        float getYVelocity();


        void setJumping(bool jumping);
        void setYVelocity(float velocity);


    };


#endif
