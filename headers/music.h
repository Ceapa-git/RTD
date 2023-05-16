#ifndef RTD_MUSIC_H_INCLUDED
#define RTD_MUSIC_H_INCLUDED

#include "pch.h"
#include "pchSFML.h"

namespace rtd
{
    class Music
    {
    public:
        Music(const std::string &filename);
        Music() = delete;
        Music(const Music &) = delete;
        Music &operator=(const Music &) = delete;
        ~Music() {}

        void play();
        void pause();
        void restart();
        void setVolume(float volume);

    private:
        sf::Music m_music;
    };
}

#endif // RTD_MUSIC_H_INCLUDED