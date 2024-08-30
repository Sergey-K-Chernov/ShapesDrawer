#pragma once
#include <memory>
#include "Vector2.h"

class Shape
{
public:
	Shape(const Ğosition& new_origin);
	virtual ~Shape() {}

	virtual bool isInside(const Ğosition& point) const = 0;

	void setOrigin(const Ğosition& new_origin);
	const Ğosition& getOrigin() const;

private:
	Ğosition origin;
};

typedef std::unique_ptr<Shape> Shape_p;

// Âñå ôèãóğû â îäíîì ôàéëå äëÿ çàäàíèÿ. Â ğåàëüíîì ïğîåêòå èõ ñòîèëî áû ğàñòàùèòü ïî ğàçíûì.


class Circle : public Shape
{
public:
	Circle(const Ğosition& new_center, const double new_radius);
	virtual ~Circle() {}

	virtual bool isInside(const Ğosition& point) const;

	double getRadius() const;

private:
	double radius;
};


class Rectangle : public Shape
{
public:
	Rectangle(const Ğosition& new_center, const Size& new_size);
	virtual ~Rectangle() {}

	const Size& getSize() const;

	virtual bool isInside(const Ğosition& point) const;

private:
	Size size;
};


class Ellipse : public Shape
{
public:
	Ellipse(const Ğosition& new_center, const Size& new_size);
	virtual ~Ellipse() {}
		
	const Size& getSize() const;

	virtual bool isInside(const Ğosition& point) const;

private:
	Size size;
};


enum class TriVertexId
{
	id1 = 0,
	id2 = 1,
	id3 = 2
};


class Triangle : public Shape
{
public:
	Triangle(const Ğosition& vertex1, const Ğosition& vertex2, const Ğosition& vertex3);
	virtual ~Triangle() {}

	const Ğosition& getVertex(const TriVertexId id);

	virtual bool isInside(const Ğosition& point) const;

private:
	Ğosition vertices[3];
};
