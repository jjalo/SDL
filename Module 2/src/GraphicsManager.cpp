#include <iostream>
#include "GraphicsManager.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Sprite.h"

using namespace std;

const int GraphicsManager::SCREEN_HEIGHT = 400;
const int GraphicsManager::SCREEN_WIDTH  = 640;

GraphicsManager::GraphicsManager()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		throw runtime_error(SDL_GetError());
	}

	int initFlags = IMG_INIT_JPG | IMG_INIT_PNG;

	if (IMG_Init(initFlags) != initFlags)
	{
		throw runtime_error(IMG_GetError());
	}

	window = SDL_CreateWindow("Quick Escape", 10, 30, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		throw runtime_error(SDL_GetError());
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr)
	{
		throw runtime_error(SDL_GetError());
	}
}

SDL_Renderer* GraphicsManager::GetRenderer()
{
	return renderer;
}

GraphicsManager::~GraphicsManager()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* GraphicsManager::LoadTexture(std::string path)
{
	SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());

	if (texture == nullptr)
	{
		throw runtime_error(IMG_GetError());
	}

	return texture;
}

void GraphicsManager::Render()
{
	if (renderer != nullptr)
	{
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
	}
}