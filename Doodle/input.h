#pragma once

#include <SDL.h>
#include <vector>
#include "mouse.h"
#include "keyboard.h"

namespace doodle {

	class Window;
	
	// The InputHandler class
	// Interface for discovering input events.
	// Note:
	// - Implementation follows the monostate pattern. 
	//   A call to doodle::Window::poll_events() is required every 
	//   frame in order to update input device states.
	class InputHandler final {
	public:

		// Checks the status of input event processing.
		// True indicates input events are enabled globally. 
		// False indicates input events have been disabled globally.
		bool input_state() const noexcept;

		// Enables input event processing by the system.
		void enable_input() const noexcept;

		// Disables all input event processing by the system.
		void disable_input() const noexcept;

		// Checks if a mouse button was released this frame.
		bool is_mouse_up(Mouse button) const noexcept;
	
		// Checks if a mouse button was pressed this frame.
		bool is_mouse_down(Mouse button) const noexcept;

		// Checks if a mouse button is being pressed.
		bool is_mouse__pressed(Mouse button) const noexcept;

		// Checks if a keyboard key was released this frame.
		bool is_key_up(Keyboard key) const noexcept;

		// Checks if a keyboard key was pressed this frame.
		bool is_key_down(Keyboard key) const noexcept;

		// Checks if a keyboard key is being pressed.
		bool is_key_pressed(Keyboard key) const noexcept;

		// Returns the current position of the mouse.
		SDL_Point get_mouse_position() const noexcept;

	private:
		friend class Window;
		
		// Input event processing state.
		static bool state;
		
		// Keyboard up states.
		static std::vector<bool> key_up;
		
		// Keyboard down states.
		static std::vector<bool> key_down;
		
		// Mouse up states.
		static std::vector<bool> mouse_up;
		
		// Mouse down states.
		static std::vector<bool> mouse_down;
	};

}