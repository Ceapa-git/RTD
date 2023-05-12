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
    rtd::FpsTracker tracker(1000);

    bool fpsDisplay = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab)
                fpsDisplay = true;
            else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Tab)
                fpsDisplay = false;
        }
        tracker.update();

        ostr.str("");
        ostr << "Average FPS: " << tracker.getAverageFps() << '\n'
             << "Average Frame Time: " << tracker.getAverageFrameTime() << " ms\n"
             << "Min Frame Time: " << tracker.getMinFrameTime() << " ms\n"
             << "Max Frame Time: " << tracker.getMaxFrameTime() << " ms";
        text.setString(ostr.str());

        window.clear();
        sf::RenderStates states;
        states.transform.translate(-16.f, -4.f);
        states.transform.scale(scaleFactor, scaleFactor);
        window.draw(map, states);
        if (fpsDisplay)
            window.draw(text);
        window.display();
    }

    return 0;
}