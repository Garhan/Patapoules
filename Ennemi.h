#ifndef ENNEMI_H
#define ENNEMI_H
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
class Ennemi{

    private :
        int vie;
        int vieMax;
        float attack;
        float attackSpeed;
        float speed;

        bool active = 0;

        sf::Sprite sprite;
        sf::Texture textureEn;

    public :

        Ennemi(int type);
        bool detect(Player player);

        sf::Sprite& getSprite();

};
#endif
