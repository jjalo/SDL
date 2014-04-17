#ifndef __Input_h__
#define __Input_h__

#include <Map>
#include "SDL.h"

static class Input
{
	public:
		static void Initialize();
		static void Update();
		static int ConsoleInputThread(void* ptr);
	private:
		static SDL_Joystick* stick;
};

#endif