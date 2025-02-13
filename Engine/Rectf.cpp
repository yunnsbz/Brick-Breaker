#include "Rectf.h"

Rectf::Rectf(float right, float left, float top, float bottom)
	:
	Right(right),
	Left(left),
	Top(top),
	Bottom(bottom)
{

}

Rectf::Rectf(Vec2 topLeft, Vec2 bottomRight)
	:
	Rectf(topLeft, bottomRight.x, bottomRight.y)
{
}

Rectf::Rectf(Vec2 topLeft, float width, float height)
	:
	Rectf(width, topLeft.x, topLeft.y, height)
{
}

Rectf Rectf::CenterRectf(Vec2 CenterPos, float halfWidth, float halfHeight)
{
	return Rectf(CenterPos.x + halfWidth, CenterPos.x - halfWidth, CenterPos.y - halfHeight, CenterPos.y + halfHeight);
}

bool Rectf::IsOverlappingWith(const Rectf& other) const
{
	if (Top > other.Bottom && Left < other.Right &&
		other.Left < Right && Bottom < other.Top) 
		return true;
}
