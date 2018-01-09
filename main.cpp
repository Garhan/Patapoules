#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Player.h"
#include "Niveau.h"
#include "Ennemi.h"



int main()
{
    using namespace sf;


    //Creation de la fenetre
    RenderWindow app(VideoMode(800, 600), "SFML window");
    //Desactivation de la repetition des inputs lors d'appui prolonge
    app.setKeyRepeatEnabled(false);
    //Creation d'une seed pour le random
    srand (time(NULL));


    //Camera principale du jeu
    View view1;

    //Horloge Globale et par Frame
    Clock clock;
    Clock deltaClock;

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


    Player player("patapoule.png",Vector2f(0.1f, 0.1f),Vector2f(250.0f,250.0f),Vector2f(200,650),2,200);

    Niveau niveau1("niveau.png",5.0, Vector2f(0,-2100),0.2f,670);

    Niveau currentLevel = niveau1;


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
        Time deltaTime = deltaClock.restart();
        //On crée un event
        Event event;
        //On scanne l'event pour réaliser des actions ponctuelles, a la PREMIERE frame
        while (app.pollEvent(event))
        {
            //On ferme la fenetre quand on appuie sur la croix rouge
            if (event.type == Event::Closed)
                app.close();

            /* Debug Clock Frame
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::T)
                {
                  Time elapsed1 = clock.restart();
                std::cout << elapsed1.asSeconds() << std::endl;
                }

            }
            */


        }
        //La structure "if(Keyboard::isKeyPressed(Keyboard::___)) renvoie un booleen a CHAQUE frame

        //On utilise un if(keyboard... pour ne pas avoir a tester une condition dans l'event
        /*if(Keyboard::isKeyPressed(Keyboard::Up) && !isJumping)
        {

            playerVelocity.y = -250.f;
            //On évite le multiple-saut
            isJumping = true;
        }

        //On applique la physique de la gravité//1 chance sur 2 patate/poule
            int typeEnnemi = rand() %2;

            if (typeEnnemi == 1){
                spriteEnnemis[i].setTexture(texturePatate);
            } else {
                spriteEnnemis[i].setTexture(texturePoule);
            }
            //Ajustement de la taille des ennemis
            spriteEnnemis[i].setScale(0.2f,0.2f);

            //Positionnement aleatoire
            float posEnnemi = (rand()%6000);
            spriteEnnemis[i].setPosition(posEnnemi,600);
        if(isJumping)
        {
            playerVelocity.y += (gravity * deltaTime.asSeconds());
            spritePp.move(playerVelocity * deltaTime.asSeconds());
        }

        //On stoppe la chute quand la patapoule touche le sol
        if(spritePp.getPosition().y > 670.f)
        {
                        spritePp.setPosition( { spritePp.getPosition().x, 670.f } );
                        isJumping = false;
        } */

        //On clear le tableau
        app.clear();

        //On dessine la patapoule et tous les ennemis avec app.draw

      /*  for (int i = 0; i < nbEnnemis; i=i+1)
        {
            if ((spriteEnnemis[i].getPosition().x < spritePp.getPosition().x - ((view1.getSize().x)/2) ||(spriteEnnemis[i].getPosition().x > spritePp.getPosition().x+view1.getSize().x)/2))

            app.draw(spriteEnnemis[i]);

        }
        */
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            player.jump();


        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            if (player.getSprite().getPosition().x >= 25 )
            {
                player.move(Vector2f(-1.0,0.0),player.getSpeed(),deltaTime);
                //spritePp.rotate(-speed * deltaTime.asSeconds());
            }

        }

        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            if (player.getSprite().getPosition().x <= currentLevel.getSprite().getGlobalBounds().width - 25 )
            {
                player.move(Vector2f(1.0,0.0),player.getSpeed(),deltaTime);
                //spritePp.rotate(-speed * deltaTime.asSeconds());
            }

        }
        player.updateYMovement(currentLevel);
        /*
        //movement vers la gauche
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            //tant que la camera n'est pas trop proche de la limite, on la bouge avec la patapoule
            if ( (spritePp.getPosition().x >= (view1.getSize().x)/2) && (spritePp.getPosition().x <= spriteNiv.getGlobalBounds().width-(view1.getSize().x/2)))
                //Camera is not exiting level
                view1.move(Vector2f(-speed, 0)* deltaTime.asSeconds());


            //tant que la patapoule n'est pas trop proche de la limite, on la bouge vers la gauche
            if (spritePp.getPosition().x >= 25 )
            {
                spritePp.move(Vector2f(-speed, 0) * deltaTime.asSeconds());
                //spritePp.rotate(-speed * deltaTime.asSeconds());
            }

        }

        //Idem Droite
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {


            if ((spritePp.getPosition().x >= (view1.getSize().x)/2) && (spritePp.getPosition().x <= spriteNiv.getGlobalBounds().width-(view1.getSize().x/2)))
                //Camera is not exiting level
                view1.move(Vector2f(speed, 0)* deltaTime.asSeconds());

            if (spritePp.getPosition().x <= spriteNiv.getGlobalBounds().width - 25 )
            {
                spritePp.move(Vector2f(speed, 0) * deltaTime.asSeconds());
                //spritePp.rotate(speed * deltaTime.asSeconds());
            }

        }
        //Test son
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            sound.play();
        }


        if (Keyboard::isKeyPressed(Keyboard::P))
        {
            std::cout <<"posy : "<< spritePp.getPosition().y << std::endl;


        }
*/
        app.draw(currentLevel.getSprite());
        app.draw(player.getSprite());

        //On configure la caméra sur view1
        app.setView(view1);

        //On affiche la fenetre
        app.display();



    }

    return EXIT_SUCCESS;
}
