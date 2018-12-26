#pragma once

#include <SDL.h>
#include <string>
#include <memory>
#include "clock.h"
#include "renderable.h"
#include "sdl_resource.h"

namespace doodle {

	class Window;

	// The Renderer class
	class Renderer final : public internal::SDLResource<SDL_Renderer> {
	public:

		// Draw a renderable object onto the renderer's parent window
		void draw(const Renderable& obj, SDL_Point dst, double angle, 
			      SDL_Rect clip, SDL_Point center, SDL_RendererFlip flip) noexcept;

		// Set the renderer's rendering area.
		void set_viewport(const SDL_Rect& rect) noexcept;

		// Set the renderer's drawing color.
		void set_draw_color(const SDL_Color& color) noexcept;

		// Get the renderer's drawing color.
		SDL_Color draw_color() const noexcept;

		// Draws a point onto this renderer's parent window.
		void draw_point(const SDL_Point& point) const noexcept;

		// Draws a series of points onto this renderer's parent window.
		template <class Container> 
		void draw_points(const Container& points) const noexcept;

		// Draws a line onto the renderer's parent window.
		void draw_line(const std::pair<SDL_Point, SDL_Point>& line) const noexcept;

		// Draws multiple lines onto the renderer's parent window.
		template <class Container>
		void draw_lines(const Container& lines) const noexcept;

		// Draws a rectangle outline onto the renderer's parent window.
		void draw_rect(const SDL_Rect& rect) const noexcept;

		// Draws multiple rectangle outlines onto the renderer's parent window.
		template <class Container>
		void draw_rects(const Container& rects) const noexcept;

		// Draws a filled rectangle onto the renderer's parent window.
		void draw_filled_rect(const SDL_Rect& filled_rect) const noexcept;

		// Draws multiple filled rectangles onto the renderer's parent window.
		template <class Container>
		void draw_filled_rects(const Container& filled_rects) const noexcept;

		bool operator==(const Renderer& other) const noexcept
		{
			return parent_window_id == other.parent_window_id;
		}
		bool operator!=(const Renderer& other) const noexcept
		{
			return *this == other;
		}

	private:
		friend class Window;
		Renderer(SDL_Renderer* renderer);
		std::uint32_t parent_window_id;
	};

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

	template<class Container>
	inline void Renderer::draw_points(const Container & points) const noexcept
	{
		for (auto point : points)
			draw_point(point);
	}

	template<class Container>
	inline void Renderer::draw_lines(const Container & lines) const noexcept
	{
		for (auto line : lines)
			draw_line(line);
	}

	template<class Container>
	inline void Renderer::draw_rects(const Container & rects) const noexcept
	{
		for (auto rect : rects)
			draw_rect(rect);
	}

	template<class Container>
	inline void Renderer::draw_filled_rects(const Container & filled_rects) const noexcept
	{
		for (auto filled_rect : filled_rects)
			draw_filled_rect(filled_rect);
	}

}