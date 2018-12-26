#pragma once

#include <SDL.h>
#include <string>
#include "clock.h"
#include "sdl_resource.h"

namespace doodle {

	// The Window class
	class Window final : public internal::SDLResource<SDL_Window> {
	public:

		// Creates a new doodle::Window.
		// title: The title of the window.
		// pos:   The window's position.
		// dim:   The window's dimensions.
		// flags: Window creation flags.
		friend Window create_window(const std::string& title, SDL_Point pos, SDL_Point dim, std::uint32_t flags);

		// Process system events.
		bool poll_events() const noexcept;

		// Return the window's title.
		std::string title() const noexcept;

		// Set the window's title
		void set_title(const std::string& title) noexcept;

		// Set the window's icon.
		void set_icon(SDL_Surface* icon) noexcept;

		// Returns the window's.
		std::uint32_t id() const noexcept;

	private:
		Window(SDL_Window* window);
	};

}