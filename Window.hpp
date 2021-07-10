#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <vector>
#include "Ball.hpp"

class Window
{
public:
    sf::RenderWindow screen;

private:
    sf::Vector2f screenDimensions;
    std::vector<Ball> objects;
    const int FRAMERATE = 60;

public:
    Window(const unsigned int x, const unsigned int y);
    Window(const Window& w);
    Window& operator =(const Window& w);
    ~Window();
    void addCircle(Ball circle);
    void run();

private:
    void drawAllObjects();
};

#endif /* WINDOW_HPP */
