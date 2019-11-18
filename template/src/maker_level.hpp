#pragma once

#include "common.hpp"
#include "brick.hpp"
#include "Robot/robot.hpp"
#include "ghost.hpp"
#include "level_graph.hpp"
#include "Interactables/door.hpp"
#include "light.hpp"
#include "sign.hpp"
#include "json.hpp"
#include "systems.hpp"
#include "background.hpp"
#include "torch.hpp"

#include <vector>

enum class ObjectType { del, brick, torch, door, ghost };

class MakerLevel
{
public:
	// Renders level
	// projection is the 2D orthographic projection matrix
	void draw_entities(const mat3& projection, const vec2& camera_shift);

	// Releases all level-associated resources
	void destroy();

	// Generate a large basic level
	void generate_starter();

	// Load previously made level
	void load_level();

	// Handle input
	std::string handle_key_press(int key, int action);
	void handle_mouse_click(double xpos, double ypos, vec2 camera);

	// Generate JSON and shadow image for current level
	void process();

private:
	// Spawn entities
	bool spawn_robot(vec2 position);
	bool spawn_brick(vec2 position, vec3 colour);
	bool spawn_door(vec2 position, std::string next_level);
	bool spawn_ghost(vec2 position, vec3 colour);
	bool spawn_torch(vec2 position);
	bool delete_object(vec2 position);

	std::string m_level;
	float width = 64.f * 40.f, height = 64.f * 40.f;

	ObjectType m_ot = ObjectType::del;
	int m_ot_selection = 0;
	vec3 m_color = { 1.f, 1.f, 1.f };

	// Systems
	int min;
	RenderingSystem m_rendering_system;

	// Level entities
	bool permanent[40][40];
	Entity* slots[40][40];

	Robot m_robot;
	std::vector<Brick*> m_bricks;
	std::vector<Ghost*> m_ghosts;
	std::vector<Door*> m_interactables;
	std::vector<Torch*> m_torches;
};
