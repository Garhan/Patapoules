#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Player.h"
#include "Niveau.h"
#include "Ennemi.h"
#include "Cam.h"




int main()
{
    using namespace sf;

    //Creation de la fenetre
    RenderWindow app(VideoMode(800, 600), "SFML window");
    app.setVerticalSyncEnabled(false);
    //Desactivation de la repetition des inputs lors d'appui prolonge
    app.setKeyRepeatEnabled(false);
    //Creation d'une seed pour le random
    srand (time(NULL));




    //Horloge Globale et par Frame
    Clock clock;
    Clock deltaClock;
    Time deltaTime;
    //Valeur de gravité


    //Declaration et chargement des Textures

        //Patate
        Texture texturePatate;
        if (!texturePatate.loadFromFile("patate.png"))
            return -1;
        //Poule
        Texture texturePoule;
        if (!texturePoule.loadFromFile("poule.png"))
            return -1;
        //Patapoule
        Texture texturePp;
        if (!texturePp.loadFromFile("patapoule.png"))
            return -1;


    Player player("patapoule.png",IntRect(0,0,500,500),Vector2f(0.2f, 0.2f),Vector2f(250.0f,250.0f),Vector2f(200,650),2,200,deltaTime);

    Niveau niveau1("niveau.png",2.5, Vector2f(0,-20),-.0010f,645,1);

    Niveau currentLevel = niveau1;

    //Camera principale du jeu
    Cam cam;
    cam.setBorders(currentLevel);


    //Boucle de jeu
    while (app.isOpen())
    {
        deltaTime = deltaClock.restart();
        //On crée un event
        Event event;
        //On scanne l'event pour réaliser des actions ponctuelles, a la PREMIERE frame
        while (app.pollEvent(event))
        {
            //On ferme la fenetre quand on appuie sur la croix rouge
            if (event.type == Event::Closed)
                app.close();

        }


        //On clear le tableau
        app.clear();


        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            player.jump(0.4);


        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            if (currentLevel.isPlayerIn(player) )
            {
                player.move(Vector2f(-1.0,0.0),player.getSpeed(),deltaTime);
                player.jump(0.15);
                player.setLookDir(-1);
                //spritePp.rotate(-speed * deltaTime.asSeconds());
            }



        }


        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            if (currentLevel.isPlayerIn(player) )
            {
                player.move(Vector2f(1.0,0.0),player.getSpeed(),deltaTime);
                player.jump(0.15);
                player.setLookDir(1);
                //spritePp.rotate(-speed * deltaTime.asSeconds());
            }

        }



        if (Keyboard::isKeyPressed(Keyboard::P))
        {
            std::cout <<"velocy : "<< player.getYVelocity() << std::endl;


        }
        if (Keyboard::isKeyPressed(Keyboard::J))
        {
            std::cout <<"camPos "<< cam.getView().getCenter().x << std::endl;


        }

        cam.update(currentLevel,player,deltaTime);

        //(currentLevel.getEnnemies()[1]).getSprite().setPosition(200.0f,400.0f);
        std::cout << (currentLevel.getEnnemies()[0]).getSprite().getPosition().x <<std::endl;

       // player.anim();
        std::cout <<player.getSprite().getPosition().x<<std::endl;
        //currentLevel.updateEnnemis(player,app);

        app.draw((currentLevel.getEnnemies()[0]).getSprite());
        currentLevel.updatePlayer(player, deltaTime);
        app.draw(currentLevel.getSprite());
        app.draw(player.getSprite());

        //On configure la caméra sur view1
        app.setView(cam.getView());

        //On affiche la fenetre
        app.display();



    }

    return EXIT_SUCCESS;
}
