#ifndef RTD_FPSTRACKER_H_INCLUDED
#define RTD_FPSTRACKER_H_INCLUDED

#include "pch.h"
#include "pchSFML.h"

namespace rtd
{
    class FpsTracker final
    {
    public:
        FpsTracker(std::chrono::milliseconds historySize,
                   std::chrono::milliseconds averageTime);
        FpsTracker()
            : FpsTracker(std::chrono::milliseconds(1000),
                         std::chrono::milliseconds(100)) {}
        FpsTracker(const FpsTracker &) = delete;
        FpsTracker &operator=(const FpsTracker &) = delete;
        ~FpsTracker() {}

        void update();
        double getAverageFps() const;
        double getAverageFrameTime() const;
        double getMinFrameTime() const;
        double getMaxFrameTime() const;

    private:
        std::chrono::milliseconds m_historySize;
        std::chrono::milliseconds m_averageTime;

        std::deque<std::chrono::milliseconds> m_frameTimes;
        std::chrono::milliseconds m_totalFrameTime;
        std::chrono::milliseconds m_minFrameTime;
        std::chrono::milliseconds m_maxFrameTime;
        std::chrono::time_point<std::chrono::steady_clock> m_lastUpdateTime;

        double m_averageFps;
        double m_averageFrameTime;
    };
}

#endif // RTD_FPSTRACKER_H_INCLUDED