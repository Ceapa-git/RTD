#include "pch.h"
#include "pchSFML.h"

#include "tile.h"

#define COLS 30
#define ROWS 30
#define TILE_SIZE 16

int main(int argc, char **argv)
{
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "RTD - roguelike towerdefnce of reverse", sf::Style::Fullscreen);

    rtd::Tile tiles[ROWS][COLS];
    for (int y = 0; y < ROWS; y++)
    {
        for (int x = 0; x < COLS; x++)
        {
            tiles[y][x].setPosition(sf::Vector2f(x * TILE_SIZE * 1.f, y * TILE_SIZE * 1.f));
            tiles[y][x].setTexture("resources\\sprites\\hero_basic.png");
        }
    }
    float scaleFactro = 2.f;
    rtd::Tile::setScale(sf::Vector2f(scaleFactro, scaleFactro));
    sf::RenderStates states;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::W:
                    states.transform.translate(sf::Vector2f(0.f, -scaleFactro * TILE_SIZE));
                    break;
                case sf::Keyboard::A:
                    states.transform.translate(sf::Vector2f(-scaleFactro * TILE_SIZE, 0.f));
                    break;
                case sf::Keyboard::S:
                    states.transform.translate(sf::Vector2f(0.f, scaleFactro * TILE_SIZE));
                    break;
                case sf::Keyboard::D:
                    states.transform.translate(sf::Vector2f(scaleFactro * TILE_SIZE, 0.f));
                    break;
                case sf::Keyboard::Up:
                    scaleFactro *= 2.f;
                    rtd::Tile::setScale(sf::Vector2f(scaleFactro, scaleFactro));
                    break;
                case sf::Keyboard::Down:
                    scaleFactro /= 2.f;
                    rtd::Tile::setScale(sf::Vector2f(scaleFactro, scaleFactro));
                    break;
                case sf::Keyboard::Enter:
                    std::cout << scaleFactro << std::endl;
                    break;
                default:
                    break;
                }
            }
        }

        window.clear();
        for (int y = 0; y < ROWS; y++)
        {
            for (int x = 0; x < COLS; x++)
            {
                window.draw(tiles[y][x], states);
            }
        }
        window.display();
    }

    return 0;
}