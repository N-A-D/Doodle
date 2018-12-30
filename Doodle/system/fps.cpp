#include "fps.h"
#include <numeric>
#include <SDL2/SDL.h>

doodle::FrameCounter::FrameCounter(std::size_t samples)
	: frame_times(samples, 0)
	, last_frame_time(SDL_GetTicks())
	, samples(samples)
	, index(0)
	, min_fps(std::numeric_limits<double>::infinity())
	, max_fps(-std::numeric_limits<double>::infinity())
{
}

double doodle::FrameCounter::min_frame_rate() const noexcept
{
	calc_frame_rate();
	return std::isinf(min_fps) ? 0 : std::round(min_fps);
}

double doodle::FrameCounter::avg_frame_rate() const noexcept
{
	return calc_frame_rate();
}

double doodle::FrameCounter::max_frame_rate() const noexcept
{
	calc_frame_rate();
	return std::isinf(max_fps) ? 0 : std::round(max_fps);
}

double doodle::FrameCounter::calc_frame_rate() const noexcept
{
	auto idx = index++ % samples;
	auto cur_frame_time = SDL_GetTicks();
	frame_times[idx] = cur_frame_time - last_frame_time;
	last_frame_time = cur_frame_time;
	
	auto count = index < samples ? index : samples;
	double avg_ft = 0.0;
	for (std::size_t i = 0; i < count; i++)
	{
		avg_ft += frame_times[i];
	}
	avg_ft /= count;
	double fps = 1000 / avg_ft;
	if (fps > max_fps) max_fps = fps;
	if (fps < min_fps) min_fps = fps;
	return fps > 20000 ? 0 : std::round(fps);
}
