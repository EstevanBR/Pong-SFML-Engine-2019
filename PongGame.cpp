#include "PongGame.hpp"
#include "Engine.hpp"

#include "Ball.hpp"
#include "Paddle.hpp"

void PongGame::initialized(Engine& engine) {
    engine.tree.addObject(std::shared_ptr<Ball>(new Ball(engine)));
    engine.tree.addObject(std::shared_ptr<Paddle>(new Paddle(true, engine)));
    engine.tree.addObject(std::shared_ptr<Paddle>(new Paddle(false, engine)));
}