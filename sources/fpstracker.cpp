#include "pch.h"
#include "pchSFML.h"

#include "fpstracker.h"

namespace rtd
{
    FpsTracker::FpsTracker(int historySize)
    {
        m_historySize = historySize;
        m_averageTime = std::chrono::milliseconds(0);
        m_lastUpdateTime = std::chrono::high_resolution_clock::now();
    }

    void FpsTracker::update()
    {
        auto currentTime = std::chrono::high_resolution_clock::now();
        auto frameTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - m_lastUpdateTime);
        m_frameTimes.push_back(frameTime);
        if ((int)m_frameTimes.size() > m_historySize)
            m_frameTimes.pop_front();
        m_lastUpdateTime = currentTime;
    }

    double FpsTracker::getAverageFps() const
    {
        double sum = 0.0;
        for (auto frame_time : m_frameTimes)
        {
            sum += 1.0 / std::chrono::duration_cast<std::chrono::duration<double>>(frame_time).count();
        }
        return sum / m_frameTimes.size();
    }
    double FpsTracker::getAverageFrameTime() const
    {
        double sum = 0.0;
        for (auto frame_time : m_frameTimes)
            sum += std::chrono::duration_cast<std::chrono::duration<double>>(frame_time).count();
        return sum / m_frameTimes.size() * 1000.0;
    }
    double FpsTracker::getMinFrameTime() const
    {
        auto it = std::min_element(m_frameTimes.begin(), m_frameTimes.end());
        return std::chrono::duration_cast<std::chrono::duration<double>>(*it).count() * 1000.0;
    }
    double FpsTracker::getMaxFrameTime() const
    {
        auto it = std::max_element(m_frameTimes.begin(), m_frameTimes.end());
        return std::chrono::duration_cast<std::chrono::duration<double>>(*it).count() * 1000.0;
    }

    double FpsTracker::getLastFrameTime() const
    {
        return std::chrono::duration_cast<std::chrono::duration<double>>(m_frameTimes.back()).count();
    }
}