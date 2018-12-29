#include "doodle.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>

void doodle::init()
{
	// Initialize SDL2 and its subsystems individually

	// Initialize SDL
	if (SDL_Init(0))
	{
		std::cerr << "SDL2: Failed to initialize!" << std::endl;
		std::cerr <<  "SDL2: " + std::string(SDL_GetError()) << std::endl;
	}
	else 
	{
		// Initialize SDL_image
		if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
		{
			std::cerr << "SDL2: Failed to initialize video subsystem!" << std::endl;
			std::cerr << "SDL2: " + std::string(SDL_GetError()) << std::endl;
		}
		else 
		{
			int flags = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF;
			int initted = IMG_Init(flags);
			if ((initted&flags) != flags)
			{
				std::cerr << "SDL2_image: Failed to initialize png, jpg, and tif support!" << std::endl;
				std::cerr << "SDL2_image: " + std::string(IMG_GetError()) << std::endl;
			}

			// Initialize SDL_ttf
			if (TTF_Init() == -1)
			{
				std::cerr << "SDL2_ttf: " + std::string(TTF_GetError()) << std::endl;
			}
		}
		// Initialize SDL_mixer
		if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0)
		{
			std::cerr << "SDL2: Failed to initialize audio subsystem!" << std::endl;
			std::cerr << "SDL2: " + std::string(SDL_GetError()) << std::endl;
		}
		else
		{
			// Initialize SDL_mixer
			if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0)
			{
				std::cerr << "SDL2: Failed to initialize audio subsystem!" << std::endl;
				std::cerr << "SDL2: " + std::string(SDL_GetError()) << std::endl;
			}
			int flags = MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_FLAC | MIX_INIT_MOD;
			int initted = Mix_Init(flags);
			if ((initted&flags) != flags)
			{
				std::cerr << "SDL2_mixer: Failed to initialize mp3, ogg, flac, and mod support!" << std::endl;
				std::cerr << "SDL2_mixer: " + std::string(Mix_GetError()) << std::endl;
			}
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
			{
				std::cerr << "Mix_OpenAudio: " + std::string(Mix_GetError()) << std::endl;
			}
			Mix_AllocateChannels(8);
		}
	}
}

void doodle::quit()
{
	Mix_AllocateChannels(0);
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
