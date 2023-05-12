#include "pch.h"
#include "pchSFML.h"

#include "sprite.h"
#include "resourcemanager.h"

namespace rtd
{
    Sprite::Sprite(const std::string &filename)
    {
        ResourceManager &manager = ResourceManager::getInstance();
        m_Texture = manager.getTexture(filename);
        m_Sprite.setTexture(m_Texture);
    }

    void Sprite::setTexture(const std::string &filename)
    {
        ResourceManager &manager = ResourceManager::getInstance();
        m_Texture = manager.getTexture(filename);
        m_Sprite.setTexture(m_Texture);
    }

    void Sprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(m_Sprite, states);
    }
}