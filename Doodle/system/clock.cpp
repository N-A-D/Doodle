#include "clock.h"

void doodle::Clock::start() noexcept
{
	cur = SDL_GetTicks();
}

std::uint32_t doodle::Clock::elapsed() const noexcept
{
	return SDL_GetTicks() - cur;
}

std::uint32_t doodle::Clock::delta_time() noexcept
{
	auto ret = elapsed();
	start();
	return ret;
}
