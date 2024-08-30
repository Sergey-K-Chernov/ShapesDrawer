#include "DrawableEllipse.h"


DrawableEllipse::DrawableEllipse(const Ðosition& center, const Size& size) :
	Ellipse(center, size)
{
	pen = Pen_sp(new Gdiplus::Pen(Gdiplus::Color(255, 0, 255, 0), 1));
	brush = Brush_sp(new Gdiplus::SolidBrush(Gdiplus::Color(255, 0, 255, 0)));
}


void DrawableEllipse::draw(const std::unique_ptr<Gdiplus::Graphics>& graphics)
{
	Gdiplus::Rect rect(
		static_cast<INT>(getOrigin().x() - getSize().x() / 2),
		static_cast<INT>(getOrigin().y() - getSize().y() / 2),
		static_cast<INT>(getSize().x()),
		static_cast<INT>(getSize().y())
	);
	graphics->FillEllipse(brush.get(), rect);
	graphics->DrawEllipse(pen.get(), rect);
}


bool DrawableEllipse::check(const std::function<bool(const Ðosition& point)>& checker)
{
	return checker(getOrigin());
}


void DrawableEllipse::setPen(Pen_sp new_pen)
{
	pen = new_pen;
}


void DrawableEllipse::setBrush(Brush_sp new_brush)
{
	brush = new_brush;
}
