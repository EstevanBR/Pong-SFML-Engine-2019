#ifndef BALL_GRAPHICS_COMPONENT_HPP
#define BALL_GRAPHICS_COMPONENT_HPP

#include <SFML/Graphics.hpp>
#include "GraphicsComponent.hpp"

class Ball;
class Engine;

class BallGraphicsComponent: public GraphicsComponent<Ball> {
    friend class Ball;
    
    sf::Texture _texture;
    sf::Sprite _sprite;
    Ball &_ball;

    BallGraphicsComponent(Engine &engine, Ball &ball);
    void process(float delta) override;
};

#endif