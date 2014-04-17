#ifndef __GraphicsManager_h__
#define __GraphicsManager_h__

#include <iostream>
#include "SDL.h"

class GraphicsManager
{
	public:
		static const int SCREEN_HEIGHT;
		static const int SCREEN_WIDTH;

		GraphicsManager();
		~GraphicsManager();
		void Render();
		SDL_Texture* LoadTexture(std::string path);
		void RenderTexture(SDL_Texture* texture, SDL_Renderer* rend, int x, int y);
		SDL_Renderer* GetRenderer();
		void DisplaySplashScreen();
		void LoadResources();

	private:
		SDL_Renderer* renderer;
		SDL_Window*   window;
		
};

#endif