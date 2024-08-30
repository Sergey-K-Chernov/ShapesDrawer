#pragma once
#include "Shapes.h"
#include "DrawableInterface.h"


class DrawableFrame : public Rectangle, public virtual IDrawable
{
public:
	DrawableFrame(const �osition& center, const Size& size);
	virtual ~DrawableFrame() {}

	virtual void draw(const std::unique_ptr<Gdiplus::Graphics>& graphics);
	virtual bool check(const std::function<bool(const �osition& point)>& checker);

	virtual void setPen(Pen_sp new_pen);
	virtual void setBrush(Brush_sp new_brush) {}

private:
	Pen_sp pen;
};
