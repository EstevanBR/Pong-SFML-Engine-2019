#ifndef PONG_GAME_HPP
#define PONG_GAME_HPP

#include "Game.hpp"

class PongGame: public Game {
    void initialized(Engine &engine) override;
};

#endif