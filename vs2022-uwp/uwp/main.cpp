#include <Windows.h>
#include "SDL2/SDL.h"

extern "C" __declspec(dllimport) void* uwp_GetWindowReference();

int bootstrap(int argc, char** argv)
{
	uwp_GetWindowReference(); // Call once to init reference for other threads

	return SDL_main(argc, argv);
}

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR argv, int argc)
{
	return SDL_WinRTRunApp(bootstrap, NULL);
}
