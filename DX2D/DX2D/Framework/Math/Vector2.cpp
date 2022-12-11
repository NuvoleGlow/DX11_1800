#include "framework.h"
#include "Vector2.h"

Vector2 Vector2::operator+(const Vector2& other) const
{
    return Vector2(_x + other._x, _y + other._y);
}

Vector2& Vector2::operator+=(const Vector2& other)
{
    _x += other._x;
    _y += other._y;

    return *this;
}

Vector2 Vector2::operator-(const Vector2& other) const
{
    return Vector2(_x - other._x, _y - other._y);
}

Vector2& Vector2::operator-=(const Vector2& other)
{
    _x -= other._x;
    _y -= other._y;

    return *this;
}

Vector2 Vector2::operator*(const float& value) const
{
    return Vector2(_x * value, _y * value);
}

Vector2 Vector2::operator/(const float& value) const
{
    return Vector2(_x / value, _y / value);
}

bool Vector2::operator==(const Vector2& other) const
{
    if (_x != other._x)
        return false;
    if (_y != other._y)
        return false;

    return true;
}

bool Vector2::operator!=(const Vector2& other) const
{
    if (_x != other._x)
        return true;
    if (_y != other._y)
        return true;

    return false;
}

bool Vector2::operator>(const Vector2& other) const
{
    if (_y != other._y)
        return _y > other._y;

    return _x > other._x;
}

bool Vector2::operator<(const Vector2& other) const
{
    if (_y != other._y)
        return _y < other._y;

    return _x < other._x;
}

float Vector2::Dot(const Vector2& other)
{
    return _x * other._x + _y * other._y;
}

float Vector2::Cross(const Vector2& other)
{
    return _x * other._y - _y * other._x;
}

bool Vector2::IsBetween(const Vector2& vector1, const Vector2& vector2)
{
    Vector2 line1ToEnd = vector1 - *(this);
    Vector2 line1ToStart = vector2 - *(this);

    float between = line1ToEnd.Cross(*this) * line1ToStart.Cross(*this);

    return between < 0.0f;
}

float Vector2::Length() const
{
    return sqrt(powf(_x, 2) + powf(_y, 2));
}

float Vector2::Length(const Vector2& other) const
{
    Vector2 temp = (*this) - other;
    return temp.Length();
}

Vector2 Vector2::Normallize() const
{
    float legnth = this->Length();
    return Vector2(_x / legnth, _y / legnth);
}

int Vector2::Manhattan(const Vector2& other)
{
    return (int)(other._x - _x) + (int)(other._y - _y);
}

float Vector2::GetAngle(const Vector2& vector1, const Vector2& vector2)
{
    float v1 = sqrt(pow(vector1._x, 2) + pow(vector1._y, 2));
    float v2 = sqrt(pow(vector2._x, 2) + pow(vector2._y, 2));

    float inner = (vector1._x * vector2._x) + (vector1._y * vector2._y);

    float theta = acos(inner / (v1 * v2));

    float angle = (vector1._x * vector2._y - vector1._y * vector2._x < 0.0f) ? theta : -theta;

    return angle;
}
