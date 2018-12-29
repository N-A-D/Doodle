#pragma once

#include <cstddef>
#include <SDL2/SDL.h>

namespace doodle {

	constexpr std::size_t NUM_MOUSE_BUTTONS = 3;

	// Enumaeration of mouse buttons
	enum class Mouse {
		LEFT_BUTTON   = 0,
		MIDDLE_BUTTON = 1,
		RIGHT_BUTTON  = 2,
	};

}