#include "font.h"
#include <string>
#include <stdexcept>

int doodle::Font::font_style() const noexcept
{
	return TTF_GetFontStyle(*this);
}

void doodle::Font::set_font_style(int style) noexcept
{
	TTF_SetFontStyle(*this, style);
}

int doodle::Font::font_outline() const noexcept
{
	return TTF_GetFontOutline(*this);
}

void doodle::Font::set_font_outline(int size) noexcept
{
	TTF_SetFontStyle(*this, size);
}

int doodle::Font::font_height() const noexcept
{
	return TTF_FontHeight(*this);
}

doodle::Font::Font(TTF_Font * font)
	: SDLResource(font, [](TTF_Font* font) { TTF_CloseFont(font); })
{
}

doodle::Font doodle::load_font(const std::string & filename, int size)
{
	auto ttf_font = TTF_OpenFont(filename.c_str(), size);
	if (!ttf_font)
		throw std::runtime_error("Could not create doodle::Font " + std::string(TTF_GetError()));
	return Font(ttf_font);
}
