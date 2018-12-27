#include "window.h"
#include "input.h"
#include <string>
#include <cassert>
#include <stdexcept>

doodle::Window doodle::create_window(const std::string & title, SDL_Point pos, SDL_Point dim, std::uint32_t flags)
{
	auto sdl_window = SDL_CreateWindow(title.c_str(), pos.x, pos.y, dim.x, dim.y, flags);
	if (!sdl_window)
		throw std::runtime_error("Could not create doodle::Window " + std::string(SDL_GetError()));
	return Window(sdl_window);
}

bool doodle::Window::poll_events() const noexcept
{
	if (should_close) return false;
	for (std::size_t i = 0; i < NUM_KEYBOARD_KEYS; i++) 
	{
		InputHandler::key_up[i] = false;
		InputHandler::key_down[i] = false;
	}
	for (std::size_t i = 0; i < NUM_MOUSE_BUTTONS; i++) 
	{
		InputHandler::mouse_up[i] = false;
		InputHandler::mouse_down[i] = false;
	}
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type)
		{
		case SDL_QUIT:
			return false;
		case SDL_KEYDOWN:
			InputHandler::key_down[static_cast<std::size_t>(e.key.keysym.scancode)] = true;
			break;
		case SDL_KEYUP:
			InputHandler::key_up[static_cast<std::size_t>(e.key.keysym.scancode)] = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
			InputHandler::mouse_down[static_cast<std::size_t>(e.button.button) - 1] = true;
			break;
		case SDL_MOUSEBUTTONUP:
			InputHandler::mouse_up[static_cast<std::size_t>(e.button.button) - 1] = true;
			break;
		default:
			break;
		}
	}
	return  true;
}

std::string doodle::Window::title() const noexcept
{
	return std::string(SDL_GetWindowTitle(*this));
}

void doodle::Window::set_title(const std::string & title) noexcept
{
	SDL_SetWindowTitle(*this, title.c_str());
}

void doodle::Window::set_icon(SDL_Surface * icon) noexcept
{
	assert(icon);
	SDL_SetWindowIcon(*this, icon);
}

std::uint32_t doodle::Window::id() const noexcept
{
	return std::uint32_t(SDL_GetWindowID(*this));
}

void doodle::Window::close() noexcept
{
	should_close = true;
}

doodle::Window::Window(SDL_Window * window)
	: should_close(false), SDLResource(window, [](SDL_Window* window) { SDL_DestroyWindow(window); })
{
}
