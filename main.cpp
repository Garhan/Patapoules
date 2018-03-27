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

    //Création de la fenetre
    RenderWindow app(VideoMode(800, 600), "SFML window");
    //Désactivation de la répétition des inputs lors d'appui prolongé
    app.setKeyRepeatEnabled(false);
    //Création d'une seed pour le random
    srand (time(NULL));

    View view1;

    Clock clock;
    Clock deltaClock;

    float gravity = 1000.f;

    int nbEnnemis = 600;

    float speed = 500.0f;
    Vector2f playerVelocity;
    bool isJumping = true;



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
        //Niveau
        Texture textureNiv;
    if (!textureNiv.loadFromFile("niveau.png"))
        return -1;



    //Déclaration et assignation des Sprites des ennemis

        Sprite *spriteEnnemis;

        spriteEnnemis = new Sprite[nbEnnemis];

        for (int i = 0; i < nbEnnemis; i=i+1)
        {
            //1 chance sur 2 patate/poule
            int typeEnnemi = rand() %2;

            if (typeEnnemi == 1){
                spriteEnnemis[i].setTexture(texturePatate);
            } else {
                spriteEnnemis[i].setTexture(texturePoule);
            }
            //Ajustement de la taille des ennemis
            spriteEnnemis[i].setScale(0.2f,0.2f);

            //Positionnement aléatoire
            float posEnnemi = (rand()%6000);
            spriteEnnemis[i].setPosition(posEnnemi,600);
        }






    //Déclaration du sprite patapoule
        Sprite spritePp;

        //Assignation de la texture
        spritePp.setTexture(texturePp);
        //Ajustement Taille, point d'origine et positionnement
        spritePp.setScale(Vector2f(0.1f, 0.1f));
        spritePp.setOrigin(Vector2f(250.0f,250.0f));
        spritePp.setPosition(Vector2f(200,650));





    //Déclaration du sprite du Niveau
        Sprite spriteNiv;

        //Assignation de la texture
        spriteNiv.setTexture(textureNiv);
        //Ajustement Taille et positionnement
        spriteNiv.setScale(Vector2f(5.0f,5.0f));
        spriteNiv.setPosition(Vector2f(0,-2100));

    //Systeme de son
        //On déclare un buffer pour un son court
        SoundBuffer buffer;
        //On assigne un son au buffer
         if (!buffer.loadFromFile("0453.ogg"))
            return -1;

        //On crée le son
        Sound sound;
        //On assigne le buffer au son
        sound.setBuffer(buffer);



    while (app.isOpen())
    {
        Time deltaTime = deltaClock.restart();
        // Process events
        Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == Event::Closed)
                app.close();

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::T)
                {
                  Time elapsed1 = clock.restart();
                std::cout << elapsed1.asSeconds() << std::endl;
                }

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

        if(Keyboard::isKeyPressed(Keyboard::Up) && !isJumping)
        {
            playerVelocity.y = -500.f;
            isJumping = true;
        }


        }


        //On clear le tableau
        app.clear();


        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            player.jump(0.4);

        app.draw(spriteNiv);
        app.draw(spritePp);
        for (int i = 0; i < nbEnnemis; i=i+1)
        {
            if ((spriteEnnemis[i].getPosition().x < spritePp.getPosition().x - ((view1.getSize().x)/2) ||(spriteEnnemis[i].getPosition().x > spritePp.getPosition().x+view1.getSize().x)/2))

            app.draw(spriteEnnemis[i]);


        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {

            if ( (spritePp.getPosition().x >= (view1.getSize().x)/2) && (spritePp.getPosition().x <= spriteNiv.getGlobalBounds().width-(view1.getSize().x/2)))
                //Camera is not exiting level
                view1.move(Vector2f(-speed, 0)* deltaTime.asSeconds());


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


                spritePp.move(Vector2f(-speed, 0) * deltaTime.asSeconds());
                //spritePp.rotate(-speed * deltaTime.asSeconds());
            }

        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {


            if ((spritePp.getPosition().x >= (view1.getSize().x)/2) && (spritePp.getPosition().x <= spriteNiv.getGlobalBounds().width-(view1.getSize().x/2)))
                //Camera is not exiting level
                view1.move(Vector2f(speed, 0)* deltaTime.asSeconds());


        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            if (currentLevel.isPlayerIn(player) )
            {

                player.move(Vector2f(1.0,0.0),player.getSpeed(),deltaTime);
                player.jump(0.15);
                player.setLookDir(1);
                //spritePp.rotate(-speed * deltaTime.asSeconds());

                spritePp.move(Vector2f(speed, 0) * deltaTime.asSeconds());
                //spritePp.rotate(speed * deltaTime.asSeconds());

            }

        }




        if (Keyboard::isKeyPressed(Keyboard::P))

        if (Keyboard::isKeyPressed(Keyboard::S))

        {
            std::cout <<"velocy : "<< player.getYVelocity() << std::endl;


        }

        if (Keyboard::isKeyPressed(Keyboard::J))

        if (Keyboard::isKeyPressed(Keyboard::P))

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
