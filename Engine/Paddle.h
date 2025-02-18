#pragma once

#include "Vec2.h"
#include "Colors.h"
#include "Ball.h"
#include "Keyboard.h"
#include "Graphics.h"
#include <cmath>

class Paddle {

public:
	Paddle(const Vec2& pos, float halfWidth, float halfHeight);
	bool DoBallCollision(Ball& ball);
	void DoWallCollision(const Rectf& wall);
	void Update(const Keyboard& kbd,float deltaTime);
	void Draw(Graphics& gfx);
	Rectf GetRect() const;
	void ResetCoolDown();

private:
	Vec2 Pos;
	static constexpr float speed = 400.0f;
	static constexpr float SideWidth = 20.0f;
	float HalfWidth;
	float HalfHeight;
	Color SideColor = Colors::Red;
	Color InnerColor = Colors::White;
	bool IsCoolDown = false;
};
