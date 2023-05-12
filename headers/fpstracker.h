#ifndef RTD_FPSTRACKER_H_INCLUDED
#define RTD_FPSTRACKER_H_INCLUDED

#include "pch.h"
#include "pchSFML.h"

namespace rtd
{
    class FpsTracker final
    {
    public:
        FpsTracker(int historySize);
        FpsTracker(const FpsTracker &) = delete;
        FpsTracker &operator=(const FpsTracker &) = delete;
        ~FpsTracker() {}

        void update();
        double getAverageFps() const;
        double getAverageFrameTime() const;
        double getMinFrameTime() const;
        double getMaxFrameTime() const;

    private:
        int m_historySize;
        std::chrono::milliseconds m_averageTime;

        std::deque<std::chrono::milliseconds> m_frameTimes;
        std::chrono::time_point<std::chrono::high_resolution_clock> m_lastUpdateTime;
    };
}

#endif // RTD_FPSTRACKER_H_INCLUDED