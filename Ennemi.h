#ifndef ENNEMI_H
#define ENNEMI_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
class Ennemi{

    public :
        int vie;
        int vieMax;
        float attack;
        float attackSpeed;
        float speed;

        enum TypeEnnemi{PATATE=1, POULE =2};

        int sprite;
        bool isDead;
    private :

        Ennemi();

};
#endif
