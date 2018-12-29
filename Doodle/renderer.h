#pragma once

#include <SDL2/SDL.h>
#include "texture.h"
#include "sdl_resource.h"

namespace doodle {

	class Window;

	// The Renderer class
	class Renderer final : public internal::SDLResource<SDL_Renderer> {
	public:
		
		Renderer(const std::pair<SDL_Renderer*, std::uint32_t>& renderer_data) noexcept;

		// Set the renderer's rendering area.
		void set_viewport(const SDL_Rect& rect) noexcept;

		// Set the renderer's drawing color.
		void set_draw_color(const SDL_Color& color) noexcept;

		// Get the renderer's drawing color.
		SDL_Color draw_color() const noexcept;

		// Draw a renderable object onto the renderer's parent window.
		void draw(const Texture& obj, const SDL_Point& dst, double angle,
			const SDL_Rect& clip, const SDL_Point& center, SDL_RendererFlip flip) noexcept;

		// Draw a renderable object onto the renderer's parent window.
		void draw(const Texture& obj, const SDL_Rect& src, const SDL_Rect& dst) noexcept;

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

		bool operator==(const Renderer& other) const noexcept;
		bool operator!=(const Renderer& other) const noexcept;

		// Clear the current rendering target with the given color.
		void clear(const SDL_Color& color = { 0, 0, 0, 0 }) const noexcept;
		
		// Update the current rendering target with the rendering that was done.
		void display() const noexcept;

	private:
		// Parent window's id
		std::uint32_t parent_window;
	};

	// Loads a new SDL_Renderer resource from a doodle::Window.
	std::pair<SDL_Renderer*, std::uint32_t> create_renderer(Window& window, std::uint32_t flags);

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