#include "Niveau.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
Player::Player(std::string filename,sf::Vector2f scale,sf::Vector2f selfOrigin,sf::Vector2f startPosition,int attack, int speed){

        this->attack = attack;
        this->speed = speed;
        if(!texturePp.loadFromFile(filename))
            std::cout <<"ERREUR DE CHARGEMENT";


        this->sprite.setTexture(texturePp);


        this->sprite.setScale(scale);
        this->sprite.setOrigin(selfOrigin);
        this->sprite.setPosition(startPosition);

}

void Player::move(sf::Vector2f dir, float speed,sf::Time deltaTime){

        sprite.move(dir * speed * deltaTime.asSeconds());

}
void Player::jump(){

    if(this->isJumping==false)
    {
        this->setYVelocity(20);

    }

}

void updateYMovement(Niveau &currentLevel){

        if (this->getSprite().getPosition().x > currentLevel.getGround()){

            this->setYVelocity(this->getYVelocity()-currentLevel.getGravity())
        }

        if (this->getSprite().getPosition().x == currentLevel.getGround()){

            this->setYVelocity(0.f);
        }

        if (this->getSprite().getPosition().x < currentLevel.getGround()){

            this->getSprite().setPosition(this->getSprite().getPosition().x,currentLevel.getGround()+5);
        }




}

sf::Sprite& Player::getSprite(){

        return this->sprite;

}

int Player::getSpeed(){

        return this->speed;

}
int Player::getAttack(){

        return this->attack;

}
bool Player::getJumping(){

        return this->isJumping;

}
float Player::getYVelocity(){

        return this->yVelocity;

}


void Player::setJumping(bool jumping){

        this->isJumping = jumping;

}
void Player::setYVelocity(float velocity){

        this->yVelocity = velocity;

}

