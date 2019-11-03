// internal
#include "common.hpp"
#include "gamemanager.hpp"

#define GL3W_IMPLEMENTATION
#include <gl3w.h>

// stlib
#include <chrono>
#include <iostream>

using Clock = std::chrono::high_resolution_clock;

// Global 
GameManager gm;
const int width = 1200;
const int height = 800;

// Entry point
int main(int argc, char* argv[])
{
	// Initializing world (after renderer.init().. sorry)
	if (!gm.init({ (float)width, (float)height }))
	{
		// Time to read the error message
		std::cout << "Press any key to exit" << std::endl;
		std::cin.get();
		return EXIT_FAILURE;
	}

	auto t = Clock::now();

	// variable timestep loop.. can be improved (:
	while (!gm.game_over())
	{
		// Processes system messages, if this wasn't present the window would become unresponsive
		glfwPollEvents();

		// Calculating elapsed times in milliseconds from the previous iteration
		auto now = Clock::now();
		float elapsed_sec = (float)(std::chrono::duration_cast<std::chrono::microseconds>(now - t)).count() / 1000;
		t = now;

		for (float b = 100.f; elapsed_sec > b; elapsed_sec -= b)
			gm.update(b);
		if (elapsed_sec > 0)
			gm.update(elapsed_sec);
		gm.draw();
	}

	gm.destroy();

	return EXIT_SUCCESS;
}