#include "renderer.h"
#include <iostream>

Window::Window(const char* title, int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
		if(!window)
		{
			IsRunning = false;
		}
		IsRunning = true;
	}else
	{
		IsRunning = false;
	}
}
void Window::HandleInput()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	auto type = e.type;
	switch(type)
	{
	SDL_QUIT:
		IsRunning = false;
		std::cout << "No longer running \n";
		break;
	}
}