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
    //Desactivation de la repetition des inputs lors d'appui prolonge
    app.setKeyRepeatEnabled(false);
    //Creation d'une seed pour le random
    srand (time(NULL));




    //Horloge Globale et par Frame
    Clock clock;
    Clock deltaClock;
    Time deltaTime;
    //Valeur de gravit�


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

    Niveau niveau1("niveau.png",2.5, Vector2f(0,-20),-.0010f,645);


    Niveau currentLevel = niveau1;

    //Camera principale du jeu
    Cam cam;
    cam.setBorders(currentLevel);



    //Declaration et assignation des Sprites des ennemi

       /*
        Ennemi *lstEnnemis;

        lstEnnemis = new Ennemi[nbEnnemis];
        for (int i = 0; i < nbEnnemis; i++)
        {
            //1 chance sur 2 patate/poule
            int typeEnnemi = rand() %2;

            if (typeEnnemi == 1){
                lstEnnemis[i].spriteEnnemi.setTexture(texturePatate);
                lstEnnemis[i].speed = 400.0f;
                lstEnnemis[i].attackSpeed = 1.0f;
                lstEnnemis[i].attack = 10.0f;
            } else {
                lstEnnemis[i].spriteEnnemi.setTexture(texturePoule);
                lstEnnemis[i].speed = 600.0f;
                lstEnnemis[i].attackSpeed = 2.0f;
                lstEnnemis[i].attack = 15.0f;
            }

                lstEnnemis[i].spriteEnnemi.setScale(0.2f,0.2f);

                float posEnnemi = (rand()%6000);
                lstEnnemis[i].spriteEnnemi.setPosition(posEnnemi,600);
        }
            */






    //Systeme de son
        //On declare un buffer pour un son court
        //SoundBuffer buffer;
        //On assigne un son au buffer
         //if (!buffer.loadFromFile("0453.ogg"))
            //return -1;

        //On cree le son
        //Sound sound;
        //On assigne le buffer au son
        //sound.setBuffer(buffer);


    //Boucle de jeu
    while (app.isOpen())
    {
        deltaTime = deltaClock.restart();
        //On cr�e un event
        Event event;
        //On scanne l'event pour r�aliser des actions ponctuelles, a la PREMIERE frame
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
            if (player.isInBounds(currentLevel) )
            {
                player.move(Vector2f(-1.0,0.0),player.getSpeed(),deltaTime);
                player.jump(0.15);
                player.setLookDir(-1);
                //spritePp.rotate(-speed * deltaTime.asSeconds());
            }



        }


        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            if (player.getSprite().getPosition().x <= currentLevel.getSprite().getGlobalBounds().width - 25 )
            {
                player.move(Vector2f(1.0,0.0),player.getSpeed(),deltaTime);
                player.jump(0.15);
                player.setLookDir(1);
                //spritePp.rotate(-speed * deltaTime.asSeconds());
            }

        }


        player.updateYMovement(currentLevel,deltaTime);

        if (Keyboard::isKeyPressed(Keyboard::P))
        {
            std::cout <<"velocy : "<< player.getYVelocity() << std::endl;


        }
        if (Keyboard::isKeyPressed(Keyboard::J))
        {
            std::cout <<"camPos "<< cam.getView().getCenter().x << std::endl;


        }

        cam.update(currentLevel,player,deltaTime);

        player.anim();

        app.draw(currentLevel.getSprite());
        app.draw(player.getSprite());

        //On configure la cam�ra sur view1
        app.setView(cam.getView());

        //On affiche la fenetre
        app.display();



    }

    return EXIT_SUCCESS;
}
