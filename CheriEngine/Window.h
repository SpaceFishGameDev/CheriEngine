#pragma once
#include<SDL.h>
#include "Vector2.h"
#include <SDL_image.h>
class Window
{
public:

	Window(const char* title, int width, int height);
	~Window();
	
	bool IsRunning;
	void HandleInput();

	SDL_Window* window = nullptr;
};

