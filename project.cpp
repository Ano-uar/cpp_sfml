#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>
#include <math.h>
#include <iostream>

int main()
{
    int scorePlayer1 = 0, scorePlayer2 = 0;
    float xVelocity = 7.0, yVelocity = 7.0;


    sf::RenderWindow window(sf::VideoMode(1280, 720), "Ping pong", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);
    //
    //bar 1
    sf::RectangleShape _Bar1;
    _Bar1.setSize(sf::Vector2f(25.0f, 200.0f));
    _Bar1.setFillColor(sf::Color::White);
    _Bar1.setOrigin(sf::Vector2f(0.0f, 100.0f));
    _Bar1.setPosition(sf::Vector2f(0.0f, window.getSize().y / 2));

    //bar 2

    sf::RectangleShape _Bar2;
    _Bar2.setSize(sf::Vector2f(25.0f, 200.0f));
    _Bar2.setFillColor(sf::Color::White);
    _Bar2.setOrigin(sf::Vector2f(25.0f, 100.0f));
    _Bar2.setPosition(sf::Vector2f(window.getSize().x, window.getSize().y / 2));

    //bar 2
    
    //ball
    sf::CircleShape ball;
    ball.setRadius(15.0f);
    ball.setFillColor(sf::Color::Red);
    ball.setOrigin(ball.getRadius(), ball.getRadius());
    ball.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
    //
    //font
    sf::Font fontDroid;
    sf::Font fontMineCraft;
    fontDroid.loadFromFile("droidFont.ttf");
    fontMineCraft.loadFromFile("mineCraft.ttf");
    //text customization

    sf::Text scoreP1;
    sf::Text scoreP2;
    sf::Text colone;
    sf::Text start;

    scoreP1.setFont(fontDroid);
    scoreP2.setFont(fontDroid);
    colone.setFont(fontDroid);
    start.setFont(fontMineCraft);

    scoreP1.setFillColor(sf::Color::White);
    scoreP2.setFillColor(sf::Color::White);
    colone.setFillColor(sf::Color::White);
    start.setFillColor(sf::Color::White);

    scoreP1.setCharacterSize(25);
    scoreP2.setCharacterSize(25);
    colone.setCharacterSize(25);
    start.setCharacterSize(50);

    //start.setOrigin(sf::Vector2f(start.getLocalBounds().left + start.getLocalBounds().width / 2.0f, start.getLocalBounds().top + start.getLocalBounds().height / 2.0f));

    colone.setPosition(sf::Vector2f(window.getSize().x / 2, 0.0f));
    scoreP1.setPosition(sf::Vector2f((window.getSize().x / 2) - 30.0f, 0.0f));
    scoreP2.setPosition(sf::Vector2f((window.getSize().x / 2) + 30.0f, 0.0f));
    //start.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f));
    //
    




    

    while (window.isOpen())
    {
        //converting int to string:
        std::string sP1 = std::to_string(scorePlayer1);
        std::string sP2 = std::to_string(scorePlayer2);
        //setting the text;
        scoreP1.setString(sP1);
        scoreP2.setString(sP2);
        colone.setString(":");
        //start.setString("Start");
        //
        //
        

        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (evnt.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                    break;
                }
            }
        }
        //control
        //bar1
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            if (_Bar1.getPosition().y > 100)
            {
                _Bar1.move(sf::Vector2f(0.0f, -4.5f));
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (_Bar1.getPosition().y < 620)
            {
                _Bar1.move(sf::Vector2f(0.0f, 4.5f));
            }
        }
        //bar 2
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if (_Bar2.getPosition().y > 100)
            {
                _Bar2.move(sf::Vector2f(0.0f, -4.5f));
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (_Bar2.getPosition().y < 620)
            {
                _Bar2.move(sf::Vector2f(0.0f, 4.5f));
            }
        }
        //moving the ball;

        ball.setPosition(sf::Vector2f(ball.getPosition().x + xVelocity, ball.getPosition().y + yVelocity));
        //collition


        if (ball.getPosition().y > 705 || ball.getPosition().y < 5) yVelocity *= -1.0;
        if (ball.getGlobalBounds().intersects(_Bar1.getGlobalBounds()))  xVelocity *= -1.0;
        if (ball.getGlobalBounds().intersects(_Bar2.getGlobalBounds()))  xVelocity *= -1.0;


        if (abs(ball.getPosition().x - window.getSize().x) < 10.0)
        {
            scorePlayer1 += 1;
            ball.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
            yVelocity = abs(yVelocity);
            xVelocity = abs(xVelocity);
        }
        else if (ball.getPosition().x < 10.0)
        {
            scorePlayer2 += 1;
            ball.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
            yVelocity = abs(yVelocity);
            xVelocity = abs(xVelocity);
            
        }
        

        


        //update game
        
        //draw
        window.clear();
        window.draw(_Bar1);
        window.draw(_Bar2);
        window.draw(ball);
        window.draw(scoreP1);
        window.draw(scoreP2);
        window.draw(colone);
        window.display();

        
    }

    return 0;
}

