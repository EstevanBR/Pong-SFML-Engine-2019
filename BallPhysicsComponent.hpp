#ifndef BALL_PHYSICS_COMPONENT_HPP
#define BALL_PHYSICS_COMPONENT_HPP

#include "PhysicsComponent.hpp"

class CircleCollisionShape;
class Ball;
class Engine;

class BallPhysicsComponent: public EntityPhysicsComponent<Ball> {
    friend class Ball;
    Ball &_ball;
    
    std::shared_ptr<RectCollisionShape> _collisionShape;
    BallPhysicsComponent(Engine &engine, Ball &ball);
    
    void process(float delta) override;
    void collided(CollisionShape &other) override;
};

#endif