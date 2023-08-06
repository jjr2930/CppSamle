#include "Vector2Int.h"

Vector2Int::Vector2Int()
	:x(0)
	,y(0)
{
}

Vector2Int::Vector2Int(const int& x, const int& y)
	:x(x)
	,y(y)
{
}

Vector2Int::~Vector2Int()
{
}

Vector2Int Vector2Int::operator*(const int& source)
{
	Vector2Int result = Vector2Int();
	result.x = this->x * source;
	result.y = this->y * source;
	return result;
}

Vector2Int Vector2Int::operator/(const int& source)
{
	Vector2Int result = Vector2Int();
	result.x = this->x / source;
	result.y = this->y / source;
	return result;
}

Vector2Int Vector2Int::operator+(const Vector2Int& source)
{
	Vector2Int result = Vector2Int();
	result.x = this->x + source.x;
	result.y = this->y + source.y;
	return result;
}

Vector2Int Vector2Int::operator-(const Vector2Int& source)
{
	Vector2Int result = Vector2Int();
	result.x = this->x - source.x;
	result.y = this->y - source.y;
	return result;
}

Vector2Int Vector2Int::operator+=(const Vector2Int& source)
{
	Vector2Int result = Vector2Int();
	result.x = this->x + source.x;
	result.y = this->y + source.y;
	return result;
}

int Vector2Int::GetX() const
{
	return this->x;
}

void Vector2Int::SetX(const int& value)
{
	this->x = value;
}

void Vector2Int::AddX(const int& amount)
{
	this->x += amount;
}

int Vector2Int::GetY() const
{
	return this->y;
}

void Vector2Int::SetY(const int& value)
{
	this->y = value;
}

void Vector2Int::AddY(const int& amount)
{
	this->y += amount;
}
