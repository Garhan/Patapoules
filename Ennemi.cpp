#include "Ennemi.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
Ennemi::Ennemi(int type){

    switch (type){

        case 0 : // Poule
        {
            speed = 150;
            attack = 2.5;
            if(!textureEn.loadFromFile("patapoule.png"))
            std::cout <<"ERREUR DE CHARGEMENT";

            std::cout <<"balpoule";

        }break;
        case 1 : //Patate
        {
            speed = 125;
            attack = 4;
            if(!textureEn.loadFromFile("patate.png"))
            std::cout <<"ERREUR DE CHARGEMENT";

            std::cout <<"balpatate";

        }break;



        //sprite.setPosition(sf::Vector2f(std::rand()%2000+500,650));
    }
    std::cout <<" balINIT ";
    sprite.setTexture(textureEn);

    sprite.setScale(sf::Vector2f(0.2f, 0.2f));
    sprite.setOrigin(sf::Vector2f(250.0f,250.0f));
    sprite.setPosition(sf::Vector2f(200.0f,645.0f));
    std::cout <<"banane";
    std::cout << this->getSprite().getTexture()->getSize().x <<std::endl;

}

bool Ennemi::detect(Player player){
    if (sprite.getPosition().x-player.getSprite().getPosition().x<200||player.getSprite().getPosition().x-sprite.getPosition().x<200){
        active =true;
        return true;
    }
    return false;
}

sf::Sprite& Ennemi::getSprite(){

        return sprite;

}
