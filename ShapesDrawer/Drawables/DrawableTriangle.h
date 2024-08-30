#pragma once
#include "Shapes.h"
#include "DrawableInterface.h"


class DrawableTriangle : public Triangle, public virtual IDrawable
{
public:
	DrawableTriangle(const �osition& vertex1, const �osition& vertex2, const �osition& vertex3);
	virtual ~DrawableTriangle() {}

	virtual void draw(const std::unique_ptr<Gdiplus::Graphics>& graphics);
	virtual bool check(const std::function<bool(const �osition& point)>& checker);

	virtual void setPen(Pen_sp new_pen);
	virtual void setBrush(Brush_sp new_brush);

private:
	Pen_sp pen;
	Brush_sp brush;
};
