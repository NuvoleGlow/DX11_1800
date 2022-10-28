#pragma once
class Vector2
{
public:
	Vector2() {}
	Vector2(float x, float y) : _x(x), _y(y) {}

	Vector2 operator+(const Vector2& other);
	Vector2& operator+=(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	Vector2& operator-=(const Vector2& other);
	Vector2 operator*(const float& value);
	Vector2 operator/(const float& value);


	Vector2 Dot(const Vector2& other); // 과제 내적
	Vector2 Cross(const Vector2& other); // 과제 외적

	// 정규화 : 임의의 벡터를 단위벡터로 만드는 작업
	// 단위벡터 : 길이가 1인 벡터

	float Length();
	float Length(const Vector2& other);

	Vector2 Normalize();

	float _x = 0.0f;
	float _y = 0.0f;
};

