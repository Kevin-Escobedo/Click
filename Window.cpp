#include "Window.hpp"

Window::Window(const unsigned int x, const unsigned int y)
:screen(), screenDimensions(), objects()
{
    screenDimensions.x = x;
    screenDimensions.y = y;

    screen.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Click", sf::Style::Titlebar | sf::Style::Close);
}

Window::Window(const Window& w)
:screen(), screenDimensions(), objects()
{
    screenDimensions.x = w.screenDimensions.x;
    screenDimensions.y = w.screenDimensions.y;

    screen.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Click", sf::Style::Titlebar | sf::Style::Close);
    objects = w.objects;
}

Window& Window::operator =(const Window& w)
{
    screenDimensions.x = w.screenDimensions.x;
    screenDimensions.y = w.screenDimensions.y;

    screen.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Click", sf::Style::Titlebar | sf::Style::Close);
    objects = w.objects;
    return *this;
}

Window::~Window()
{
    if(screen.isOpen())
    {
        screen.close();
    }
}

void Window::addCircle(sf::CircleShape circle)
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
        screen.draw(objects[i]);
    }
}
