#include "ExampleScreen.h"



ExampleScreen::ExampleScreen() 
{
	drawables.push_back(IDrawable_p(new DrawableRectangle(�osition(100, 100), Size(150, 50))));
	drawables.back()->setPen(Pen_sp(new Gdiplus::Pen(Gdiplus::Color(255, 255, 0, 0), 3)));

	drawables.push_back(IDrawable_p(new DrawableEllipse(�osition(200, 200), Size(150, 50))));
	drawables.back()->setPen(Pen_sp(new Gdiplus::Pen(Gdiplus::Color(255, 0, 0, 255), 3)));

	drawables.push_back(IDrawable_p(new DrawableFrame(�osition(100, 170), Size(120, 40))));
	drawables.back()->setPen(Pen_sp(new Gdiplus::Pen(Gdiplus::Color(255, 0, 0, 0), 2)));

	drawables.push_back(IDrawable_p(new DrawableCircle(�osition(200, 100), 92)));
	drawables.back()->setPen(Pen_sp(new Gdiplus::Pen(Gdiplus::Color(255, 0, 200, 200), 4)));

	drawables.push_back(IDrawable_p(new DrawableTriangle(�osition(300,100), �osition(280,120), �osition(330,140))));
	drawables.back()->setPen(Pen_sp(new Gdiplus::Pen(Gdiplus::Color(255, 255, 200, 0), 4)));

	drawables.push_back(IDrawable_p(new DrawableCircle(�osition(300, 400), 220)));
	drawables.back()->setPen(Pen_sp(new Gdiplus::Pen(Gdiplus::Color(255, 0, 200, 200), 4)));


	limiters.push_back(Shape_p(new Circle(�osition(100,100), 150)));
	limiters.push_back(Shape_p(new Triangle(�osition(310, 110), �osition(280, 125), �osition(325, 135))));
	
}


void ExampleScreen::draw(const std::unique_ptr<Gdiplus::Graphics>& graphics)
{
	auto checker = [this](const �osition& point) {
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
