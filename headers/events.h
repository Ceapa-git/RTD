#ifndef RTD_EVENTS_H_INCLUDED
#define RTD_EVENTS_H_INCLUDED

#include "pch.h"
#include "pchSFML.h"

namespace rtd
{
    const int UP = 1 << 0;
    const int LEFT = 1 << 1;
    const int DOWN = 1 << 2;
    const int RIGHT = 1 << 3;
    void moveEvent(const sf::Event &event, sf::RenderStates &states, int &dir);
    void zoomEvent(const sf::Event &event, sf::RenderStates &states, float &scaleFactor);
}

#endif // RTD_EVENTS_H_INCLUDED