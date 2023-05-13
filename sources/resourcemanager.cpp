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
        if (m_textures.find(filename) != m_textures.end())
            return *m_textures.at(filename);

        std::cout << "Generate texture from " << filename << std::endl;
        auto newTexture = std::make_shared<sf::Texture>();
        if (!newTexture->loadFromFile(filename))
            throw std::runtime_error("Failed to load texture from " + filename);
        m_textures[filename] = newTexture;
        return *newTexture;
    }
    void ResourceManager::removeTexture(const std::string &filename)
    {
        m_textures.erase(filename);
    }

    rtd::Sprite &ResourceManager::getSprite(const std::string &filename)
    {
        if (m_sprites.find(filename) != m_sprites.end())
            return *m_sprites.at(filename);

        std::cout << "Generate sprite from " << filename << std::endl;
        auto newSprite = std::make_shared<rtd::Sprite>(filename);
        newSprite->setScale(2.f, 2.f);
        m_sprites[filename] = newSprite;
        return *newSprite;
    }
    void ResourceManager::removeSprite(const std::string &filename)
    {
        m_sprites.erase(filename);
    }
}