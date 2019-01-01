#include "../Doodle/doodle.h"
#include "../Doodle/display.h"
#include "../Doodle/system.h"
#include "../Doodle/graphics.h"
#include "../Doodle/system/fps.h"
#include "systems.h"
#include "components.h"
#include <random>
#include <sstream>

const int NUM_PARTICLES = 200;

void create_particles(rift::EntityManager& entities, int num_entities) noexcept;

int main(int argc, char** argv) {
	doodle::init();
	doodle::Window window = doodle::create_window("", 
		                                          { SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED }, 
		                                          { SCR_WIDTH, SCR_HEIGHT },
		                                          SDL_WINDOW_SHOWN
	                                             );
	doodle::Renderer renderer = doodle::create_renderer(window, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	doodle::InputHandler handler;
	doodle::Clock clock;
	doodle::FrameCounter fc(100'000);
	std::stringstream time_text;

	rift::EntityManager entities;
	rift::SystemManager systems(entities);
	systems.add<MovementSystem>();
	systems.add<RenderingSystem>(renderer);

	create_particles(entities, NUM_PARTICLES);

	while (window.poll_events()) {
		if (handler.is_key_pressed(doodle::Keyboard::KEY_ESCAPE))
			window.close();
		time_text.str("");
		time_text << fc.avg_frame_rate() << " FPS";
		window.set_title(time_text.str());
		renderer.clear({ 0, 0, 0, 0 });
		systems.update<MovementSystem, RenderingSystem>(clock.delta_time() / 1000.0);
		renderer.display();
	}
	doodle::quit();
	return 0;
}

void  create_particles(rift::EntityManager & entities, int num_entities) noexcept
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> angle_dis(0.f, 360.f);
	std::uniform_real_distribution<float> speed_dis(100.f, 300.f);

	for (int i = 0; i < num_entities; i++)
	{
		auto e = entities.create_entity();
		e.add<Body>(5, 5, doodle::Vector2f(400, 300), 
			doodle::rotate(doodle::Vector2f(speed_dis(gen), 0), angle_dis(gen)));
		SDL_Color color = { 255, 255, 255, 255 };
		e.add<Render>(color);
	}
}
