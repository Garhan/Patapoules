#ifndef NIVEAU_H
#define NIVEAU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
class Niveau{

    private :
        float gravity;
        float ground;
        sf::Sprite sprite;
        sf::Texture textureNiv;

    public :
        Niveau(std::string filename, float scale,sf::Vector2f shift,float gravity,float ground);
        sf::Sprite& getSprite();
        float getGravity();
        float getGround();




};

    //Declaration du sprite du Niveau
    /*    Sprite spriteNiv;

        //Assignation de la texture
        spriteNiv.setTexture(textureNiv);
        //Ajustement Taille et positionnement
        spriteNiv.setScale(Vector2f(5.0f,5.0f));
        spriteNiv.setPosition(Vector2f(0,-2100));
*/
#endif
