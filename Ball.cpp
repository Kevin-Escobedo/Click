#include "Ball.hpp"

Ball::Ball(const unsigned int x, const unsigned int y)
:circle(), circlePosition(), radius(), down(), right()
{
    srand((unsigned int)time(nullptr));
    radius = (rand() % 10) + 10;
    circle.setRadius(radius);

    circlePosition.x = x - radius;
    circlePosition.y = y - radius;

    circle.setPosition(circlePosition);

    time_t now = time(nullptr);
    struct tm* time = localtime(&now);

    const int month = time->tm_mon;

    if(month == 5) //Check if June
    {
        const unsigned int red = rand() % 256;
        const unsigned int green = rand() % 256;
        const unsigned int blue = rand() % 256;

        const sf::Color color = sf::Color(red, green, blue);
        circle.setFillColor(color);
    }
    
    else
    {
        circle.setFillColor(sf::Color::Black);
    }

    int direction = rand() % 4;

    switch(direction)
    {
        case 0:
            down = false;
            right = false;
            break;

        case 1:
            down = false;
            right = true;
            break;

        case 2:
            down = true;
            right = false;
            break;

        case 3:
            down = true;
            right = true;
            break;

        default:
            break;
    }
}

Ball::Ball(const Ball& b)
:circle(), circlePosition(), radius(), down(), right()
{
    circlePosition.x = b.circlePosition.x;
    circlePosition.y = b.circlePosition.y;
    radius = b.radius;

    circle.setRadius(radius);
    circle.setPosition(circlePosition);
    
    time_t now = time(nullptr);
    struct tm* time = localtime(&now);

    const int month = time->tm_mon;

    if(month == 5) //Check if June
    {
        const unsigned int red = rand() % 256;
        const unsigned int green = rand() % 256;
        const unsigned int blue = rand() % 256;

        const sf::Color color = sf::Color(red, green, blue);
        circle.setFillColor(color);
    }
    
    else
    {
        circle.setFillColor(sf::Color::Black);
    }

    down = b.down;
    right = b.right;
}

Ball& Ball::operator =(const Ball& b)
{
    circlePosition.x = b.circlePosition.x;
    circlePosition.y = b.circlePosition.y;
    radius = b.radius;

    time_t now = time(nullptr);
    struct tm* time = localtime(&now);

    const int month = time->tm_mon;

    if(month == 5) //Check if June
    {
        const unsigned int red = rand() % 256;
        const unsigned int green = rand() % 256;
        const unsigned int blue = rand() % 256;

        const sf::Color color = sf::Color(red, green, blue);
        circle.setFillColor(color);
    }
    
    else
    {
        circle.setFillColor(sf::Color::Black);
    }

    circle.setRadius(radius);
    circle.setPosition(circlePosition);

    down = b.down;
    right = b.right;

    return *this;
}

Ball::~Ball()
{

}

void Ball::move(const unsigned int width, const unsigned int length)
{
    const int velocity = length / 100;
    int xValue = (right) ? velocity : -1 * velocity;
    int yValue = (down) ? velocity : -1 * velocity;

    circlePosition.x += xValue;
    circlePosition.y += yValue;

    circle.setPosition(circlePosition);

    const float diameter = 2 * radius;

    if(circlePosition.x <= 0 || circlePosition.x >= (width - diameter))
    {
        right = !right;
    }

    if(circlePosition.y <= 0 || circlePosition.y >= (length - diameter))
    {
        down = !down;
    }
}
