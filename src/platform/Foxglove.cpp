#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <ctime>
#include <fstream>
#include <chrono>
#include "gameFrame/gameFrame.hpp"

#ifdef _WIN32
#include <Windows.h>
#endif

GLFWwindow* window = 0;

int main()
{
#ifdef _WIN32
#ifdef _MSC_VER 
#if PRODUCTION_BUILD == 0
	AllocConsole();
	(void)freopen("conin$", "r", stdin);
	(void)freopen("conout$", "w", stdout);
	(void)freopen("conout$", "w", stderr);
	std::cout.sync_with_stdio();
#endif
#endif
#endif

#pragma region Window & OpenGL
	if (!glfwInit())
		return 0; // Can't init GLFW
	glfwWindowHint(GLFW_SAMPLES, 4);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
#endif

	int width = 1600;
	int height = 900;
	window = glfwCreateWindow(width, height, "Game", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
#pragma endregion

	if (!gameInit())
		return 0;

	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	gameClose();
	return 0;
}

namespace platform {
	bool isFullscreen() {
		return false;
	}
}
