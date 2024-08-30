#pragma once

class Vector2
{
public:
	Vector2();
	Vector2(double x, double y);
	~Vector2() {}

	double x() const;
	double y() const;

	double length_sq() const;

private:
	double _x;
	double _y;

	friend Vector2 operator + (const Vector2& v1, const Vector2& v2);
	friend Vector2 operator - (const Vector2& v1, const Vector2& v2);
	friend Vector2 operator / (const Vector2& v, const double d);
	// *, <, >, >=, <= �� �������������
};

inline Vector2 operator + (const Vector2& v1, const Vector2& v2)
{
	return Vector2(v1._x + v2._x, v1._y + v2._y);
}


inline Vector2 operator - (const Vector2& v1, const Vector2& v2)
{
	return Vector2(v1._x - v2._x, v1._y - v2._y);
}



inline Vector2 operator / (const Vector2& v, const double d)
{
	return Vector2(v._x / d, v._y / d);
}


class Size;


class �osition : public Vector2
{
public:
	�osition() {}
	�osition(double x, double y) : Vector2(x, y) {}
	�osition(const Vector2& v) : Vector2(v) {}

	�osition(const Size&) = delete;
	�osition(Size&) = delete;
};


class Size : public Vector2
{
public:
	Size() {}
	Size(double x, double y) : Vector2(x, y) {}
	Size(const Vector2& v) : Vector2(v) {}

	Size(const �osition&) = delete;
	Size(�osition&) = delete;
};
