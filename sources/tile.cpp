#include "pch.h"
#include "pchSFML.h"

#include "tile.h"

namespace rtd
{
    void Tile::setTexture(const char *filename)
    {
        m_Sprite.setTexture(filename);
    }
    void Tile::setPosition(const sf::Vector2f &position)
    {
        m_Postion = position;
    }
    void Tile::setScale(float scale)
    {
        Tile::setScale(sf::Vector2f(scale, scale));
    }
    void Tile::setScale(const sf::Vector2f &scale)
    {
        s_Scale = scale;
    }

    void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform.scale(s_Scale);
        states.transform.translate(m_Postion);
        target.draw(m_Sprite, states);
    }
}