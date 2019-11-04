#include "PaddleGraphicsComponent.hpp"
#include "Paddle.hpp"
#include <cassert>
#include "Graphics.hpp"
#include "Engine.hpp"

PaddleGraphicsComponent::PaddleGraphicsComponent(Engine &engine, Paddle &paddle):_paddle(paddle), GraphicsComponent<Paddle>(engine, paddle) {
    if (_texture.loadFromFile("paddle.png")) {
        _sprite.setTexture(_texture);
        //_sprite.setOrigin(1.f, 8.f);

        engine.graphics.addObject<sf::Drawable>(std::shared_ptr<sf::Sprite>(&_sprite));
    } else {
        assert(false);
    }


}

void PaddleGraphicsComponent::process(float delta) {
    _sprite.setPosition(_paddle.position);
}