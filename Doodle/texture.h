#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "sdl_resource.h"
#include "asset.h"

namespace doodle {

	class Font;
	class Renderer;

	class Texture final 
		: public Asset<Texture>
		, public internal::SDLResource<SDL_Texture> 
	{
	public:
		Texture(SDL_Texture* texture) noexcept;

		// Returns the alpha modulation of the texture.
		std::uint8_t alpha_mod() const noexcept;

		// Sets the alpha modulation for the texture.
		void set_alpha_mod(std::uint8_t alpha) noexcept;

		// Returns the blending mode for the texture.
		SDL_BlendMode blend_mode() const noexcept;

		// Sets the blending mode for the texture.
		void set_blend_mode(SDL_BlendMode blend_mode) noexcept;

		// Returns the color modulation for the texture.
		SDL_Color color_mod() const noexcept;

		// Sets the color modulation for the texture.
		void set_color_mod(const SDL_Color& color) noexcept;

		// Returns the width of the texture.
		int width() const noexcept;

		// Returns the height of the texture.
		int height() const noexcept;

	};

	SDL_Texture* load_image(const Renderer& renderer, const std::string& filename);
	SDL_Texture* load_solid_text(const Renderer& renderer, const Font& font, const std::string& text, const SDL_Color& text_color);
	SDL_Texture* load_shaded_text(const Renderer& renderer, const Font& font, const std::string& text, const SDL_Color& text_color, const SDL_Color& bg_color);
	SDL_Texture* load_blended_text(const Renderer& renderer, const Font& font, const std::string& text, const SDL_Color& text_color);

}