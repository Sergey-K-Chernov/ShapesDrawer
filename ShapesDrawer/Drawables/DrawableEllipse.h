#pragma once
#include "Shapes.h"
#include "DrawableInterface.h"


class DrawableEllipse : public Ellipse, public virtual IDrawable
{
public:
	DrawableEllipse(const Ðosition& center, const Size& size);
	~DrawableEllipse() {}

	void draw(const std::unique_ptr<Gdiplus::Graphics>& graphics) override;
	bool check(const std::function<bool(const Ðosition& point)>& checker) override;

	void setPen(Pen_sp new_pen) override;
	void setBrush(Brush_sp new_brush) override;

private:
	Pen_sp pen;
	Brush_sp brush;
};
