#pragma once
#include <memory>
#include "Vector2.h"

class Shape
{
public:
	Shape(const �osition& new_origin);
	virtual ~Shape() {}

	virtual bool isInside(const �osition& point) const = 0;

	void setOrigin(const �osition& new_origin);
	const �osition& getOrigin() const;

private:
	�osition origin;
};

typedef std::unique_ptr<Shape> Shape_p;

// ��� ������ � ����� ����� ��� �������. � �������� ������� �� ������ �� ��������� �� ������.


class Circle : public Shape
{
public:
	Circle(const �osition& new_center, const double new_radius);
	virtual ~Circle() {}

	virtual bool isInside(const �osition& point) const;

	double getRadius() const;

private:
	double radius;
};


class Rectangle : public Shape
{
public:
	Rectangle(const �osition& new_center, const Size& new_size);
	virtual ~Rectangle() {}

	const Size& getSize() const;

	virtual bool isInside(const �osition& point) const;

private:
	Size size;
};


class Ellipse : public Shape
{
public:
	Ellipse(const �osition& new_center, const Size& new_size);
	virtual ~Ellipse() {}
		
	const Size& getSize() const;

	virtual bool isInside(const �osition& point) const;

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
	Triangle(const �osition& vertex1, const �osition& vertex2, const �osition& vertex3);
	virtual ~Triangle() {}

	const �osition& getVertex(const TriVertexId id);

	virtual bool isInside(const �osition& point) const;

private:
	�osition vertices[3];
};
