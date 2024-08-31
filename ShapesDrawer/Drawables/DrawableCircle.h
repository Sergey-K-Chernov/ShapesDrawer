#pragma once
#include "Shapes.h"
#include "DrawableInterface.h"

// Все фигуры в одном файле для задания. В реальном проекте их стоило бы растащить по разным.


class DrawableCircle : public Circle, public virtual IDrawable
{
public:
	DrawableCircle(const Рosition& center, const double radius);
	~DrawableCircle() {}

	void draw(const std::unique_ptr<Gdiplus::Graphics>& graphics) override;
	bool check(const std::function<bool(const Рosition& point)>& checker) override;

	void setPen(Pen_sp new_pen) override ;
	void setBrush(Brush_sp new_brush) override {}

private:
	Pen_sp pen;
	Brush_sp brush;
};
