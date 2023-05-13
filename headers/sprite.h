#ifndef RTD_SPRITE_H_INCLUDED
#define RTD_SPRITE_H_INCLUDED

#include "pch.h"
#include "pchSFML.h"

namespace rtd
{
    class Sprite : public sf::Drawable
    {

    public:
        Sprite(){};
        Sprite(const std::string &filename);
        ~Sprite(){};

        void setTexture(const std::string &filename);
        void setScale(float scaleX, float scaleY);

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    private:
        sf::Texture m_texture;
        sf::Sprite m_sprite;
    };
}
#endif // RTD_SPRITE_H_INCLUDED