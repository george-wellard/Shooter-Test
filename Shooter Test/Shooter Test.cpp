// Shooter Test.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include <math.h>
#include <vector>


class Bullet {

public:

    sf::CircleShape bullet;
    sf::Vector2f currentVelocity;
    float maxSpeed;

    Bullet(float radius = 5.f) 
        : currentVelocity(0.f, 0.f), maxSpeed(15.f) {

        this->bullet.setRadius(radius);
        this->bullet.setFillColor(sf::Color::Red);

    }
};

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
    Bullet b1;

    std::vector<Bullet> bullets;
    bullets.push_back(Bullet(b1));

    //Main Loop:
    while (window.isOpen()) {

        sf::Event Event;

        playerCenter = sf::Vector2f(player.getX(), player.getY());
        mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(window));
        aimDir = mousePosWindow - playerCenter;
        aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));

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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                player.move(sf::Vector2f(0, moveSpeed));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                player.move(sf::Vector2f(-moveSpeed, 0));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                player.move(sf::Vector2f(moveSpeed, 0));
            }

            //Shooting
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                b1.bullet.setPosition(playerCenter);
                b1.currentVelocity = aimDirNorm * b1.maxSpeed;

                bullets.push_back(Bullet(b1));
            }

            for(size_t i = 0; i < bullets.size(); i++) {

                bullets[i].bullet.move(bullets[i].currentVelocity);
            }

        }

        window.clear();

        player.draw(window);

        for (size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i].bullet);
        }

        window.display();
    }
}
