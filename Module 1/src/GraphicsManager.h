#ifndef __GraphicsManager_h__
#define __GraphicsManager_h__

#include "SDL.h"

class GraphicsManager
{
	public:
		GraphicsManager();
		~GraphicsManager();
		void Render();
		void LoadBitmap(std::string path);

	private:
		SDL_Window*   window;
		SDL_Renderer* renderer;
		SDL_Texture* texture;
};

#endif