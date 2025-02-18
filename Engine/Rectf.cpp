#include "Rectf.h"

Rectf::Rectf(float left, float right, float top, float bottom)
	:
	Left(left),
	Right(right),
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

Rectf Rectf::GetExpanded(float offset) const
{
	return Rectf(Left - offset, Right + offset, Top - offset, Bottom + offset);
}

Vec2 Rectf::GetCenter() const
{
	return Vec2((Right + Left) / 2, (Bottom + Top) / 2);
}

bool Rectf::IsOverlappingWith(const Rectf& other) const
{
	return Left <= other.Right && Right >= other.Left &&
		Bottom >= other.Top && Top <= other.Bottom;
}
