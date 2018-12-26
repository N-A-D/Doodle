#pragma once

#include <string>
#include <SDL_mixer.h>
#include "sdl_resource.h"

namespace doodle {

	class Music final : public internal::SDLResource<Mix_Music> {
	public:

		// Plays this music track
		// loops: The number of times to loop. -1 is infinite
		void play(int loops) const noexcept;

		// Fade-in this music track
		// loops: The number of times to loop. -1 is infinite
		// fade_in_time: The time to fade in
		void fade_in(int loops, int fade_in_time) const noexcept;

	private:
		Music(Mix_Music* music);
	
		friend Music load_music(const std::string& filename);
	};

}