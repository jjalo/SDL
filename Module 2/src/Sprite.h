#ifndef  __Sprite_h__
#define __Sprite_h__

#include "GraphicsManager.h"

struct Vector2
{
	public: 
		float x;
		float y;

		Vector2() { }

		Vector2(float posX, float posY)
		{
			x = posX;
			y = posY;
		}
};

class Sprite
{
	public:
		Sprite();
		Sprite(SDL_Texture* texture);
		Sprite(SDL_Texture* texture, bool fillScreen);
		Sprite(SDL_Texture* texture, Vector2 scale);
		Sprite(SDL_Texture* texture, Vector2 scale, Vector2 sourcePosition, int width, int height);
		virtual ~Sprite();
		void Draw(GraphicsManager& gm);
		void SetFill(bool value);
		void SetPosition(Vector2 newPosition);
		Vector2 GetPosition();
		float GetWidth();
		float GetHeight();

	private:
		Vector2 position;
		Vector2 scale;
		SDL_Texture* texture;
		SDL_Rect* destinationRect = new SDL_Rect();
		SDL_Rect* sourceRect = NULL;
		bool fillScreen = false;
		bool isOnSpriteSheet = false;
};

#endif
