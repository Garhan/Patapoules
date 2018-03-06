#include "Cam.h"
#include "Niveau.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
Cam::Cam(){





}

Cam::Cam(sf::Vector2f center){

    this->view.setCenter(center);



}

sf::View Cam::getView(){

    return this->view;

}
void Cam::setBorders(){
    this->minBorder = this->view.getCenter().x-(this->view.getSize().x/2);
    this->maxBorder = this->view.getCenter().x+(this->view.getSize().x/2);

}


void Cam::setBorders(float minB, float maxB){

    this->minBorder = minB;
    this->maxBorder = maxB;


}

void Cam::setBorders(Niveau currentLevel){

    this->minBorder = currentLevel.getMinBorder();
    this->maxBorder = currentLevel.getMaxBorder();


}

void Cam::update(Niveau currentLevel,Player player,sf::Time deltaTime){


    if (player.getSprite().getPosition().x>currentLevel.getMinBorder()+this->getView().getSize().x/2&& player.getSprite().getPosition().x<currentLevel.getMaxBorder()-this->getView().getSize().x/2){

        this->view.setCenter(player.getSprite().getPosition().x,this->view.getCenter().y);
    }else{

    }
//player.getSprite().getPosition().x,this->getView().getCenter().y
}

