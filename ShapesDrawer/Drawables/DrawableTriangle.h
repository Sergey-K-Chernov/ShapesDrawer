#pragma once
#include "Shapes.h"
#include "DrawableInterface.h"


class DrawableTriangle : public Triangle, public virtual IDrawable
{
public:
	DrawableTriangle(const Ðosition& vertex1, const Ðosition& vertex2, const Ðosition& vertex3);
	~DrawableTriangle() {}

	void draw(const std::unique_ptr<Gdiplus::Graphics>& graphics) override;
	bool check(const std::function<bool(const Ðosition& point)>& checker) override;

	void setPen(Pen_sp new_pen) override;
	void setBrush(Brush_sp new_brush) override;

private:
	Pen_sp pen;
	Brush_sp brush;
};
