#pragma once
#define RIFT_ENABLE_PARALLEL_TRANSFORMATIONS
#include <Rift/entity.h>
#include <Rift/system.h>
#include "components.h"
#include "../Doodle/display.h"

constexpr int SCR_WIDTH = 800;
constexpr int SCR_HEIGHT = 600;

struct MovementSystem : public rift::System<MovementSystem> {
	void update(rift::EntityManager& entities, double dt) override {
		entities.par_for_entities_with<Body>([dt](/*rift::Entity e,*/ Body& body) {
			body.pos += body.dir * static_cast<float>(dt);
			if (body.pos.x < 0) {
				body.pos.x = 0;
				body.dir.x *= -1;
			}
			else if (body.pos.x > SCR_WIDTH - body.w) {
				body.pos.x = static_cast<float>(SCR_WIDTH - body.w);
				body.dir.x *= -1;
			}
			if (body.pos.y < 0) {
				body.pos.y = 0;
				body.dir.y *= -1;
			}
			if (body.pos.y > SCR_HEIGHT - body.h) {
				body.pos.y = static_cast<float>(SCR_HEIGHT - body.h);
				body.dir.y *= -1;
			}
		});
	}
};

class RenderingSystem : public rift::System<RenderingSystem> {
public:
	RenderingSystem(doodle::Renderer renderer)
		: renderer(renderer) {}
	void update(rift::EntityManager& entities, double dt) override {
		entities.for_entities_with<Render, Body>([this](rift::Entity entity, Render& render, Body& body) {
			renderer.set_draw_color(render.rect_color);
			SDL_Rect rect = { 
				static_cast<int>(body.pos.x) - body.w / 2, 
				static_cast<int>(body.pos.y) - body.h / 2, 
				body.w,
				body.h
			};
			renderer.draw_filled_rect(rect);
		});
	}
private:
	doodle::Renderer renderer;
};
