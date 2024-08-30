#include "Shapes.h"
#include <cmath>


Shape::Shape(const �osition& new_origin) : origin(new_origin)
{
}


void Shape::setOrigin(const �osition& new_origin)
{
	origin = new_origin;
}


const �osition& Shape::getOrigin() const
{
	return origin;
}


//-------------------------------------------------------------------
// Circle

Circle::Circle(const �osition& new_center, const double new_radius) :
	Shape(new_center),
	radius(new_radius)
{
}


bool Circle::isInside(const �osition& point) const
{
	return (fabs((point - getOrigin()).length_sq()) < getRadius() * getRadius());
}


double Circle::getRadius() const
{
	return radius;
}

//-------------------------------------------------------------------
// Rectangle

Rectangle::Rectangle(const �osition& new_center, const Size& new_size) :
	Shape(new_center),
	size(new_size)
{
}


const Size& Rectangle::getSize() const
{
	return size;
}


bool Rectangle::isInside(const �osition& point) const
{
	return point.x() > (getOrigin().x() - size.x() / 2) &&
		point.x() < (getOrigin().x() + size.x() / 2) &&
		point.y() > (getOrigin().y() - size.y() / 2) &&
		point.y() < (getOrigin().y() + size.y() / 2);
}


//-------------------------------------------------------------------
// Ellipse

Ellipse::Ellipse(const �osition& new_center, const Size& new_size) :
	Shape(new_center),
	size(new_size)
{
}


const Size& Ellipse::getSize() const
{
	return size;
}


bool Ellipse::isInside(const �osition& point) const
{
	auto center = getOrigin();

	return ((point.x() - center.x()) * (point.x() - center.x()) / (size.x() * size.x()) +
		(point.y() - center.y()) * (point.y() - center.y()) / (size.y() * size.y()))
		< 1;
	
}

//-------------------------------------------------------------------
// Triangle

Triangle::Triangle(const �osition& vertex1, const �osition& vertex2, const �osition& vertex3) :
	Shape(vertex1)
{
	vertices[0] = vertex1;
	vertices[1] = vertex2;
	vertices[2] = vertex3;

	�osition barycenter = (vertices[0] + vertices[1] + vertices[2]) / 3.0;
	setOrigin(barycenter);
}


const �osition& Triangle::getVertex(const TriVertexId id)
{
	return vertices[static_cast<unsigned int>(id)];
}


bool Triangle::isInside(const �osition& point) const
{
	double a = ((vertices[1].y() - vertices[2].y()) * (point.x() - vertices[2].x()) + (vertices[2].x() - vertices[1].x()) * (point.y() - vertices[2].y())) /
		((vertices[1].y() - vertices[2].y()) * (vertices[0].x() - vertices[2].x()) + (vertices[2].x() - vertices[1].x()) * (vertices[0].y() - vertices[2].y()));
	
	double b = ((vertices[2].y() - vertices[0].y()) * (point.x() - vertices[2].x()) + (vertices[0].x() - vertices[2].x()) * (point.y() - vertices[2].y())) /
		((vertices[1].y() - vertices[2].y()) * (vertices[0].x() - vertices[2].x()) + (vertices[2].x() - vertices[1].x()) * (vertices[0].y() - vertices[2].y()));
	
	double c = 1 - a - b;

	return 0 <= a && a <= 1 &&
		0 <= b && b <= 1 &&
		0 <= c && c <= 1;
}
