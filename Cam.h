#ifndef CAM_H_INCLUDED
#define CAM_H_INCLUDED


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Cam{


    private :

        sf::View view;
        float minBorder;
        float maxBorder;


    public :

        Cam();
        Cam(sf::Vector2f center);
        sf::View getView();











};




#endif // CAM_H_INCLUDED
