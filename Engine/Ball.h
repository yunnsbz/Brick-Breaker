#pragma once
#include "Rectf.h"
#include "graphics.h"
#include "SpriteCodex.h"

class Ball {
public:
	Ball(const Vec2& pos, const Vec2 vel);
	void Draw(Graphics& gfx) const;
	void Update(float deltaTime);

	Rectf GetRect() const;
	Vec2 GetVel() const;
	bool DoWallCollision(const Rectf& wall);
	void BounceX();
	void BounceY();
	Vec2 GetPos() const;
private:
	static constexpr float Radius = 7.0f;
	Vec2 Pos;
	Vec2 Vel;


};