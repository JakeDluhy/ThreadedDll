#pragma once

#include <thread>
#include <atomic>

using std::thread;
using std::atomic;

class Threader
{
public:
	Threader(void(*frameReadyCB)());
	~Threader();

	void start();
	void stop();
private:
	void renderLoop();

	atomic<bool> isThreading;
	void(*frameReadyCB)();
	thread myThread;
};

