#include "Niveau.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
Player::Player(std::string filename,sf::IntRect idle,sf::Vector2f scale,sf::Vector2f selfOrigin,sf::Vector2f startPosition,int attack, int speed,sf::Time &deltaTime){

        this->attack = attack;
        this->speed = speed;
        if(!texturePp.loadFromFile(filename))
            std::cout <<"ERREUR DE CHARGEMENT";


        this->sprite.setTexture(texturePp);
        sprite.setTextureRect(idle);


        this->sprite.setScale(scale);
        this->sprite.setOrigin(selfOrigin);
        this->sprite.setPosition(startPosition);

        animTimer=0;

}

void Player::blink(){
    switch (animTimer){
    case 70 :sprite.setTextureRect(sf::IntRect(500,0,500,500));

    break;
    case 73 : sprite.setTextureRect(sf::IntRect(1000,0,500,500));
    break;

    case 76 : sprite.setTextureRect(sf::IntRect(1500,0,500,500));
    break;
    case 79 : sprite.setTextureRect(sf::IntRect(000,0,500,500));

    }
}

void Player::anim(){
    animTimer++;

    blink();

    if (animTimer >= 200)
        animTimer = 0;
}



void Player::move(sf::Vector2f dir, float speed,sf::Time deltaTime){

        sprite.move(dir * speed * deltaTime.asSeconds());

}
void Player::jump(float jumpForce){

    if(this->isJumping==false)
    {
        this->setYVelocity(jumpForce);
        //~= 0.25
    }

    this->setJumping(true);
}

void Player::setLookDir(int dir){


        this->sprite.setScale(fabs(this->sprite.getScale().x)*dir,this->sprite.getScale().y);

}

void Player::updateYMovement(Niveau &currentLevel, sf::Time &deltaTime){

        if (this->getSprite().getPosition().y < currentLevel.getGround()){

            this->setYVelocity(this->getYVelocity()+(currentLevel.getGravity()*deltaTime.asMilliseconds()));

            }
    this->setJumping(true);

        if (this->getSprite().getPosition().y == currentLevel.getGround()){
            this->setJumping(false);

        }

        if (this->getSprite().getPosition().y > currentLevel.getGround()){

            this->setYVelocity(0.f);
            this->getSprite().setPosition(this->getSprite().getPosition().x,currentLevel.getGround());
        }


        this->getSprite().setPosition(this->getSprite().getPosition().x,this->getSprite().getPosition().y-(getYVelocity()*deltaTime.asMilliseconds()));

}


bool Player::isInBounds(Niveau &currentlevel){
    sf::FloatRect result;
    bool b3 = currentlevel.getSprite().getGlobalBounds().intersects(this->getSprite().getGlobalBounds(), result);

    return (result ==  this->getSprite().getGlobalBounds());

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


