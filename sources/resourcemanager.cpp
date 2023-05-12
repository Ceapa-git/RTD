#include "pch.h"
#include "pchSFML.h"

#include "resourcemanager.h"
#include "sprite.h"

namespace rtd
{
    ResourceManager &ResourceManager::getInstance()
    {
        static ResourceManager instance;
        return instance;
    }

    sf::Texture &ResourceManager::getTexture(const std::string &filename)
    {
        if (textures.find(filename) != textures.end())
            return *textures.at(filename);

        std::cout << "Generate texture from " << filename << std::endl;
        auto newTexture = std::make_shared<sf::Texture>();
        if (!newTexture->loadFromFile(filename))
            throw std::runtime_error("Failed to load texture from " + filename);
        textures[filename] = newTexture;
        return *newTexture;
    }
    void ResourceManager::removeTexture(const std::string &filename)
    {
        textures.erase(filename);
    }

    rtd::Sprite &ResourceManager::getSprite(const std::string &filename)
    {
        if (sprites.find(filename) != sprites.end())
            return *sprites.at(filename);

        std::cout << "Generate sprite from " << filename << std::endl;
        sprites[filename] = std::make_shared<rtd::Sprite>(filename);
        return *sprites.at(filename);
    }
    void ResourceManager::removeSprite(const std::string &filename)
    {
        sprites.erase(filename);
    }
}