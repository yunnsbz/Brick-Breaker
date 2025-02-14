#include "Rectf.h"

Rectf::Rectf(float right, float left, float top, float bottom)
	:
	Right(right),
	Left(left),
	Top(top),
	Bottom(bottom)
{

}

Rectf::Rectf(const Vec2& topLeft, const Vec2& bottomRight)
	:
	Rectf(topLeft.x, bottomRight.x, topLeft.y, bottomRight.y)
{
}

Rectf::Rectf(const Vec2& topLeft, float width, float height)
	:
	Rectf(topLeft, topLeft + Vec2(width, height))
{
}

Rectf Rectf::CenterRectf(const Vec2& center, float halfWidth, float halfHeight)
{
	const Vec2 half(halfWidth, halfHeight);
	return Rectf(center - half, center + half);
}

bool Rectf::IsOverlappingWith(const Rectf& other) const
{
	return Right < other.Left && Left > other.Right &&
		Bottom > other.Top && Top < other.Bottom;
}
