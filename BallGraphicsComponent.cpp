#include "BallGraphicsComponent.hpp"
#include "Ball.hpp"
#include <cassert>
#include "Graphics.hpp"
#include "Engine.hpp"

void BallGraphicsComponent::process(float delta) {
    _sprite.setPosition(_ball.position);
}

BallGraphicsComponent::BallGraphicsComponent(Engine &engine, Ball &ball): _ball(ball), GraphicsComponent<Ball>(engine, ball) {
    if (_texture.loadFromFile("ball.png")) {
        
        _sprite.setTexture(_texture);

        engine.graphics.addObject<sf::Drawable>(std::shared_ptr<sf::Sprite>(&_sprite));
    } else {
        assert(false);
    }
}