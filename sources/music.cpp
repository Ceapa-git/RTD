#include "pch.h"
#include "pchSFML.h"

#include "music.h"

namespace rtd
{
    Music::Music(const std::string &filename)
    {
        if (!m_music.openFromFile(filename))
            throw new std::runtime_error("Failed to open music from " + filename);
    }

    void Music::play()
    {
        m_music.play();
    }
    void Music::pause()
    {
        m_music.pause();
    }
    void Music::restart()
    {
        m_music.stop();
        m_music.play();
    }
    void Music::setVolume(float volume)
    {
        if (volume < 0.f)
            volume = 0.f;
        if (volume > 100.f)
            volume = 100.f;
        m_music.setVolume(volume);
    }
}