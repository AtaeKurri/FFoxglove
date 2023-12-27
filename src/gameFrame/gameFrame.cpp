#define GLM_ENABLE_EXPERIMENTAL
#include "gameFrame/gameFrame.hpp"
#include <glad/glad.h>
#include <glm/glm.hpp>

struct GameData {
	glm::vec2 rectPos = { 853, 480 };
} gameData;

bool gameInit() {
	return true;
}

bool gameUpdate() {

	return true;
}

void gameClose() {
	// Save the game data here.
}