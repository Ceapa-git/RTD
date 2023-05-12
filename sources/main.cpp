#include "pch.h"
#include "pchSFML.h"

#include "resourcemanager.h"
#include "map.h"
#include "fpstracker.h"

int cols = 61;
int rows = 34;
int tileSize = 16;
float scaleFactor = 2.f;

int main(int argc, char **argv)
{
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "RTD - roguelike towerdefnce of reverse", sf::Style::Fullscreen);

    rtd::Map map(rows, cols, tileSize);

    sf::Font font;
    font.loadFromFile("resources\\CONSOLA.TTF");
    sf::Text text("", font);
    std::ostringstream ostr;
    rtd::FpsTracker tracker;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        tracker.update();

        ostr.str("");
        ostr << "Average FPS: " << tracker.getAverageFps() << '\n'
             << "Average Frame Time: " << tracker.getAverageFrameTime() << '\n'
             << "Min Frame Time: " << tracker.getMinFrameTime() << '\n'
             << "Max Frame Time: " << tracker.getMaxFrameTime();
        text.setString(ostr.str());

        window.clear();
        sf::RenderStates states;
        states.transform.translate(-16.f, -4.f);
        states.transform.scale(scaleFactor, scaleFactor);
        window.draw(map, states);
        window.draw(text);
        window.display();
    }

    return 0;
}