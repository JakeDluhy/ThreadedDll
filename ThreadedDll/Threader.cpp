#include "Threader.h"

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
	isThreading = true;

	myThread = thread(&Threader::renderLoop, this);
}

void Threader::stop()
{
	isThreading = false;

	if (myThread.joinable()) myThread.join();
}

void Threader::renderLoop()
{
	while (isThreading) {
		frameReadyCB();
	}
}