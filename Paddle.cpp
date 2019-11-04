#include "Paddle.hpp"
#include "Engine.hpp"
#include "PaddleGraphicsComponent.hpp"
#include "PaddlePhysicsComponent.hpp"
#include "PaddleInputComponent.hpp"

Paddle::Paddle(bool side, Engine &engine) {
    _side = side;
    _startingPosition = sf::Vector2f((_side) ? 4 : engine.window.getSize().x - 8, engine.window.getSize().y /  2);
    position = _startingPosition;
    
    _graphicsComponent = std::shared_ptr<PaddleGraphicsComponent>(new PaddleGraphicsComponent(engine, *this));
    _physicsComponent = std::shared_ptr<PaddlePhysicsComponent>(new PaddlePhysicsComponent(engine, *this));
    _inputComponent = std::shared_ptr<PaddleInputComponent>(new PaddleInputComponent(engine, *this));
}

void Paddle::process(float delta) {

}