#pragma once

#include <string>
#include <SDL2/SDL.h>
#include "../asset/asset.h"
#include "../internal/sdl_resource.h"

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

	// Loads a new SDL_Texture resource from an image file.
	SDL_Texture* load_image(const Renderer& renderer, const std::string& filename);

	// Loads a new SDL_Texture resource from solid rendered text.
	SDL_Texture* load_solid_text(const Renderer& renderer, const Font& font, const std::string& text, const SDL_Color& text_color);
	
	// Loads a new SDL_Texture resource from shaded rendered text.
	SDL_Texture* load_shaded_text(const Renderer& renderer, const Font& font, const std::string& text, const SDL_Color& text_color, const SDL_Color& bg_color);
	
	// Loads a new SDL_Texture resource from blended rendered text.	
	SDL_Texture* load_blended_text(const Renderer& renderer, const Font& font, const std::string& text, const SDL_Color& text_color);

}