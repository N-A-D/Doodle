#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "../internal/sdl_resource.h"

namespace doodle {

	// The Window class
	class Window final : public internal::SDLResource<SDL_Window> {
	public:

		Window(SDL_Window* window) noexcept;

		// Process system events.
		// Returns false if the window should close, true otherwise.
		bool poll_events() const noexcept;

		// Return the window's title.
		std::string title() const noexcept;

		// Set the window's title
		void set_title(const std::string& title) noexcept;

		// Set the window's icon.
		void set_icon(SDL_Surface* icon) noexcept;

		// Returns the window's.
		std::uint32_t id() const noexcept;

		// Instructs the window to close.
		void close() noexcept;

	private:
		bool should_close = false;
	};

	// Loads a new SDL_Window resource.
	SDL_Window* create_window(const std::string& title, SDL_Point pos, SDL_Point dim, std::uint32_t flags);
}