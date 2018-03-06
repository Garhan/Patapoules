#include "Niveau.h"


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
Niveau::Niveau(std::string filename,float scale,sf::Vector2f shift,float gravity,float ground){

        this->gravity = gravity;
        this->ground = ground;


        if(!textureNiv.loadFromFile(filename))
            std::cout <<"ERREUR DE CHARGEMENT";


        this->sprite.setTexture(textureNiv);
        this->sprite.setScale(scale,scale);
        this->sprite.setPosition(shift);




}

sf::Sprite& Niveau::getSprite(){

        return this->sprite;

}
float Niveau::getGround(){

        return this->ground;
}
float Niveau::getGravity(){

        return this->gravity;
}
float Niveau::getMinBorder(){
    return this->getSprite().getGlobalBounds().left;

}
float Niveau::getMaxBorder(){
    return this->getSprite().getGlobalBounds().left+this->getSprite().getGlobalBounds().width;

}
