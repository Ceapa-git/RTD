#include "pch.h"
#include "pchSFML.h"

#include "events.h"
#include "tile.h"

namespace rtd
{
    void moveEvent(const sf::Event &event, int &dir)
    {
        if (event.type != sf::Event::KeyPressed && event.type != sf::Event::KeyReleased)
            return;

        bool pressed = event.type != sf::Event::KeyPressed;

        switch (event.key.code)
        {
        case sf::Keyboard::W:
            dir = (pressed ? (dir | UP) : (dir & (!UP)));
            break;
        case sf::Keyboard::A:
            dir = (pressed ? (dir | LEFT) : (dir & (!LEFT)));
            break;
        case sf::Keyboard::S:
            dir = (pressed ? (dir | DOWN) : (dir & (!DOWN)));
            break;
        case sf::Keyboard::D:
            dir = (pressed ? (dir | RIGHT) : (dir & (!RIGHT)));
            break;
        default:
            break;
        }
    }
    void zoomEvent(const sf::Event &event, sf::RenderStates &states, float &scaleFactor)
    {
        if (event.type != sf::Event::KeyPressed)
            return;

        switch (event.key.code)
        {
        case sf::Keyboard::Up:
            scaleFactor *= 2.f;
            rtd::Tile::setScale(sf::Vector2f(scaleFactor, scaleFactor));
            break;
        case sf::Keyboard::Down:
            scaleFactor /= 2.f;
            rtd::Tile::setScale(sf::Vector2f(scaleFactor, scaleFactor));
            break;
        default:
            break;
        }
    }
}