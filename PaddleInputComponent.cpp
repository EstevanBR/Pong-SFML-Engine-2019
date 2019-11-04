#include "PaddleInputComponent.hpp"
#include "Paddle.hpp"

PaddleInputComponent::PaddleInputComponent(Engine &engine, Paddle &paddle): _paddle(paddle), InputComponent<Paddle>(engine, paddle) {

}

void PaddleInputComponent::process(float delta) {
    if (_paddle.side) {
        _paddle.position.y += (engine.input.userInput.up) ? 50.f * delta : 0.f;
        _paddle.position.y += (engine.input.userInput.down) ? -50.f * delta : 0.f;    
    } else {
        _paddle.position.y += (engine.input.userInput.left) ? 50.f * delta : 0.f;
        _paddle.position.y += (engine.input.userInput.right) ? -50.f * delta : 0.f;    
    }
    
}