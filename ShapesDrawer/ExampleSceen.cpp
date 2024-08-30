#include "ExampleScreen.h"



ExampleScreen::ExampleScreen() 
{
	drawables.push_back(IDrawable_p(new DrawableRectangle(Ðosition(100, 100), Size(150, 50))));
	drawables.back()->setPen(Pen_sp(new Gdiplus::Pen(Gdiplus::Color(255, 255, 0, 0), 3)));

	drawables.push_back(IDrawable_p(new DrawableEllipse(Ðosition(200, 200), Size(150, 50))));
	drawables.back()->setPen(Pen_sp(new Gdiplus::Pen(Gdiplus::Color(255, 0, 0, 255), 3)));

	drawables.push_back(IDrawable_p(new DrawableFrame(Ðosition(100, 170), Size(120, 40))));
	drawables.back()->setPen(Pen_sp(new Gdiplus::Pen(Gdiplus::Color(255, 0, 0, 0), 2)));

	drawables.push_back(IDrawable_p(new DrawableCircle(Ðosition(200, 100), 92)));
	drawables.back()->setPen(Pen_sp(new Gdiplus::Pen(Gdiplus::Color(255, 0, 200, 200), 4)));

	drawables.push_back(IDrawable_p(new DrawableTriangle(Ðosition(300,100), Ðosition(280,120), Ðosition(330,140))));
	drawables.back()->setPen(Pen_sp(new Gdiplus::Pen(Gdiplus::Color(255, 255, 200, 0), 4)));

	drawables.push_back(IDrawable_p(new DrawableCircle(Ðosition(300, 400), 220)));
	drawables.back()->setPen(Pen_sp(new Gdiplus::Pen(Gdiplus::Color(255, 0, 200, 200), 4)));


	limiters.push_back(Shape_p(new Circle(Ðosition(100,100), 150)));
	limiters.push_back(Shape_p(new Triangle(Ðosition(310, 110), Ðosition(280, 125), Ðosition(325, 135))));
	
}


void ExampleScreen::draw(const std::unique_ptr<Gdiplus::Graphics>& graphics)
{
	auto checker = [this](const Ðosition& point) {
			for (auto& limiter : limiters)
			{
				if (limiter->isInside(point))
					return true;
			}
			return false;
		};
		
	for (auto& drawable : drawables)
	{
		if (drawable->check(checker))
		{
			drawable->draw(graphics);
		}
	}
}
