#pragma once

#include "Vec2.h";
#include "Colors.h";
#include "Ball.h";
#include "Keyboard.h";
#include "Graphics.h";

class Paddle {

public:
	Paddle(const Vec2& pos, float halfWidth, float halfHeight);
	bool DoBallCollision(Ball& ball) const;
	void DoWallCollision(const Rectf& wall);
	void Update(const Keyboard& kbd,float deltaTime);
	void Draw(Graphics& gfx) const;
	Rectf GetRect() const;

private:
	Vec2 Pos;
	static constexpr float speed = 200.0f;
	float HalfWidth;
	float HalfHeight;
	Color SideColor = Colors::Red;
	Color InnerColor = Colors::White;

};
