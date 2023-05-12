#ifndef RTD_RESOURCEMANAGER_H_INCLUDED
#define RTD_RESOURCEMANAGER_H_INCLUDED

#include "pch.h"
#include "pchSFML.h"

#include "sprite.h"

namespace rtd
{
    class ResourceManager final
    {
    public:
        static ResourceManager &getInstance();

        sf::Texture &getTexture(const std::string &filename);
        void removeTexture(const std::string &filename);

        rtd::Sprite &getSprite(const std::string &filename);
        void removeSprite(const std::string &filename);

    private:
        ResourceManager() {}
        ResourceManager(const ResourceManager &) = delete;
        ResourceManager &operator=(const ResourceManager &) = delete;

        std::unordered_map<std::string, std::shared_ptr<sf::Texture>> textures;
        std::unordered_map<std::string, std::shared_ptr<rtd::Sprite>> sprites;
    };
}

#endif // RTD_RESOURCEMANAGER_H_INCLUDED