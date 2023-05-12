#include "pch.h"
#include "pchSFML.h"

#include "sprite.h"
#include "resourcemanager.h"

namespace rtd
{
    Sprite::Sprite(const char *filename)
    {
        ResourceManager &manager = ResourceManager::getInstance();
        m_Texture = manager.getTexture(filename);
        m_Sprite.setTexture(m_Texture);
    }

    void Sprite::setTexture(const char *filename)
    {
        ResourceManager &manager = ResourceManager::getInstance();
        m_Texture = manager.getTexture(filename);
        m_Sprite.setTexture(m_Texture);
    }

    void Sprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(m_Sprite, states);
    }
}