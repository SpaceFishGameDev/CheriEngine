#pragma once
#include "Window.h"
class Texture
{
public:
	const char* path;
	SDL_Surface* surface;
	SDL_Texture* texture;
	Texture(const char* path, SDL_Renderer* renderer)
	{
		surface = IMG_Load(path);
		texture = SDL_CreateTextureFromSurface(renderer, surface);
	}
};
class GameObject
{
private:
	SDL_Renderer* renderer;
public:
	Vector2 Position = Vector2(0,0);
	const char* name;
	GameObject(SDL_Renderer* renderer_, Vector2 Position, const char* name_)
	{
		this->renderer = renderer_;
		this->Position = Position;
		this->name = name_;
	}
};
