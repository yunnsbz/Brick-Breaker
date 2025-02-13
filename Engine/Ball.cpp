#include "Ball.h"

Ball::Ball(const Vec2& pos, const Vec2 vel)
	: 
	Vel(vel), 
	Pos(pos)
{
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(Pos, gfx);
}

void Ball::Update(float deltaTime)
{
	Pos += Vel * deltaTime;
}

bool Ball::DoWallCollision(const Rectf& wall)
{

	return false;
}

void Ball::BounceX()
{
}

void Ball::BounceY()
{
}
