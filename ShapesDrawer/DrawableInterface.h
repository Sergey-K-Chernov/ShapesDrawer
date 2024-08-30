#pragma once
#include <Windows.h>
#include <memory>
#include <functional>
#include <gdiplus.h>

typedef std::shared_ptr<Gdiplus::Pen> Pen_sp;
typedef std::shared_ptr<Gdiplus::Brush> Brush_sp;

class IDrawable {
public:
	virtual void draw(const std::unique_ptr<Gdiplus::Graphics>& graphics) = 0;
	virtual bool check(const std::function<bool(const Ðosition& point)>& checker) = 0;

	virtual void setPen(Pen_sp new_pen) = 0;
	virtual void setBrush(Brush_sp new_brush) = 0;


	virtual ~IDrawable() {}
};

typedef std::unique_ptr<IDrawable> IDrawable_p;
