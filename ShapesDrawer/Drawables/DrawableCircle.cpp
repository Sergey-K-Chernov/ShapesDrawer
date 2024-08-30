#include "DrawableCircle.h"



DrawableCircle::DrawableCircle(const Ðosition& center, const double radius) :
	Circle(center, radius)
{
	pen = Pen_sp(new Gdiplus::Pen(Gdiplus::Color(255, 0, 255, 0), 1));
}


void DrawableCircle::draw(const std::unique_ptr<Gdiplus::Graphics>& graphics)
{
	Gdiplus::Rect rect(
		static_cast<INT>(getOrigin().x() - getRadius()),
		static_cast<INT>(getOrigin().y() - getRadius()),
		static_cast<INT>(getRadius() * 2),
		static_cast<INT>(getRadius() * 2)
	);
	graphics->DrawEllipse(pen.get(), rect);
}


bool DrawableCircle::check(const std::function<bool(const Ðosition& point)>& checker)
{
	return checker(getOrigin());
}


void DrawableCircle::setPen(Pen_sp new_pen)
{
	pen = new_pen;
}
