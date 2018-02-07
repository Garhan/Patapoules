#include "Cam.h"
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
