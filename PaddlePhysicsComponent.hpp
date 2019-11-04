#ifndef PADDLEPHYSICSCOMPONENT_HPP
#define PADDLEPHYSICSCOMPONENT_HPP

#include "Paddle.hpp"
#include "PhysicsComponent.hpp"

class PaddlePhysicsComponent: public EntityPhysicsComponent<Paddle> {
    friend class Paddle;

    Paddle &_paddle;

    std::shared_ptr<RectCollisionShape> _collisionShape;
    PaddlePhysicsComponent(Engine &engine, Paddle &paddle);

    void process(float delta) override;
    void collided(CollisionShape &other) override;
};

#endif // PADDLEPHYSICSCOMPONENT_HPP
