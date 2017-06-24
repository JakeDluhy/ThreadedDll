#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifdef THREADEDDLL_EXPORTS
#define THREADEDDLL_API __declspec(dllexport)
#else
#define THREADEDDLL_API __declspec(dllimport)
#endif
	THREADEDDLL_API void beginSession(void(*frameReadyCB)());
	THREADEDDLL_API void endSession();

	THREADEDDLL_API void startStreaming();
	THREADEDDLL_API void stopStreaming();
#ifdef __cplusplus
}
#endif