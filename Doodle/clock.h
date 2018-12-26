#pragma once

#include <SDL.h>
#include <cstdint>

namespace doodle {

	class Clock final {
	public:

		// Starts/Restarts the clock.
		void start() noexcept;
		
		// Returns the time elapsed since creation or the last call to start()
		std::uint32_t elapsed() const noexcept;

		// Returns time in between calls.
		std::uint32_t ticks() noexcept;

	private:
		std::uint32_t cur = SDL_GetTicks();
	};

}