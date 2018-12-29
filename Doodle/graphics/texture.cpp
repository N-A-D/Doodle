#include <string>
#include "font.h"
#include "texture.h"
#include <stdexcept>
#include <SDL2/SDL_image.h>
#include "../display/renderer.h"

doodle::Texture::Texture(SDL_Texture * texture) noexcept
	: SDLResource(texture, [](SDL_Texture* texture) { SDL_DestroyTexture(texture); })
{
}

std::uint8_t doodle::Texture::alpha_mod() const noexcept
{
	std::uint8_t alpha;
	SDL_GetTextureAlphaMod(*this, &alpha);
	return alpha;
}

void doodle::Texture::set_alpha_mod(std::uint8_t alpha) noexcept
{
	SDL_SetTextureAlphaMod(*this, alpha);
}

SDL_BlendMode doodle::Texture::blend_mode() const noexcept
{
	SDL_BlendMode mode;
	SDL_GetTextureBlendMode(*this, &mode);
	return mode;
}

void doodle::Texture::set_blend_mode(SDL_BlendMode blend_mode) noexcept
{
	SDL_SetTextureBlendMode(*this, blend_mode);
}

SDL_Color doodle::Texture::color_mod() const noexcept
{
	SDL_Color color;
	SDL_GetTextureColorMod(*this, &color.r, &color.g, &color.b);
	return color;
}

void doodle::Texture::set_color_mod(const SDL_Color & color) noexcept
{
	SDL_SetTextureColorMod(*this, color.r, color.g, color.b);
}

int doodle::Texture::width() const noexcept
{
	int w;
	SDL_QueryTexture(*this, nullptr, nullptr, &w, nullptr);
	return w;
}

int doodle::Texture::height() const noexcept
{
	int h;
	SDL_QueryTexture(*this, nullptr, nullptr, nullptr, &h);
	return h;
}

SDL_Texture * doodle::load_image(const Renderer & renderer, const std::string & filename)
{
	auto surf = IMG_Load(filename.c_str());
	if (!surf)
		throw std::runtime_error("Could not create doodle::Texture " + std::string(SDL_GetError()));
	auto texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (!texture)
		throw std::runtime_error("Could not create doodle::Texture " + std::string(SDL_GetError()));
	return texture;
}

SDL_Texture * doodle::load_solid_text(const Renderer & renderer, const Font & font, const std::string & text, const SDL_Color & text_color)
{
	auto surf = TTF_RenderText_Solid(font, text.c_str(), text_color);
	if (!surf)
		throw std::runtime_error("Could not create doodle::Texture " + std::string(SDL_GetError()));
	auto texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (!texture)
		throw std::runtime_error("Could not create doodle::Texture " + std::string(SDL_GetError()));
	return texture;
}

SDL_Texture * doodle::load_shaded_text(const Renderer & renderer, const Font & font, const std::string & text, const SDL_Color & text_color, const SDL_Color & bg_color)
{
	auto surf = TTF_RenderText_Shaded(font, text.c_str(), text_color, bg_color);
	if (!surf)
		throw std::runtime_error("Could not create doodle::Texture " + std::string(SDL_GetError()));
	auto texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (!texture)
		throw std::runtime_error("Could not create doodle::Texture " + std::string(SDL_GetError()));
	return texture;
}

SDL_Texture * doodle::load_blended_text(const Renderer & renderer, const Font & font, const std::string & text, const SDL_Color & text_color)
{
	auto surf = TTF_RenderText_Blended(font, text.c_str(), text_color);
	if (!surf)
		throw std::runtime_error("Could not create doodle::Texture " + std::string(SDL_GetError()));
	auto texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (!texture)
		throw std::runtime_error("Could not create doodle::Texture " + std::string(SDL_GetError()));
	return texture;
}
