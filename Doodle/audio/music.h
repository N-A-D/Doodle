#pragma once

#include <string>
#include <SDL2/SDL_mixer.h>
#include "../asset/asset.h"
#include "../internal/sdl_resource.h"

namespace doodle {

	class Music final 
		: public Asset<Music>
		, public internal::SDLResource<Mix_Music> 
	{
	public:

		Music(Mix_Music* music) noexcept;

		// Plays this music track
		// loops: The number of times to loop. -1 is infinite
		void play(int loops) const noexcept;

		// Fade-in this music track
		// loops: The number of times to loop. -1 is infinite
		// fade_in_time: The time to fade in
		void fade_in(int loops, int fade_in_time) const noexcept;

	};

	// Loads a new Mix_Music resource.
	Mix_Music* load_music(const std::string& filename);

}