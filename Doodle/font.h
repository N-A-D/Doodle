#pragma once

#include <SDL2/SDL_ttf.h>
#include "sdl_resource.h"
#include "asset.h"

namespace doodle {

	class Font final 
		: public Asset<Font>
		, public internal::SDLResource<TTF_Font> 
	{
	public:

		Font(TTF_Font* font);

		// Returns the this font's style
		// The returned style is a bitmask composed of the following:
		// TTF_STYLE_BOLD
		// TTF_STYLE_ITALIC
		// TTF_STYLE_UNDERLINE
		// TTF_STYLE_STRIKETHROUGH
		// If a style was not set, then TTF_NORMAL_STYLE will be returned
		int font_style() const noexcept;

		// Sets this font's style
		// the style parameter is a bitmask composed of:
		// TTF_STYLE_BOLD
		// TTF_STYLE_ITALIC
		// TTF_STYLE_UNDERLINE
		// TTF_STYLE_STRIKETHROUGH
		void set_font_style(int style) noexcept;

		// Returns the current size of the font's outline
		int font_outline() const noexcept;

		// Sets the font's outline size
		// Passing in zero will remove outlines on the font
		void set_font_outline(int osize) noexcept;

		// Returns the maximum height of all glyphs using this font.
		// This may be used for rendering text such that they are close 
		// together vertically as possible. 
		int font_height() const noexcept;

	};

	TTF_Font* load_font(const std::string& filename, int size);

}