#include "TimeMeter.h"
#include <windows.h>
#include <vector>

class TimeMeter::Impl {
public:
    Impl(unsigned count) : timeStamps(count) {
        LARGE_INTEGER freq;
        QueryPerformanceFrequency(&freq);
        frequency = freq.QuadPart;
        QueryPerformanceCounter(&startTime);
    }

    double setTimeStamp(unsigned num) {
        if (num >= timeStamps.size()) return -1.0;
        LARGE_INTEGER currentTime;
        QueryPerformanceCounter(&currentTime);
        timeStamps[num] = currentTime;
        return (currentTime.QuadPart - startTime.QuadPart) / static_cast<double>(frequency);
    }

    double getSTimeStamp(unsigned num) {
        if (num >= timeStamps.size()) return -1.0;
        return (timeStamps[num].QuadPart - startTime.QuadPart) / static_cast<double>(frequency);
    }

    int64_t getMSTimeStamp(unsigned num) {
        return static_cast<int64_t>(getSTimeStamp(num) * 1000);
    }

    double getSDiff(unsigned first, unsigned second) {
        return getSTimeStamp(second) - getSTimeStamp(first);
    }

    int64_t getMSDiff(unsigned first, unsigned second) {
        return static_cast<int64_t>(getSDiff(first, second) * 1000);
    }

    bool isLess(unsigned first, unsigned second, int64_t expected) {
        return getMSDiff(first, second) < expected;
    }

    bool isLess(unsigned num, int64_t expected) {
        return getMSTimeStamp(num) < expected;
    }

private:
    LARGE_INTEGER startTime;
    int64_t frequency;
    std::vector<LARGE_INTEGER> timeStamps;
};


TimeMeter::TimeMeter(unsigned count) : pImpl(std::make_unique<Impl>(count)) {}


double TimeMeter::setTimeStamp(unsigned num) { 
    return pImpl->setTimeStamp(num); 
}
double TimeMeter::getSTimeStamp(unsigned num) { 
    return pImpl->getSTimeStamp(num); 
}
int64_t TimeMeter::getMSTimeStamp(unsigned num) { 
    return pImpl->getMSTimeStamp(num); 
}
double TimeMeter::getSDiff(unsigned first, unsigned second) { 
    return pImpl->getSDiff(first, second); 
}
int64_t TimeMeter::getMSDiff(unsigned first, unsigned second) { 
    return pImpl->getMSDiff(first, second); 
}
bool TimeMeter::isLess(unsigned first, unsigned second, int64_t expected) { 
    return pImpl->isLess(first, second, expected); 
}
bool TimeMeter::isLess(unsigned num, int64_t expected) { 
    return pImpl->isLess(num, expected); 
}