#pragma once

#include <vector>
#include <cstddef>

namespace doodle {

	class FrameCounter {
	public:
		FrameCounter(std::size_t samples = 10000);

		// Returns the minimum attained frame rate.
		double min_frame_rate() noexcept;

		// Returns the current frame rate.
		double avg_frame_rate() noexcept;

		// Returns the maximum attained frame rate.
		double max_frame_rate() noexcept;

	private:
		
		// Calculates min/max fps.
		double calc_frame_rate() noexcept;

		// Collection of frame times.
		std::vector<std::uint32_t> frame_times;

		// The last frame time calculated.
		std::uint32_t last_frame_time;

		// Number of frame time samples.
		std::size_t samples;

		// Current index in the frame time container.
		std::size_t index;

		// Current min/max frame rates
		double min_fps, max_fps;
	};

}