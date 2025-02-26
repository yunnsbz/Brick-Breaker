#pragma once

#include "Rectf.h"
#include "Graphics.h"
#include "Ball.h"
#include <cmath>

class Brick {
public:
	Brick() = default;
	Brick(const Rectf& rect, int BreakPoint = 1);

	bool CheckBallCollision(const Ball& ball) const;
	void ExecuteBallCollision(Ball& ball);
	void Draw(Graphics& gfx) const;
	Vec2 GetCenter() const;
	void RestoreBrick();
	bool IsBrickDestroyed() const;
	void ResetCoolDown();
private:
	Color color;
	Rectf rect;
	bool IsDestroyed = false;
	static constexpr float padding = -2.0f;
	int BreakPoint;
	int BreakPointMax;
	static constexpr Color BrickColors[4] = { Colors::White, Colors::Green, Colors::Blue, Colors::Red };
	bool IsCoolDown = false;
};