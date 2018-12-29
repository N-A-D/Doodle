#include "../Doodle/doodle.h"
#include "../Doodle/display.h"
#include "../Doodle/system.h"

int main(int argc, char** argv) {
	doodle::init();
	doodle::Window window = doodle::create_window("Particle effect", 
		                                          { SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED }, 
		                                          { 800, 600 }, 
		                                          SDL_WINDOW_SHOWN
	                                             );
	doodle::Renderer renderer = doodle::create_renderer(window, SDL_RENDERER_ACCELERATED);
	doodle::InputHandler handler;
	while (window.poll_events()) {
		if (handler.is_key_down(doodle::Keyboard::KEY_ESCAPE))
			window.close();
		renderer.clear({ 255, 255, 255, 255 });
		renderer.display();
	}
	doodle::quit();
	return 0;
}