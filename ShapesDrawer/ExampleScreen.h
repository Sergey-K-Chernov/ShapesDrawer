#pragma once
#include "Drawables/Drawables.h"
#include <vector>

class ExampleScreen
{
public:
	ExampleScreen();
	~ExampleScreen() {}

	void draw(const std::unique_ptr<Gdiplus::Graphics>& graphics);

private:
	std::vector<IDrawable_p> drawables;
	std::vector<Shape_p> limiters;
};
