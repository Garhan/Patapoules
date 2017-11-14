#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


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

    //Valeur de gravit�
    float gravity = 1000.f;

    //Noombre d'ennemis
    int nbEnnemis = 600;

    //parametres du joueur
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



    //Declaration et assignation des Sprites des ennemis

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

            //Positionnement aleatoire
            float posEnnemi = (rand()%6000);
            spriteEnnemis[i].setPosition(posEnnemi,600);
        }






    //Declaration du sprite patapoule
        Sprite spritePp;

        //Assignation de la texture
        spritePp.setTexture(texturePp);
        //Ajustement Taille, point d'origine et positionnement
        spritePp.setScale(Vector2f(0.1f, 0.1f));
        spritePp.setOrigin(Vector2f(250.0f,250.0f));
        spritePp.setPosition(Vector2f(200,650));





    //Declaration du sprite du Niveau
        Sprite spriteNiv;

        //Assignation de la texture
        spriteNiv.setTexture(textureNiv);
        //Ajustement Taille et positionnement
        spriteNiv.setScale(Vector2f(5.0f,5.0f));
        spriteNiv.setPosition(Vector2f(0,-2100));

    //Systeme de son
        //On declare un buffer pour un son court
        SoundBuffer buffer;
        //On assigne un son au buffer
         if (!buffer.loadFromFile("0453.ogg"))
            return -1;

        //On cree le son
        Sound sound;
        //On assigne le buffer au son
        sound.setBuffer(buffer);


    //Boucle de jeu
    while (app.isOpen())
    {
        Time deltaTime = deltaClock.restart();
        //On cr�e un event
        Event event;
        //On scanne l'event pour r�aliser des actions ponctuelles
        while (app.pollEvent(event))
        {
            //On ferme la fenetre quand on appuie sur la croix rouge
            if (event.type == Event::Closed)
                app.close();

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::T)
                {
                  Time elapsed1 = clock.restart();
                std::cout << elapsed1.asSeconds() << std::endl;
                }

            }


        }


        if(Keyboard::isKeyPressed(Keyboard::Up) && !isJumping)
        {
            playerVelocity.y = -500.f;
            isJumping = true;
        }

        if(isJumping)
        {
            playerVelocity.y += (gravity * deltaTime.asSeconds());
            spritePp.move(playerVelocity * deltaTime.asSeconds());
        }


        if(spritePp.getPosition().y > 670.f)
                {
                        spritePp.setPosition( { spritePp.getPosition().x, 670.f } );
                        isJumping = false;
                }
        app.clear();

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



            if (spritePp.getPosition().x >= 25 )
            {
                spritePp.move(Vector2f(-speed, 0) * deltaTime.asSeconds());
                //spritePp.rotate(-speed * deltaTime.asSeconds());
            }

        }
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

        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            sound.play();
        }
        if (Keyboard::isKeyPressed(Keyboard::P))
        {
            std::cout <<"posy : "<< spritePp.getPosition().y << std::endl;


        }

        app.setView(view1);
        app.display();



    }

    return EXIT_SUCCESS;
}
