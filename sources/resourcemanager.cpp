#include "pch.h"
#include "pchSFML.h"

#include "resourcemanager.h"

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

        std::cout << "generate texture for " << filename << std::endl;
        auto newTexture = std::make_shared<sf::Texture>();
        newTexture->loadFromFile(filename);
        textures[filename] = newTexture;
        return *newTexture;
    }
    void ResourceManager::removeTexture(const std::string &filename)
    {
        textures.erase(filename);
    }
}