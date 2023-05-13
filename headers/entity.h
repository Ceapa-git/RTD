#ifndef RTD_ENTITY_H_INCLUDED
#define RTD_ENTITY_H_INCLUDED

#include "pch.h"
#include "pchSFML.h"

#include "sprite.h"

namespace rtd
{
    class Entity : public sf::Drawable, public sf::Transformable
    {
    public:
        Entity(const std::vector<std::string> &filenames, float x = 0.f, float y = 0.f);
        Entity() = delete;
        Entity(const Entity &) = delete;
        Entity &operator=(const Entity &) = delete;
        ~Entity() {}

        void update();
        void draw(sf::RenderTarget &targer, sf::RenderStates states) const override;

    private:
        std::unique_ptr<rtd::Sprite[]> m_sprites;
        int m_spriteCount;
        int m_currentSprite;
        int m_updateCount;

    private:
        inline static int s_updatedPerFrame = 20;
    };
}

#endif // RTD_ENTITY_H_INCLUDED