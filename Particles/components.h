#pragma once

#include <SDL2/SDL.h>
#include "../Doodle/math.h"
#include <Rift/component.h>

struct Body : public rift::Component<Body>
{
	Body() = default;
	Body(int width, int height, doodle::Vector2f pos, doodle::Vector2f dir)
		: w(width), h(height), pos(pos), dir(dir) {}
	int w = 0, h = 0;
	doodle::Vector2f pos;
	doodle::Vector2f dir;
};

struct Render : public rift::Component<Render>
{
	Render() { rect_color = { 0, 0, 0, 0 }; }
	Render(SDL_Color color) : rect_color(color) {}
	SDL_Color rect_color;
};