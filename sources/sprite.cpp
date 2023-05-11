#include "pch.h"
#include "pchSFML.h"

#include "sprite.h"

namespace rtd
{
    Sprite::Sprite(const char *filename)
    {
        m_Texture.loadFromFile(filename);
        m_Sprite.setTexture(m_Texture);
    }

    void Sprite::setTexture(const char *filename)
    {
        m_Texture.loadFromFile(filename);
        m_Sprite.setTexture(m_Texture);
    }

    void Sprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(m_Sprite, states);
    }
}