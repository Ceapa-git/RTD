#ifndef RTD_TILE_H_INCLUDED
#define RTD_TILE_H_INCLUDED

#include "pch.h"
#include "pchSFML.h"

#include "sprite.h"

namespace rtd
{
    class Tile : public sf::Drawable
    {
    public:
        Tile(){};
        ~Tile(){};

        void setTexture(const char *filename);
        void setPosition(const sf::Vector2f &position);

        static void setScale(const sf::Vector2f &scale);

        void draw(sf::RenderTarget &renderer, sf::RenderStates states) const override;

    private:
        rtd::Sprite m_Sprite;
        sf::Vector2f m_Postion;
        static inline sf::Vector2f s_Scale = sf::Vector2f(1.f, 1.f);
    };
}

#endif // RTD_TILE_H_INCLUDED