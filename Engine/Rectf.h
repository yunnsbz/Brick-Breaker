#pragma once

#include "Vec2.h"

class Rectf {
public:
	Rectf(float right, float left, float top, float bottom);
	Rectf(Vec2 topLeft, Vec2 bottomRight);
	Rectf(Vec2 topLeft, float width, float height);
	Rectf CenterRectf(Vec2 CenterPos, float halfWidth, float halfHeight);

	bool IsOverlappingWith(const Rectf& rect) const;

public:
	float Right;
	float Left;
	float Top;
	float Bottom;



};
