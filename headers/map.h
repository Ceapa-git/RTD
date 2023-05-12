#ifndef RTD_MAP_H_INCLUDED
#define RTD_MAP_H_INCLUDED

#include "pch.h"
#include "pchSFML.h"

#include "sprite.h"

namespace rtd
{
    enum TileType
    {
        EMPTY,
        LADDER,
        SPIKE,
        SPIKE_SPRUNG,
        WALL,
        COUNT // keep last
    };
    class Map : public sf::Drawable
    {
    public:
        Map(int rows, int cols, int tileSize);
        Map() = delete;
        Map(const Map &) = delete;
        Map &operator=(const Map &) = delete;
        ~Map() {}

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    private:
        std::unique_ptr<uint8_t[]> map;
        std::array<rtd::Sprite, TileType::COUNT> tiles;
        int rows;
        int cols;
        int tileSize;
    };
}

#endif // RTD_MAP_H_INCLUDED