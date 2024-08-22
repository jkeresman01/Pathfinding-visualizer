#include "headers/ResourceManager.h"

#include "headers/Logger.h"

namespace pfv
{

const sf::Texture &ResourceManager::getTexture(const std::filesystem::path &filepath)
{
    TexturesUnorderedMapT::const_iterator it = m_textures.find(filepath.string());

    if (it == m_textures.end())
    {
        loadTexture(filepath);
        it = m_textures.find(filepath);
    }

    return it->second;
}

void ResourceManager::loadTexture(const std::filesystem::path &filepath)
{
    sf::Texture texture;

    bool isTextureLoadedSuccessfully = texture.loadFromFile(filepath);

    if (!isTextureLoadedSuccessfully)
    {
        LOG_ERROR("Failed to texture from " << filepath.string() << "!");
        return;
    }

    m_textures.emplace(filepath.string(), texture);
}

const sf::Font &ResourceManager::getFont(const std::filesystem::path &filepath)
{
    FontsUnorderedMapT::const_iterator it = m_fonts.find(filepath.string());

    if (it == m_fonts.end())
    {
        loadFont(filepath);
        it = m_fonts.find(filepath);
    }

    return it->second;
}

void ResourceManager::loadFont(const std::filesystem::path &filepath)
{
    sf::Font font;

    bool isFontLoadedSuccesfully = font.loadFromFile(filepath);

    if (!isFontLoadedSuccesfully)
    {
        LOG_ERROR("Failed to load font from " << filepath.string() << "!");
        return;
    }

    m_fonts.emplace(filepath.string(), font);
}

const sf::SoundBuffer &ResourceManager::getSoundBuffer(const std::filesystem::path &filepath)
{
    SoundBuffersUnorderedMapT::const_iterator it = m_soundBuffers.find(filepath.string());

    if (it == m_soundBuffers.end())
    {
        loadSoundBuffer(filepath);
        it = m_soundBuffers.find(filepath);
    }

    return it->second;
}

void ResourceManager::loadSoundBuffer(const std::filesystem::path &filepath)
{
    sf::SoundBuffer soundBuffer;

    bool isSoundBufferLoadedSuccsfully = soundBuffer.loadFromFile(filepath);

    if (!isSoundBufferLoadedSuccsfully)
    {
        LOG_ERROR("Failed to texture from " << filepath.string() << "!");
        return;
    }

    m_soundBuffers.emplace(filepath.string(), soundBuffer);
}

ResourceManager &ResourceManager::Instance()
{
    static ResourceManager instace;
    return instace;
}

} // namespace pfv
