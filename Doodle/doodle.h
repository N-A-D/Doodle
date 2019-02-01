#pragma once

#include "asset/asset.h"
#include "audio/music.h"
#include "audio/sound.h"
#include "display/window.h"
#include "display/renderer.h"
#include "graphics/texture.h"
#include "graphics/font.h"
#include "system/clock.h"
#include "system/fps.h"
#include "system/input.h"
#include "system/keyboard.h"
#include "system/mouse.h"

namespace doodle {

	// Initializes Doodle.
	void init();

	// Shuts down Doodle.
	void quit();

}