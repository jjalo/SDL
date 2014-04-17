#include "Input.h"
#include "Command.h"
#include "Game.h"

using namespace std;

SDL_Joystick* Input::stick;

void Input::Initialize()
{
	SDL_Thread* consoleThread = SDL_CreateThread(Input::ConsoleInputThread, "ConsoleInput", NULL);

	if (SDL_NumJoysticks() > 0)
	{
		stick = SDL_JoystickOpen(0);
	}
}

void Input::Update()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_JOYDEVICEADDED:
				stick = SDL_JoystickOpen(0);
				break;

			case SDL_JOYDEVICEREMOVED:
				SDL_JoystickClose(0);
				break;

			case SDL_KEYDOWN: case SDL_QUIT:  case SDL_JOYHATMOTION: case SDL_JOYBUTTONDOWN:
				Command *pCmd = CommandUtils::Parse(event);
				pCmd->Execute(*Game::GetInstance());
				cout << string(2, '\b');
				cout << "> ";
				delete pCmd;
				break;
		}
	}
}

int Input::ConsoleInputThread(void* ptr)
{
	while (true)
	{
		if (Game::GetInstance()->GetProperty("running"))
		{
			cout << "> ";

			string tmp;
			getline(cin, tmp);

			Command *pCmd = CommandUtils::Parse(tmp);
			pCmd->Execute(*Game::GetInstance());
			delete pCmd;
		}
	}

	return 0;
}