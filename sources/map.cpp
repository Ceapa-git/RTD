#include "pch.h"
#include "pchSFML.h"

#include "map.h"
#include "sprite.h"
#include "resourcemanager.h"

namespace rtd
{
    static const std::string tileName[TileType::COUNT]{
        "resources\\sprites\\floor_1.png",
        "resources\\sprites\\floor_ladder.png",
        "resources\\sprites\\floor_spikes_anim_f0.png",
        "resources\\sprites\\floor_spikes_anim_f3.png",
        "resources\\sprites\\wall_mid.png"};

    Map::Map(int rows, int cols, int tileSize)
    {
        map = std::make_unique<uint8_t[]>(rows * cols);
        this->rows = rows;
        this->cols = cols;
        this->tileSize = tileSize;

        srand(time(nullptr));
        for (int i = 0; i < cols; i++)
        {
            map[i] = map[(rows - 1) * cols + i] = TileType::WALL;
            int x = (int)(((double)rand() / RAND_MAX) * (cols - 2)) + 1;
            int y = (int)(((double)rand() / RAND_MAX) * (rows - 2)) + 1;
            map[y * cols + x] = TileType::SPIKE;
            x = (int)(((double)rand() / RAND_MAX) * (cols - 2)) + 1;
            y = (int)(((double)rand() / RAND_MAX) * (rows - 2)) + 1;
            map[y * cols + x] = TileType::SPIKE_SPRUNG;
        }
        for (int i = 0; i < rows; i++)
        {
            map[i*cols] = map[(i+1)*cols-1] = TileType::WALL;
            int x = (int)(((double)rand() / RAND_MAX) * (cols - 2)) + 1;
            int y = (int)(((double)rand() / RAND_MAX) * (rows - 2)) + 1;
            map[y * cols + x] = TileType::SPIKE;
            x = (int)(((double)rand() / RAND_MAX) * (cols - 2)) + 1;
            y = (int)(((double)rand() / RAND_MAX) * (rows - 2)) + 1;
            map[y * cols + x] = TileType::SPIKE_SPRUNG;
        }
        int x = (int)(((double)rand() / RAND_MAX) * (cols - 2)) + 1;
        int y = (int)(((double)rand() / RAND_MAX) * (rows - 2)) + 1;
        map[y * cols + x] = 1;

        rtd::ResourceManager &manager = rtd::ResourceManager::getInstance();
        for (int i = 0; i < TileType::COUNT; i++)
            tiles[i] = manager.getSprite(tileName[i]);
    }

    void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        for (int y = 0; y < rows; y++)
        {
            for (int x = 0; x < cols; x++)
            {
                sf::RenderStates newStates = states;
                newStates.transform.translate(x * tileSize * 1.f, y * tileSize * 1.f);
                target.draw(tiles[map[y * cols + x]], newStates);
            }
        }
    }
}