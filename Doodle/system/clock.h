#pragma once

#include <cstdint>
#include <SDL2/SDL.h>

namespace doodle {

	// The Clock class
	class Clock final {
	public:

		// Starts/Restarts the clock.
		void start() noexcept;
		
		// Returns the time elapsed since creation or the last call to start()
		std::uint32_t elapsed() const noexcept;

		// Returns time in between calls.
		std::uint32_t delta_time() noexcept;

	private:
		std::uint32_t cur = SDL_GetTicks();
	};

}