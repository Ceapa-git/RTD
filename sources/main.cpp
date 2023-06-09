#include "pch.h"
#include "pchSFML.h"

#include "resourcemanager.h"
#include "map.h"
#include "fpstracker.h"
#include "entity.h"
#include "music.h"

int cols = 61;
int rows = 34;
int tileSize = 32;

int main(int argc, char **argv)
{
    std::cout<<"AAA\n";
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "RTD - roguelike towerdefnce of reverse", sf::Style::Fullscreen);

    rtd::Map map(rows, cols, tileSize);

    sf::Font font;
    font.loadFromFile("resources\\CONSOLA.TTF");
    sf::Text text("", font);
    std::ostringstream ostr;
    rtd::FpsTracker tracker(1000);

    rtd::Entity entity({"resources\\sprites\\chest_mimic_open_anim_f0.png",
                        "resources\\sprites\\chest_mimic_open_anim_f1.png",
                        "resources\\sprites\\chest_mimic_open_anim_f2.png",
                        "resources\\sprites\\chest_mimic_open_anim_f1.png"},
                       32.f, 32.f);

    bool fpsDisplay = false;

    double dTime = 0.0;
    const double updateTime = 1.0 / 60.0;

    rtd::Music backgroundMusic("resources\\audio\\backgroundMusic.mp3");
    backgroundMusic.play();

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
            else if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                case sf::Keyboard::W:
                    entity.move(0.f, -32.f);
                    break;
                case sf::Keyboard::Left:
                case sf::Keyboard::A:
                    entity.move(-32.f, 0.f);
                    break;
                case sf::Keyboard::Down:
                case sf::Keyboard::S:
                    entity.move(0.f, 32.f);
                    break;
                case sf::Keyboard::Right:
                case sf::Keyboard::D:
                    entity.move(32.f, 0.f);
                    break;
                default:
                    break;
                }
            }
        }
        tracker.update();
        dTime += tracker.getLastFrameTime();
        while (dTime >= updateTime)
        {
            entity.update();
            dTime -= updateTime;
        }

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