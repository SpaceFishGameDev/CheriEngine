#include "Game.h"

SDL_Texture* player_tex;


Game::Game() 
{
	
}

Game::~Game() 
{

}

void Game::Init(const char* title, int x, int y, int width, int height, bool FullScreen)
{
	int flags = 0;

	if (FullScreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL initialized, creating window..." << std::endl;
		
		this->window = SDL_CreateWindow(title, x, y, width, height, flags);
		
		if (window)
		{
			std::cout << "Window created, creating renderer... \n";
		}
		
		renderer = SDL_CreateRenderer(window, -1, 0);
		
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer,200,220,200,255);
			std::cout << "Renderer created..." << std::endl;
		}

		IsRunning = true;
		SDL_Surface* tmpSurf = IMG_Load("D:/CheriEngine/CheriEngine/assets/Char.png");
	}
	else
	{
		IsRunning = false;
	}
	
	
}

void Game::HandleEvents()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	switch(e.type)
	{
	SDL_QUIT:
		IsRunning = false;
		break;
	}
}

void Game::Update()
{

}

void Game::Render()
{
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game exited\n";
}
