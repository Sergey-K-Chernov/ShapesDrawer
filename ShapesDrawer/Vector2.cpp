#include "Vector2.h"





Vector2::Vector2() : _x(0), _y(0)
{
}


Vector2::Vector2(double x, double y) : _x(x), _y(y)
{
}


double Vector2::x() const
{
	return _x;
}


double Vector2::y() const
{
	return _y;
}


double Vector2::length_sq() const
{
	return _x * _x + _y * _y;
}
