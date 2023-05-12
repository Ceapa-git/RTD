#include "pch.h"
#include "pchSFML.h"

#include "fpstracker.h"

// By chat GPT
namespace rtd
{
    FpsTracker::FpsTracker(std::chrono::milliseconds historySize, std::chrono::milliseconds averageTime)
        : m_historySize(historySize),
          m_averageTime(averageTime),
          m_frameTimes(),
          m_totalFrameTime(0),
          m_minFrameTime(std::chrono::milliseconds::max()),
          m_maxFrameTime(std::chrono::milliseconds::zero()),
          m_lastUpdateTime(std::chrono::steady_clock::now()),
          m_averageFps(0),
          m_averageFrameTime(0)
    {
    }

    void FpsTracker::update()
    {
        // Calculate current frame time
        auto currentTime = std::chrono::steady_clock::now();
        auto frameTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - m_lastUpdateTime);
        m_lastUpdateTime = currentTime;

        // Add frame time to history and update total frame time
        m_frameTimes.push_back(frameTime);
        m_totalFrameTime += frameTime;

        // Remove oldest frame time if history size is exceeded
        while ((int)m_frameTimes.size() > m_historySize.count())
        {
            m_totalFrameTime -= m_frameTimes.front();
            m_frameTimes.pop_front();
        }

        // Calculate average FPS and average frame time
        if (m_totalFrameTime > std::chrono::milliseconds::zero())
        {
            m_averageFps = 1000.0 * m_frameTimes.size() / m_totalFrameTime.count();
            m_averageFrameTime = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(m_totalFrameTime / m_frameTimes.size()).count();
        }

        // Update min and max frame times over the last ten seconds
        std::chrono::milliseconds tenSeconds(10000);
        auto historyEnd = std::find_if(m_frameTimes.rbegin(), m_frameTimes.rend(),
                                       [currentTime, tenSeconds](std::chrono::milliseconds time)
                                       {
                                           return std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - std::chrono::steady_clock::now() + time) > tenSeconds;
                                       })
                              .base();

        for (auto it = historyEnd; it != m_frameTimes.end(); ++it)
        {
            if (*it > std::chrono::milliseconds::zero())
            {
                m_minFrameTime = std::min(*it, m_minFrameTime);
                m_maxFrameTime = std::max(*it, m_maxFrameTime);
            }
        }
    }

    double FpsTracker::getAverageFps() const
    {
        return m_averageFps;
    }

    double FpsTracker::getAverageFrameTime() const
    {
        return m_averageFrameTime;
    }

    double FpsTracker::getMinFrameTime() const
    {
        return m_minFrameTime.count();
    }

    double FpsTracker::getMaxFrameTime() const
    {
        return m_maxFrameTime.count();
    }
}