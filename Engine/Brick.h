#pragma once

#include "Rectf.h"
#include "Graphics.h"
#include "Ball.h"

class Brick {
public:
	Brick() = default;
	Brick(const Rectf& rect, const Color& c);

	bool DoBallCollision(Ball& ball);
	void Draw(Graphics& gfx) const;

public:
	Color color;
	Rectf rect;
	bool IsDestroyed = false;
};