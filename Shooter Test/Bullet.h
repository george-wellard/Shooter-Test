#pragma once
#include "SFML/Graphics.hpp"

class Bullet {

public:

    sf::CircleShape bullet;
    sf::Vector2f currentVelocity; 
    float maxSpeed;

    Bullet(float radius = 5.f) : currentVelocity(0.f, 0.f), maxSpeed(15.f) {

        this->bullet.setRadius(radius);
        this->bullet.setFillColor(sf::Color::Red);

    }
};