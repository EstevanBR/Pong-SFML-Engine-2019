cmake_minimum_required(VERSION 3.0.0)
project(Pong VERSION 0.1.0)

# include(CTest)
# enable_testing()

add_executable(Pong
    main.cpp
    PongGame.hpp
    PongGame.cpp
    Ball.hpp
    Ball.cpp
    BallGraphicsComponent.hpp
    BallGraphicsComponent.cpp
    BallPhysicsComponent.hpp
    BallPhysicsComponent.cpp
    Paddle.hpp
    Paddle.cpp
    PaddlePhysicsComponent.hpp
    PaddlePhysicsComponent.cpp
    PaddleGraphicsComponent.hpp
    PaddleGraphicsComponent.cpp
    PaddleInputComponent.hpp
    PaddleInputComponent.cpp
    
)

add_subdirectory(SFML-Engine-2019)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

link_directories(SFML-Engine-2019)
target_link_libraries(Pong LINK_PUBLIC SFML-Engine sfml-system sfml-graphics sfml-window)
