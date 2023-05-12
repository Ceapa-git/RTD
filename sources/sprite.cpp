#include "pch.h"
#include "pchSFML.h"

#include "sprite.h"
#include "resourcemanager.h"

namespace rtd
{
    Sprite::Sprite(const std::string &filename)
    {
        ResourceManager &manager = ResourceManager::getInstance();
        m_texture = manager.getTexture(filename);
        m_sprite.setTexture(m_texture);
    }

    void Sprite::setTexture(const std::string &filename)
    {
        ResourceManager &manager = ResourceManager::getInstance();
        m_texture = manager.getTexture(filename);
        m_sprite.setTexture(m_texture);
    }

    void Sprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(m_sprite, states);
    }
}