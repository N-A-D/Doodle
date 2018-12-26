#include "window.h"
#include "input.h"

bool doodle::Window::poll_events() const noexcept
{
	for (std::size_t i = 0; i < NUM_KEYBOARD_KEYS; i++) {
		InputHandler::key_up[i] = false;
		InputHandler::key_down[i] = false;
	}
	for (std::size_t i = 0; i < NUM_MOUSE_BUTTONS; i++) {
		InputHandler::mouse_up[i] = false;
		InputHandler::mouse_down[i] = false;
	}
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			return false;
		case SDL_KEYUP:
			InputHandler::key_up[static_cast<std::size_t>(event.key.keysym.scancode)] = true;
			break;
		case SDL_KEYDOWN:
			InputHandler::key_down[static_cast<std::size_t>(event.key.keysym.scancode)] = true;
			break;
		case SDL_MOUSEBUTTONUP:
			InputHandler::mouse_up[static_cast<std::size_t>(event.button.button) - 1];
			break;
		case SDL_MOUSEBUTTONDOWN:
			InputHandler::mouse_down[static_cast<std::size_t>(event.button.button) - 1];
			break;
		default:
			break;
		}
	}
	return true;
}

doodle::Renderer doodle::Window::renderer() const noexcept
{
	return window_renderer;
}

std::string doodle::Window::title() const noexcept
{
	return std::string(SDL_GetWindowTitle(resource.get()));
}

void doodle::Window::set_title(const std::string & title) noexcept
{
	SDL_SetWindowTitle(resource.get(), title.c_str());
}

void doodle::Window::set_icon(SDL_Surface * icon) noexcept
{
	SDL_SetWindowIcon(resource.get(), icon);
}

void doodle::Window::clear(const SDL_Color & color) noexcept
{
	window_renderer.set_draw_color(color);
	SDL_RenderClear(window_renderer);
}

void doodle::Window::display() noexcept
{
	SDL_RenderPresent(window_renderer);
}

std::uint32_t doodle::Window::delta_time() const noexcept
{
	return frametimer.ticks();
}
