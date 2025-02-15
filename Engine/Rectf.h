#pragma once

#include "Vec2.h"

class Rectf {
public:
	Rectf() = default;
	Rectf(float right, float left, float top, float bottom);
	Rectf(const Vec2& topLeft, const Vec2& bottomRight);
	Rectf(const Vec2& topLeft, float width, float height);
	static Rectf CenterRectf(const Vec2& CenterPos, float halfWidth, float halfHeight);
	Rectf GetExpanded(float offset) const;
	bool IsOverlappingWith(const Rectf& rect) const;

public:
	float Right;
	float Left;
	float Top;
	float Bottom;



};
