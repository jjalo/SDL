#include "Sprite.h"

Sprite::Sprite()
{

}

Sprite::Sprite(SDL_Texture* texture)
{
	this->position = Vector2(0, 0);
	this->texture  = texture;
}

Sprite::Sprite(SDL_Texture* texture, Vector2 scale)
{
	this->position = Vector2(0, 0);
	this->texture  = texture;
	this->scale    = scale;
}

Sprite::Sprite(SDL_Texture* texture, Vector2 scale, Vector2 sourcePosition, int width, int height)
{
	this->position = Vector2(0, 0);
	this->texture = texture;
	this->scale = scale;

	SDL_Rect* srcRect = new SDL_Rect();
	srcRect->h = height;
	srcRect->w = width;
	srcRect->x = sourcePosition.x;
	srcRect->y = sourcePosition.y;
	this->sourceRect = srcRect;

	isOnSpriteSheet = true;
}

Sprite::Sprite(SDL_Texture* texture, bool fillScreen)
{
	this->position   = Vector2(0, 0);
	this->texture    = texture;
	this->fillScreen = fillScreen;
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(texture);
}

void Sprite::SetFill(bool value)
{
	fillScreen = value;
}

void Sprite::SetPosition(Vector2 newPosition)
{
	position = newPosition;
}

Vector2 Sprite::GetPosition()
{
	return position;
}

float Sprite::GetWidth()
{
	if (sourceRect != NULL)
	{
		return sourceRect->w;
	}
	else
	{
		return destinationRect->w;
	}
}

float Sprite::GetHeight()
{
	if (sourceRect != NULL)
	{
		return sourceRect->h;
	}
	else
	{
		return destinationRect->h;
	}
}

void Sprite::Draw(GraphicsManager& gm)
{
	destinationRect->x = position.x;
	destinationRect->y = position.y;

	if (!isOnSpriteSheet)
	{
		SDL_QueryTexture(texture, NULL, NULL, &destinationRect->w, &destinationRect->h);
	}
	else
	{
		// The dimensions for the image will be the width and height 
		// of the sourceRectangle instead when a sprite is on a sheet.
		destinationRect->w = GetWidth();
		destinationRect->h = GetHeight();
	}
	
	if (fillScreen == false)
	{
		destinationRect->w = GetWidth() * scale.x;
		destinationRect->h = GetHeight() * scale.y;
	}
	else
	{
		destinationRect->w = GraphicsManager::SCREEN_WIDTH;
		destinationRect->h = GraphicsManager::SCREEN_HEIGHT;
	}

	SDL_RenderCopy(gm.GetRenderer(), texture, sourceRect, destinationRect);
}