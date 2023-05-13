#include "pch.h"
#include "pchSFML.h"

#include "resourcemanager.h"
#include "map.h"
#include "fpstracker.h"
#include "entity.h"

int cols = 61;
int rows = 34;
int tileSize = 32;

int main(int argc, char **argv)
{
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "RTD - roguelike towerdefnce of reverse", sf::Style::Fullscreen);

    rtd::Map map(rows, cols, tileSize);

    sf::Font font;
    font.loadFromFile("resources\\CONSOLA.TTF");
    sf::Text text("", font);
    std::ostringstream ostr;
    rtd::FpsTracker tracker(1000);

    rtd::Entity entity({"resources\\sprites\\chest_mimic_open_anim_f0.png",
                        "resources\\sprites\\chest_mimic_open_anim_f1.png",
                        "resources\\sprites\\chest_mimic_open_anim_f2.png"},
                       100.f, 100.f);

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
        entity.update();

        if (fpsDisplay)
        {
            ostr.str("");
            ostr << "Average FPS: " << std::fixed << std::setprecision(2) << tracker.getAverageFps() << '\n'
                 << "Average Frame Time: " << std::fixed << std::setprecision(2) << tracker.getAverageFrameTime() << " ms\n"
                 << "Min Frame Time: " << std::fixed << std::setprecision(2) << tracker.getMinFrameTime() << " ms\n"
                 << "Max Frame Time: " << std::fixed << std::setprecision(2) << tracker.getMaxFrameTime() << " ms";
            text.setString(ostr.str());
        }

        window.clear(sf::Color::Transparent);
        sf::RenderStates states;
        states.transform.translate(-16.f, -4.f);
        window.draw(map, states);
        window.draw(entity, states);
        if (fpsDisplay)
            window.draw(text);
        window.display();
    }

    return 0;
}