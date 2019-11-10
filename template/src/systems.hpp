#pragma once

#include <vector>
#include "components.hpp"

class RenderingSystem
{
private:
	std::vector<int> level_entities;
	std::vector<int> menu_entities;

public:
    void render_ui(const mat3& projection, const vec2& camera_shift);
    void render(const mat3& projection, const vec2& camera_shift, vec3 headlight_channel);
	void process(int min, int max);
	void destroy();
	void clear();
};
