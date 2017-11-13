#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


int main()
{
    using namespace sf;
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    sf::Clock clock;
    sf::Clock deltaClock;
    float speed = 2500.0f;
    app.setKeyRepeatEnabled(false);
    sf::Vector2f playerVelocity;
    bool isJumping = true;
    float gravity = 1000.f;
    // Load a sprite to display
    sf::Texture texturePp;
    if (!texturePp.loadFromFile("patapoule.png"))
        return -1;

    sf::Sprite spritePp;
    spritePp.setTexture(texturePp);
    spritePp.setScale(sf::Vector2f(0.1f, 0.1f));
    spritePp.setOrigin(sf::Vector2f(250.0f,250.0f));
    spritePp.setPosition(sf::Vector2f(200,650));


     sf::Texture textureNiv;
    if (!textureNiv.loadFromFile("niveau.png"))
        return -1;

    sf::Sprite spriteNiv;
    spriteNiv.setTexture(textureNiv);
    spriteNiv.setScale(sf::Vector2f(5.0f,5.0f));
    spriteNiv.setPosition(sf::Vector2f(0,-2100));


    sf::SoundBuffer buffer;
     if (!buffer.loadFromFile("0453.ogg"))
        return -1;

    sf::Sound sound;
    sound.setBuffer(buffer);

    sf::View view1;
	// Start the game loop
    while (app.isOpen())
    {
        sf::Time deltaTime = deltaClock.restart();
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::T)
                {
                  sf::Time elapsed1 = clock.restart();
                std::cout << elapsed1.asSeconds() << std::endl;
                }

            }


        }


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !isJumping)
        {
            playerVelocity.y = -250.f;
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {

            if ( (spritePp.getPosition().x >= (view1.getSize().x)/2) && (spritePp.getPosition().x <= spriteNiv.getGlobalBounds().width-(view1.getSize().x/2)))
                //Camera is not exiting level
                view1.move(sf::Vector2f(-speed, 0)* deltaTime.asSeconds());



            if (spritePp.getPosition().x >= 25 )
            {
                spritePp.move(sf::Vector2f(-speed, 0) * deltaTime.asSeconds());
                spritePp.rotate(-speed * deltaTime.asSeconds());
            }

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {


            if ((spritePp.getPosition().x >= (view1.getSize().x)/2) && (spritePp.getPosition().x <= spriteNiv.getGlobalBounds().width-(view1.getSize().x/2)))
                //Camera is not exiting level
                view1.move(sf::Vector2f(speed, 0)* deltaTime.asSeconds());

            if (spritePp.getPosition().x <= spriteNiv.getGlobalBounds().width - 25 )
            {
                spritePp.move(sf::Vector2f(speed, 0) * deltaTime.asSeconds());
                spritePp.rotate(speed * deltaTime.asSeconds());
            }

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            sound.play();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            std::cout <<"posy : "<< spritePp.getPosition().y << std::endl;


        }

        app.setView(view1);
        app.display();



    }

    return EXIT_SUCCESS;
}
