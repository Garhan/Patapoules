#ifndef CAM_H_INCLUDED
#define CAM_H_INCLUDED

#include "Niveau.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Cam{


    private :


        float minBorder;
        float maxBorder;


    public :

        Cam();
        Cam(sf::Vector2f center);
        sf::View view;
        sf::View getView();


        void setBorders();
        void setBorders(float minB, float maxB);
        void setBorders(Niveau currentLevel);

        void update(Niveau currentLevel,Player player,sf::Time deltaTime);














};




#endif // CAM_H_INCLUDED
