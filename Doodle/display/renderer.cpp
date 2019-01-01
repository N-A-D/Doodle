#include "renderer.h"
#include "window.h"
#include <stdexcept>
#include <string>

doodle::Renderer::Renderer(const std::pair<SDL_Renderer *, std::uint32_t>& renderer_data) noexcept
	: SDLResource(renderer_data.first, [](SDL_Renderer* renderer) { SDL_DestroyRenderer(renderer); })
	, parent_window(renderer_data.second)
{
}

void doodle::Renderer::set_viewport(const SDL_Rect & rect) noexcept
{
	SDL_RenderSetViewport(*this, &rect);
}

void doodle::Renderer::set_draw_color(const SDL_Color & color) noexcept
{
	SDL_SetRenderDrawColor(*this, color.r, color.g, color.b, color.a);
}

SDL_Color doodle::Renderer::draw_color() const noexcept
{
	SDL_Color color;
	SDL_GetRenderDrawColor(*this, &color.r, &color.g, &color.b, &color.a);
	return color;
}

void doodle::Renderer::draw(const Texture & obj, const SDL_Point& dst, double angle, const SDL_Rect& clip, const SDL_Point& center, SDL_RendererFlip flip) noexcept
{
	SDL_Rect quad = { dst.x, dst.y, clip.w, clip.h };
	SDL_RenderCopyEx(*this, obj, &clip, &quad, angle, &center, flip);
}

void doodle::Renderer::draw(const Texture & obj, const SDL_Rect & src, const SDL_Rect & dst) noexcept
{
	SDL_RenderCopy(*this, obj, &src, &dst);
}

void doodle::Renderer::draw_point(const SDL_Point & point) const noexcept
{
	SDL_RenderDrawPoint(*this, point.x, point.y);
}

void doodle::Renderer::draw_line(const std::pair<SDL_Point, SDL_Point>& line) const noexcept
{
	SDL_RenderDrawLine(*this, line.first.x, line.first.y, line.second.x, line.second.y);
}

void doodle::Renderer::draw_rect(const SDL_Rect & rect) const noexcept
{
	SDL_RenderDrawRect(*this, &rect);
}

void doodle::Renderer::draw_filled_rect(const SDL_Rect & filled_rect) const noexcept
{
	SDL_RenderFillRect(*this, &filled_rect);
}

bool doodle::Renderer::operator==(const Renderer & other) const noexcept
{
	return parent_window == other.parent_window;
}

bool doodle::Renderer::operator!=(const Renderer & other) const noexcept
{
	return !(*this == other);
}

void doodle::Renderer::clear(const SDL_Color & color) const noexcept
{
	SDL_SetRenderDrawColor(*this, color.r, color.g, color.b, color.a);
	SDL_RenderClear(*this);
}

void doodle::Renderer::display() const noexcept
{
	SDL_RenderPresent(*this);
}

std::pair<SDL_Renderer*, std::uint32_t> doodle::create_renderer(Window & window, std::uint32_t flags)
{
	auto sdl_renderer = SDL_CreateRenderer(window, -1, flags);
	if (!sdl_renderer)
		throw std::runtime_error("Failed to create SDL_Renderer " + std::string(SDL_GetError()));
	return std::make_pair(sdl_renderer, window.id());
}
