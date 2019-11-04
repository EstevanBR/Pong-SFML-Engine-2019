#ifndef BALL_HPP
#define BALL_HPP

#include <memory>
#include "Node2D.hpp"

class BallGraphicsComponent;
class BallPhysicsComponent;

class Engine;

class Ball: public Node2D {
    friend class PongGame;
    friend class BallPhysicsComponent;
    sf::Vector2f _startingPosition;
    sf::Vector2f _velocity;
    float _speed = 10.f;
    sf::FloatRect _bounds;

    std::shared_ptr<BallGraphicsComponent> _graphicsComponent;
    std::shared_ptr<BallPhysicsComponent> _physicsComponent;
    
    Ball(Engine &engine);
    void process(float delta) override;
    void reset();
};

#endif