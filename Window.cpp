#include "Window.hpp"

Window::Window(const unsigned int x, const unsigned int y)
:screen(), screenDimensions(), objects()
{
    screenDimensions.x = x;
    screenDimensions.y = y;

    screen.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Click", sf::Style::Titlebar | sf::Style::Close);
    screen.setFramerateLimit(FRAMERATE);
}

Window::Window(const Window& w)
:screen(), screenDimensions(), objects()
{
    screenDimensions.x = w.screenDimensions.x;
    screenDimensions.y = w.screenDimensions.y;

    screen.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Click", sf::Style::Titlebar | sf::Style::Close);
    objects = w.objects;
    screen.setFramerateLimit(FRAMERATE);
}

Window& Window::operator =(const Window& w)
{
    screenDimensions.x = w.screenDimensions.x;
    screenDimensions.y = w.screenDimensions.y;

    screen.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Click", sf::Style::Titlebar | sf::Style::Close);
    objects = w.objects;
    screen.setFramerateLimit(FRAMERATE);

    return *this;
}

Window::~Window()
{
    if(screen.isOpen())
    {
        screen.close();
    }
}

void Window::addCircle(Ball circle)
{
    objects.push_back(circle);
}

void Window::run()
{
    while(screen.isOpen())
    {
        sf::Event event;
        while(screen.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                screen.close();
            }
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(screen);
            Ball b(mousePosition.x, mousePosition.y);
            objects.push_back(b);
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            if(!objects.empty())
            {
                objects.pop_back();
            }
        }

        screen.clear(sf::Color::White);
        drawAllObjects();
        screen.display();
    }
}

void Window::drawAllObjects()
{
    const unsigned int count = objects.size();
    for(unsigned int i = 0; i < count; i++)
    {
        objects[i].move(screenDimensions.x, screenDimensions.y);
        screen.draw(objects[i].circle);
    }
}
