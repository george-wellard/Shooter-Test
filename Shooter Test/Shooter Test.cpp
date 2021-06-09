// Shooter Test.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Bullet.h"
#include "Player.h"
#include <math.h>

int main()
{
    sf::RenderWindow window;
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 755, (sf::VideoMode::getDesktopMode().height / 2) - 390);

    window.create(sf::VideoMode(1500, 700), "Shooter test", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(true);

    sf::Clock clock;

    sf::Vector2f playerCenter;
    sf::Vector2f mousePosWindow;
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;
   

    Player player(sf::Vector2f(50, 50));

    //Main Loop:
    while (window.isOpen()) {

        sf::Event Event;

        //Event Loop:
        while (window.pollEvent(Event)) {
            switch (Event.type) {

            case sf::Event::Closed:
                window.close();
            }

            int moveSpeed = 6;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                player.move(sf::Vector2f(0, -moveSpeed));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                player.move(sf::Vector2f(0, moveSpeed));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                player.move(sf::Vector2f(-moveSpeed, 0));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                player.move(sf::Vector2f(moveSpeed, 0));
            }

        }

        window.clear();

        player.draw(window);
        window.display();
    }
}
