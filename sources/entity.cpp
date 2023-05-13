#include "pch.h"
#include "pchSFML.h"

#include "entity.h"
#include "resourcemanager.h"
#include "sprite.h"

namespace rtd
{
    Entity::Entity(const std::vector<std::string> &filenames, float x, float y)
    {
        rtd::ResourceManager &manager = rtd::ResourceManager::getInstance();
        m_spriteCount = filenames.size();
        m_sprites = std::make_unique<rtd::Sprite[]>(m_spriteCount);
        for (int i = 0; i < m_spriteCount; i++)
            m_sprites[i] = manager.getSprite(filenames[i]);
        m_updateCount = 0;
        m_currentSprite = 0;
        move(x, y);
    }

    void Entity::update()
    {
        m_updateCount++;
        if (m_updateCount >= s_updatedPerFrame)
        {
            m_updateCount = 0;
            m_currentSprite = (m_currentSprite + 1) % m_spriteCount;
        }
    }
    void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform.combine(getTransform());
        target.draw(m_sprites[m_currentSprite], states);
    }
}