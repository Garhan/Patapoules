#include "Niveau.h"

Niveau::Niveau(sf::Texture textureNiveau,int nbEnnemis, int scale, int HSol){


        sf::Sprite spriteNiv;

        spriteNiv.setTexture(textureNiveau);

        spriteNiv.setScale(Vector2f(scale,scale));
        spriteNiv.setPosition(Vector2f(0,scale*HSol));


        this->sprite = spriteNiv;
        this->nbEnnemis = nbEnnemis;
        this->HSol = scale*HSol;


}

Niveau::load(){
    app.draw(this->sprite);

}
