#pragma once

#include "Rectf.h"
#include "Graphics.h"
#include "Ball.h"

class Brick {
public:
	Brick() = default;
	Brick(const Rectf& rect, const Color& c);

	bool CheckBallCollision(const Ball& ball) const;
	void ExecuteBallCollision(Ball& ball);
	void Draw(Graphics& gfx) const;
	Vec2 GetCenter() const;

private:
	Color color;
	Rectf rect;
	bool IsDestroyed = false;
	static constexpr float padding = -2.0f;
};