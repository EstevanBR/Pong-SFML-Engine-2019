#include <iostream>
#include "Paddle.hpp"
#include "PaddlePhysicsComponent.hpp"
#include "RectCollisionShape.hpp"
#include "Engine.hpp"

PaddlePhysicsComponent::PaddlePhysicsComponent(Engine &engine, Paddle &paddle): _paddle(paddle), EntityPhysicsComponent<Paddle>(engine, paddle) {
    _collisionShape = engine.physics.addObject<RectCollisionShape>(std::shared_ptr<RectCollisionShape>(new RectCollisionShape(*this, paddle.position.x, paddle.position.y, 2.f, 16.f)));
}

void PaddlePhysicsComponent::process(float delta) {
    _collisionShape->left = _paddle.position.x;
    _collisionShape->top = _paddle.position.y;
    //std::cout << "paddle: x:" << int(_collisionShape->left) << " y: " << int(_collisionShape->top) << std::endl;
}

void PaddlePhysicsComponent::collided(CollisionShape &other) {
}