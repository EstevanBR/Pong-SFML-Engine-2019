#include "Ball.hpp"
#include "Engine.hpp"
#include "BallGraphicsComponent.hpp"
#include "BallPhysicsComponent.hpp"
#include <random>
#include <iostream>
#include "Math.hpp"

Ball::Ball(Engine &engine) {
    _startingPosition = sf::Vector2f(engine.window.getSize()) * 0.5f;
   
    _graphicsComponent = std::shared_ptr<BallGraphicsComponent>(new BallGraphicsComponent(engine, *this));
    _physicsComponent = std::shared_ptr<BallPhysicsComponent>(new BallPhysicsComponent(engine, *this));

    _velocity = sf::Vector2f(_speed, 0);

    _bounds = sf::FloatRect(-32,-32,engine.window.getSize().x+64, engine.window.getSize().y+64);
    
    reset();
}

void Ball::reset() {
    position = _startingPosition;
    _velocity.x *= -1.f;
    _velocity = Normalize(_velocity);
    _velocity *= _speed;
}

void Ball::process(float delta) {
    if (_bounds.contains(position)) {
        position += _velocity * delta;
    } else {
        reset();
    }
}
