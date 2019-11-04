#ifndef PADDLEGRAPHICSCOMPONENT_HPP
#define PADDLEGRAPHICSCOMPONENT_HPP

#include <SFML/Graphics.hpp>
#include "GraphicsComponent.hpp"

class Paddle;
class Engine;

class PaddleGraphicsComponent: public GraphicsComponent<Paddle> {
    friend class Paddle;

    sf::Texture _texture;
    sf::Sprite _sprite;
    Paddle &_paddle;

    PaddleGraphicsComponent(Engine &engine, Paddle &paddle);
    void process(float delta) override;
};

#endif // PADDLEGRAPHICSCOMPONENT_HPP
