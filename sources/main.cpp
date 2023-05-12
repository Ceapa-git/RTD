#include "pch.h"
#include "pchSFML.h"

#include "tile.h"
#include "events.h"

const int COLS = 90;
const int ROWS = 60;
const int TILE_SIZE = 16;

int main(int argc, char **argv)
{
    std::cout << sizeof(rtd::Tile) << std::endl
              << COLS * ROWS * sizeof(rtd::Tile) << std::endl;
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "RTD - roguelike towerdefnce of reverse", sf::Style::Fullscreen);

    float offset = TILE_SIZE / 2.f;

    std::unique_ptr<std::unique_ptr<rtd::Tile[]>[]> tiles = std::make_unique<std::unique_ptr<rtd::Tile[]>[]>(ROWS);
    for (int y = 0; y < ROWS; y++)
    {
        tiles[y] = std::make_unique<rtd::Tile[]>(COLS);
        for (int x = 0; x < COLS; x++)
        {
            tiles[y][x].setPosition(sf::Vector2f(x * TILE_SIZE * 1.f + offset, y * TILE_SIZE * 1.f + offset));
            tiles[y][x].setTexture("resources\\sprites\\hero_basic.png");
        }
    }
    float scaleFactor = 1.f;
    sf::RenderStates states;
    int dir = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            rtd::moveEvent(event, states, dir);
            rtd::zoomEvent(event, states, scaleFactor);
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