#include <iostream>

#include "PongGame.hpp"

int main(int, char**) {
    return PongGame().main(sf::VideoMode(320,240), "Pong");
}
