#include "Threader.h"

using std::cout;

Threader::Threader(void(*frameReadyCB)()) :
	isThreading{ false },
	frameReadyCB{ frameReadyCB }
{
}


Threader::~Threader()
{
	if (myThread.joinable()) myThread.join();
}

void Threader::start()
{
	cout << "Start";
	isThreading = true;

	myThread = thread(&Threader::renderLoop, this);
}

void Threader::stop()
{
	cout << "Stop";
	isThreading = false;

	if (myThread.joinable()) myThread.join();
}

void Threader::renderLoop()
{
	cout << "Render:start";
	while (isThreading) {
		frameReadyCB();
	}
	cout << "Render:stop";
}