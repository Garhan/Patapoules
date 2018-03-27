#include "Niveau.h"
#include "Ennemi.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
Niveau::Niveau(std::string filename,float scale,sf::Vector2f shift,float gravity,float ground){

        this->gravity = gravity;
        this->ground = ground;


        if(!textureNiv.loadFromFile(filename))
            std::cout <<"ERREUR DE CHARGEMENT";


        this->sprite.setTexture(textureNiv);
        this->sprite.setScale(scale,scale);
        this->sprite.setPosition(shift);


        ennemiCount = 0;
        std::cout <<"kiwi";

}

Niveau::Niveau(std::string filename,float scale,sf::Vector2f shift,float gravity,float ground,int enCount){

        this->gravity = gravity;
        this->ground = ground;

        if(!textureNiv.loadFromFile(filename))
            std::cout <<"ERREUR DE CHARGEMENT";

        this->sprite.setTexture(textureNiv);
        this->sprite.setScale(scale,scale);
        this->sprite.setPosition(shift);
        ennemiCount = enCount;

        for (int i=0;i<ennemiCount;i++){
            Ennemi ennemi(1);
            std::cout << ennemi.getSprite().getPosition().y <<std::endl;
            ennemiPool.push_back(ennemi);
            std::cout <<" balpushback ";


        }

        std::cout << ennemiPool.at(0).getSprite().getPosition().y <<std::endl;


}

void Niveau::updateEnnemis(Player &player,sf::RenderWindow &app){

    for (int i=0;i<ennemiCount;i++){

            if(ennemiPool[i].detect(player)){

                app.draw(ennemiPool[i].getSprite());

            }



        }
}

void Niveau::updatePlayer(Player &player, sf::Time &deltaTime){

        if (player.getSprite().getPosition().y < this->getGround()){

            player.setYVelocity(player.getYVelocity()+(this->getGravity()*deltaTime.asMilliseconds()));

            }
    player.setJumping(true);

        if (player.getSprite().getPosition().y == this->getGround()){
            player.setJumping(false);

        }

        if (player.getSprite().getPosition().y > this->getGround()){

            player.setYVelocity(0.f);
            player.getSprite().setPosition(player.getSprite().getPosition().x,this->getGround());
        }


        player.getSprite().setPosition(player.getSprite().getPosition().x,player.getSprite().getPosition().y-(player.getYVelocity()*deltaTime.asMilliseconds()));
}

bool Niveau::isPlayerIn(Player &player){
    sf::FloatRect result;
    this->getSprite().getGlobalBounds().intersects(player.getSprite().getGlobalBounds(), result);
    return (result ==  player.getSprite().getGlobalBounds());

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

std::vector<Ennemi> Niveau::getEnnemies(){
    return ennemiPool;

}
