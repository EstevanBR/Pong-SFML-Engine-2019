#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "Node2D.hpp"

class Engine;
class PaddleGraphicsComponent;
class PaddleInputComponent;
class PaddlePhysicsComponent;

class Paddle: public Node2D {
    friend class PongGame;

    // false == left, true == right
    bool _side;
    sf::Vector2f _startingPosition;

    std::shared_ptr<PaddleGraphicsComponent> _graphicsComponent;
    std::shared_ptr<PaddlePhysicsComponent> _physicsComponent;
    std::shared_ptr<PaddleInputComponent> _inputComponent;

    Paddle(bool side, Engine &engine);
    void process(float delta) override;
public:
    const bool &side = _side;
};

#endif // PADDLE_HPP
