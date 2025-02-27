#pragma once
#include "Rectf.h"
#include "graphics.h"
#include "SpriteCodex.h"
#include <cmath>

class Ball {
public:
	Ball(const Vec2& pos);
	void Draw(Graphics& gfx) const;
	void Update(float deltaTime);

	Rectf GetRect() const;
	Vec2 GetVel() const;
	bool DoWallCollision(const Rectf& wall);
	bool DoGroundCollision(const Rectf& wall);
	void BounceX();
	void BounceY();
	void ChangeAngle(float dx);
	Vec2 GetPos() const;
	void RestoreBall();

private:
	static constexpr float Radius = 7.0f;
	static constexpr float MaxAngleChange = 50.0f;
	Vec2 Pos;

	// can change angle of the ball
	Vec2 Vel = Vec2(110.0f, -80.0f);

	// constant velocity of the ball
	Vec2 VelConst = Vel;
};