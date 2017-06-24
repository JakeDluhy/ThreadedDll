// ThreadedDll.cpp : Defines the exported functions for the DLL application.
//
#include "ThreadedDll.h"
#include "Threader.h"

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
}

void stopStreaming()
{
	if (threader) threader->stop();
}