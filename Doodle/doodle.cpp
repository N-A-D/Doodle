#include "doodle.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <stdexcept>
#include <string>

void doodle::init()
{
	if (SDL_Init(0))
		throw std::runtime_error("ERROR::SDL::INITIALIZATION_FAILED - " + std::string(SDL_GetError()));

	if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
		throw std::runtime_error("ERROR::SDL::SUBSYSTEM::VIDEO::INITIALIZATION_FAILED - " + std::string(SDL_GetError()));

	int flags = IMG_INIT_PNG;
	if (!(IMG_Init(flags) & flags))
		throw std::runtime_error("ERROR::SDL_IMAGE::INITIALIZATION_FAILED - " + std::string(IMG_GetError()));

	if (TTF_Init() == -1)
		throw std::runtime_error("ERROR::SDL_TTF::INITIALIZATION_FAILED - " + std::string(TTF_GetError()));

	if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0)
		throw std::runtime_error("ERROR::SDL::SUBSYSTEM::AUDIO::INITIALIZATION_FAILED - " + std::string(SDL_GetError()));

	flags = MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_FLAC;
	if (!(Mix_Init(flags) < 0))
		throw std::runtime_error("ERROR::SDL_MIXER::INITIALIZATION_FAILED - " + std::string(Mix_GetError()));
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		throw std::runtime_error("ERROR::SDL_MIXER::MIXER::INITIALIZATION_FAILED - " + std::string(Mix_GetError()));
	Mix_AllocateChannels(8);
}

void doodle::quit()
{
	Mix_AllocateChannels(0);
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
