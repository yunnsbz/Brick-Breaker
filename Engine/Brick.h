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

private:
	Color color;
	Rectf rect;
	bool IsDestroyed = false;
	static constexpr float padding = -2.0f;
};