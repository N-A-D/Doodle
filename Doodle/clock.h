#pragma once

#include <SDL.h>
#include <cstdint>

namespace doodle {

	class Clock final {
	public:
		void start() noexcept;
		std::uint32_t elapsed() const noexcept;
		std::uint32_t ticks() noexcept;
	private:
		std::uint32_t cur = SDL_GetTicks();
	};

}