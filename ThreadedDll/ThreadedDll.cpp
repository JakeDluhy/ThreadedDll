// ThreadedDll.cpp : Defines the exported functions for the DLL application.
//
#include "ThreadedDll.h"
#include "Threader.h"
#include <iostream>

using std::cout;

static Threader *threader = NULL;

void beginSession(void(*frameReadyCB)())
{
	threader = new Threader(frameReadyCB);
}

void endSession()
{
	delete threader;
	threader = NULL;
}

void startStreaming()
{
	if (threader) threader->start();
	cout << "Dll:start";
}

void stopStreaming()
{
	if (threader) threader->stop();
	cout << "Dll:stop";
}