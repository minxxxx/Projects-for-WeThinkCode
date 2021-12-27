#include <TimeManager.class.hpp>
using namespace std;
using namespace chrono;


TimeManager::TimeManager(void)
{
    return ;
}

double TimeManager::calculateFrameRate(bool writeToConsole = false)
{
	// Below we create a bunch of static variables to track the deltas of the time.

	static double framesPerSecond = 0.0f;
	static double startTime = this->getTime();
	static double lastTime = this->getTime();
	//static char strFrameRate[50] = { 0 };
	static double currentFPS = 0.0f;

    this->currentTime = this->getTime();
    this->deltaTime = this->currentTime - lastTime;

	lastTime = this->currentTime;
	++framesPerSecond;

	if ( this->currentTime - startTime > 1.0f )
	{
		startTime = this->currentTime;
		if ( writeToConsole )
			fprintf(stderr, "Current Frames Per Second: %d\n", int(framesPerSecond));

		currentFPS = framesPerSecond;
		framesPerSecond = 0;
	}

	return currentFPS;
}



double TimeManager::getTime()
{

	auto beginningOfTime = system_clock::now().time_since_epoch();
	auto ms = duration_cast<milliseconds>(beginningOfTime).count();

	return ms * 0.001;
}


void TimeManager::sleep(int ms)
{
	this_thread::sleep_for( milliseconds(ms) );
}