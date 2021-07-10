#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <stdlib.h>
#include <time.h>

class Ball
{
public:
    sf::CircleShape circle;

private:
    sf::Vector2f circlePosition;
    float radius;
    bool down;
    bool right;

public:
    Ball(const unsigned int x, const unsigned int y);
    Ball(const Ball& b);
    Ball& operator =(const Ball& b);
    ~Ball();
    void move(const unsigned int width, const unsigned int length);
};

#endif /* BALL_HPP */
