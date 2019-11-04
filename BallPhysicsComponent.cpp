#include <iostream>
#include "Ball.hpp"
#include "BallPhysicsComponent.hpp"
#include "RectCollisionShape.hpp"
#include "Engine.hpp"
#include "PaddlePhysicsComponent.hpp"


BallPhysicsComponent::BallPhysicsComponent(Engine &engine, Ball &ball): _ball(ball), EntityPhysicsComponent<Ball>(engine, ball) {
    _collisionShape = engine.physics.addObject<RectCollisionShape>(std::shared_ptr<RectCollisionShape>(new RectCollisionShape(*this, ball.position.x, ball.position.y, 4.f, 4.f)));
}

void BallPhysicsComponent::process(float delta) {
    _collisionShape->left = _ball.position.x;
    _collisionShape->top = _ball.position.y;
}

void BallPhysicsComponent::collided(CollisionShape &other) {
    if (other.belongsTo<PaddlePhysicsComponent>()) {
        bool left = _ball._velocity.x <= 0.f;
        RectCollisionShape &rectCollisionShape = static_cast<RectCollisionShape &>(other);
        owner._velocity.x *= -1.f;
        
        if (left) {
            _ball.position.x = _collisionShape->left = rectCollisionShape.left+rectCollisionShape.width; 
        } else {
            _ball.position.x = _collisionShape->left = rectCollisionShape.left-_collisionShape->width;
        }
    }
}