#pragma once
#include "Shapes.h"
#include "DrawableInterface.h"


class DrawableEllipse : public Ellipse, public virtual IDrawable
{
public:
	DrawableEllipse(const Ðosition& center, const Size& size);
	virtual ~DrawableEllipse() {}

	virtual void draw(const std::unique_ptr<Gdiplus::Graphics>& graphics);
	virtual bool check(const std::function<bool(const Ðosition& point)>& checker);

	virtual void setPen(Pen_sp new_pen);
	virtual void setBrush(Brush_sp new_brush);

private:
	Pen_sp pen;
	Brush_sp brush;
};
