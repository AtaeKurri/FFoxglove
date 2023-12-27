#pragma once
#include <glm/vec2.hpp>

bool gameInit();
bool gameUpdate(float dt);
void gameClose();

namespace platform {
	bool isFullscreen();
	void setFullscreen(bool fullscreen);
}