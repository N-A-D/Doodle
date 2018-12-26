#pragma once

#include <SDL.h>
#include <string>
#include "sdl_resource.h"

namespace doodle {

	class Font;
	class Renderer;

	// The Renderable class
	class Texture final : public internal::SDLResource<SDL_Texture> {
	public:

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

	private:

		friend Texture load_image(const Renderer& renderer, const std::string& filename);
		friend Texture load_solid_text(const Renderer& renderer, const Font& font, const std::string& text, const SDL_Color& text_color);
		friend Texture load_shaded_text(const Renderer& renderer, const Font& font, const std::string& text, const SDL_Color& text_color, const SDL_Color& bg_color);
		friend Texture load_blended_text(const Renderer& renderer, const Font& font, const std::string& text, const SDL_Color& text_color);

		Texture(SDL_Texture* texture);
	};

}