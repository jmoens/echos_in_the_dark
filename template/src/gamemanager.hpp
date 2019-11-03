#pragma once

#include "world.hpp"
#include "UI/menu.hpp"

#include <stack>

class GameManager
{
public:
	// Initialize the game
	bool init(vec2 size);

	// Update the game
	void update(float elapsed_ms);

	// Draw the game
	void draw();

	// Is the game over
	bool game_over();

	// Destroy all assets
	void destroy();

	// Handle input
	void on_key(GLFWwindow*, int key, int, int action, int mod);
	void on_mouse_move(GLFWwindow* window, double xpos, double ypos);
	void on_click(GLFWwindow* window, int button, int action, int mods);

private:
	// Load menus
	void load_main_menu();
	void load_pause_menu();

private:
	// Window information
	GLFWwindow* m_window;

	// Information about the state
	bool m_world_valid = true;
	bool m_in_menu = false;

	// Game states
	World m_world;
	Menu m_menu;

	// Should end game
	bool m_is_over = false;
};