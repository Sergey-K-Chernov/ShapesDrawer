#include "DrawableRectangle.h"


DrawableRectangle::DrawableRectangle(const Ðosition& center, const Size& size) :
	Rectangle(center, size)
{
	pen = Pen_sp(new Gdiplus::Pen(Gdiplus::Color(255, 0, 255, 0), 1));
	brush = Brush_sp(new Gdiplus::SolidBrush(Gdiplus::Color(255, 0, 255, 0)));
}


void DrawableRectangle::draw(const std::unique_ptr<Gdiplus::Graphics>& graphics)
{
	Gdiplus::Rect rect(
		static_cast<INT>(getOrigin().x() - getSize().x() / 2),
		static_cast<INT>(getOrigin().y() - getSize().y() / 2),
		static_cast<INT>(getSize().x()),
		static_cast<INT>(getSize().y())
	);
	graphics->FillRectangle(brush.get(), rect);
	graphics->DrawRectangle(pen.get(), rect);
}


bool DrawableRectangle::check(const std::function<bool(const Ðosition& point)>& checker)
{
	return checker(getOrigin());
}


void DrawableRectangle::setPen(Pen_sp new_pen)
{
	pen = new_pen;
}


void DrawableRectangle::setBrush(Brush_sp new_brush)
{
	brush = new_brush;
}
