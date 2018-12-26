#include "input.h"

bool doodle::InputHandler::state = true;
std::vector<bool> doodle::InputHandler::key_up(doodle::NUM_KEYBOARD_KEYS, false);
std::vector<bool> doodle::InputHandler::key_down(doodle::NUM_KEYBOARD_KEYS, false);
std::vector<bool> doodle::InputHandler::mouse_up(doodle::NUM_MOUSE_BUTTONS, false);
std::vector<bool> doodle::InputHandler::mouse_down(doodle::NUM_MOUSE_BUTTONS, false);

bool doodle::InputHandler::input_state() const noexcept
{
	return InputHandler::state;
}

void doodle::InputHandler::enable_input() const noexcept
{
	InputHandler::state = true;
}

void doodle::InputHandler::disable_input() const noexcept
{
	InputHandler::state = false;
}

bool doodle::InputHandler::is_mouse_up(Mouse button) const noexcept
{
	if (!InputHandler::state) return false;
	return InputHandler::mouse_up[static_cast<std::size_t>(button)];
}

bool doodle::InputHandler::is_mouse_down(Mouse button) const noexcept
{
	if (!InputHandler::state) return false;
	return InputHandler::mouse_down[static_cast<std::size_t>(button)];
}

bool doodle::InputHandler::is_mouse__pressed(Mouse button) const noexcept
{
	if (!InputHandler::state) return false;
	switch (button)
	{
	case doodle::Mouse::LEFT_BUTTON:
		return SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(SDL_BUTTON_LEFT);
	case doodle::Mouse::MIDDLE_BUTTON:
		return SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(SDL_BUTTON_MIDDLE);
	case doodle::Mouse::RIGHT_BUTTON:
		return SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(SDL_BUTTON_RIGHT);
	default:
		return false;
	}
}

bool doodle::InputHandler::is_key_up(Keyboard key) const noexcept
{
	if (!InputHandler::state) return false;
	return InputHandler::key_up[static_cast<std::size_t>(key)];
}

bool doodle::InputHandler::is_key_down(Keyboard key) const noexcept
{
	if (!InputHandler::state) return false;
	return InputHandler::key_down[static_cast<std::size_t>(key)];
}

bool doodle::InputHandler::is_key_pressed(Keyboard key) const noexcept
{
	if (!InputHandler::state) return false;
	auto current_keyboard_state = SDL_GetKeyboardState(nullptr);
	return current_keyboard_state[static_cast<std::size_t>(key)];
}

SDL_Point doodle::InputHandler::get_mouse_position() const noexcept
{
	SDL_Point pos;
	SDL_GetMouseState(&pos.x, &pos.y);
	return pos;
}
