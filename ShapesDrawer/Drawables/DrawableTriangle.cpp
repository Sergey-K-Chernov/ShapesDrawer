#include "DrawableTriangle.h"


DrawableTriangle::DrawableTriangle(const Ðosition& vertex1, const Ðosition& vertex2, const Ðosition& vertex3) :
	Triangle(vertex1, vertex2, vertex3)
{
	pen = Pen_sp(new Gdiplus::Pen(Gdiplus::Color(255, 0, 255, 0), 1));
	brush = Brush_sp(new Gdiplus::SolidBrush(Gdiplus::Color(255, 0, 255, 0)));
}


void DrawableTriangle::draw(const std::unique_ptr<Gdiplus::Graphics>& graphics)
{
	Gdiplus::GraphicsPath path;

	path.AddLine(static_cast<INT>(getVertex(TriVertexId::id1).x()),
		static_cast<INT>(getVertex(TriVertexId::id1).y()),
		static_cast<INT>(getVertex(TriVertexId::id2).x()),
		static_cast<INT>(getVertex(TriVertexId::id2).y()));

	path.AddLine(static_cast<INT>(getVertex(TriVertexId::id2).x()),
		static_cast<INT>(getVertex(TriVertexId::id2).y()),
		static_cast<INT>(getVertex(TriVertexId::id3).x()),
		static_cast<INT>(getVertex(TriVertexId::id3).y()));

	path.AddLine(static_cast<INT>(getVertex(TriVertexId::id3).x()),
		static_cast<INT>(getVertex(TriVertexId::id3).y()),
		static_cast<INT>(getVertex(TriVertexId::id1).x()),
		static_cast<INT>(getVertex(TriVertexId::id1).y()));

	graphics->FillPath(brush.get(), &path);
	graphics->DrawPath(pen.get(), &path);
}


bool DrawableTriangle::check(const std::function<bool(const Ðosition& point)>& checker)
{
	return checker(getOrigin());
}



void DrawableTriangle::setPen(Pen_sp new_pen)
{
	pen = new_pen;
}


void DrawableTriangle::setBrush(Brush_sp new_brush)
{
	brush = new_brush;
}
