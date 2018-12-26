#pragma once

#include <SDL.h>
#include <string>
#include "clock.h"
#include "renderer.h"
#include "sdl_resource.h"

namespace doodle {

	// The Window class
	class Window final : public internal::SDLResource<SDL_Window> {
	public:

		// Process system events.
		bool poll_events() const noexcept;

		// Return the window's renderer.
		Renderer renderer() const noexcept;

		// Return the window's title.
		std::string title() const noexcept;

		// Set the window's title
		void set_title(const std::string& title) noexcept;

		// Set the window's icon.
		void set_icon(SDL_Surface* icon) noexcept;

		// Clears the window with the given color.
		void clear(const SDL_Color& color = { 0, 0, 0, 0 }) noexcept;

		// Displays what has been rendered.
		void display() noexcept;

		// Returns the time taken between consecutive frames.
		std::uint32_t delta_time() const noexcept;

	private:
		mutable Clock frametimer;
		Renderer window_renderer;
	};

}