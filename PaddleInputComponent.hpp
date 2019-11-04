#ifndef PADDLEINPUTCOMPONENT_HPP
#define PADDLEINPUTCOMPONENT_HPP

#include "InputComponent.hpp"

class Engine;
class Paddle;

class PaddleInputComponent: public InputComponent<Paddle> {
    friend class Paddle;

    Paddle &_paddle;
    PaddleInputComponent(Engine &engine, Paddle &paddle);
    void process(float delta) override;
};

#endif // PADDLEINPUTCOMPONENT_HPP
