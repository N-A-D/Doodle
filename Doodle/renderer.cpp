#include "renderer.h"

std::uint8_t doodle::Renderable::alpha_mod() const noexcept
{
	std::uint8_t ret;
	SDL_GetTextureAlphaMod(resource.get(), &ret);
	return ret;
}

void doodle::Renderable::set_alpha_mod(std::uint8_t alpha) noexcept
{
	SDL_SetTextureAlphaMod(resource.get(), alpha);
}

SDL_BlendMode doodle::Renderable::blend_mode() const noexcept
{
	SDL_BlendMode mode;
	SDL_GetTextureBlendMode(resource.get(), &mode);
	return mode;
}

void doodle::Renderable::set_blend_mode(SDL_BlendMode blend_mode) noexcept
{
	SDL_SetTextureBlendMode(resource.get(), blend_mode);
}

SDL_Color doodle::Renderable::color_mod() const noexcept
{
	SDL_Color color = { 0, 0, 0, 0 };
	SDL_GetTextureColorMod(resource.get(), &color.r, &color.g, &color.b);
	return color;
}

void doodle::Renderable::set_color_mod(const SDL_Color & color) noexcept
{
	SDL_SetTextureColorMod(resource.get(), color.r, color.g, color.b);
}

int doodle::Renderable::width() const noexcept
{
	int w;
	SDL_QueryTexture(resource.get(), nullptr, nullptr, &w, nullptr);
	return w;
}

int doodle::Renderable::height() const noexcept
{
	int h;
	SDL_QueryTexture(resource.get(), nullptr, nullptr, nullptr, &h);
	return h;
}

void doodle::Renderer::draw(const Renderable & obj, SDL_Point dst, double angle, SDL_Rect clip, SDL_Point center, SDL_RendererFlip flip) noexcept
{
	SDL_Rect quad = { dst.x, dst.y, clip.w, clip.h };
	SDL_RenderCopyEx(resource.get(), obj, &clip, &quad, angle, &center, flip);
}

void doodle::Renderer::set_viewport(const SDL_Rect & rect) noexcept
{
	SDL_RenderSetViewport(resource.get(), &rect);
}

void doodle::Renderer::set_draw_color(const SDL_Color & color) noexcept
{
	SDL_SetRenderDrawColor(resource.get(), color.r, color.g, color.b, color.a);
}

SDL_Color doodle::Renderer::draw_color() const noexcept
{
	SDL_Color color;
	SDL_GetRenderDrawColor(resource.get(), &color.r, &color.g, &color.b, &color.a);
	return color;
}

void doodle::Renderer::draw_point(const SDL_Point & point) const noexcept
{
	SDL_RenderDrawPoint(resource.get(), point.x, point.y);
}

void doodle::Renderer::draw_line(const std::pair<SDL_Point, SDL_Point>& line) const noexcept
{
	SDL_RenderDrawLine(resource.get(), line.first.x, line.first.y, line.second.x, line.second.y);
}

void doodle::Renderer::draw_rect(const SDL_Rect & rect) const noexcept
{
	SDL_RenderDrawRect(resource.get(), &rect);
}

void doodle::Renderer::draw_filled_rect(const SDL_Rect & filled_rect) const noexcept
{
	SDL_RenderFillRect(resource.get(), &filled_rect);
}