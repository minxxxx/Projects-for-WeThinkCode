#ifndef TIMEMANGER_CLASS_HPP
#define TIMEMANGER_CLASS_HPP

#include <chrono>													// Used for the C++ 11 time functionality
#include <thread>													// used for the C++ 11 sleep functionality


class TimeManager
{
    public:
        static TimeManager& instance()
        {
            static TimeManager instance;

            return instance;
        }


        double calculateFrameRate(bool writeToConsole);
        double getTime();
        void sleep(int milliseconds);
        double deltaTime = 0;
        double currentTime = 0;

        int step = 1;

    private:
        TimeManager(void);
        TimeManager(TimeManager const&);
        TimeManager& operator=(TimeManager const&);
};

#endif