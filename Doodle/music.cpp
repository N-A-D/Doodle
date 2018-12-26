#include "music.h"
#include <stdexcept>

doodle::Music doodle::load_music(const std::string & filename)
{
	auto mix_music = Mix_LoadMUS(filename.c_str());
	if (!mix_music)
		throw std::runtime_error("Could not create doodle::Music " + std::string(Mix_GetError()));
	return Music(mix_music);
}

void doodle::Music::play(int loops) const noexcept
{
	Mix_PlayMusic(*this, loops);
}

void doodle::Music::fade_in(int loops, int fade_in_time) const noexcept
{
	Mix_FadeInMusic(*this, loops, fade_in_time);
}

doodle::Music::Music(Mix_Music * music)
	: SDLResource(music, [](Mix_Music* music) { Mix_FreeMusic(music); })
{
}
