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

Rectf Ball::GetRect() const
{
	return Rectf::CenterRectf(Pos, Radius, Radius);
}

Vec2 Ball::GetVel() const
{
	return Vel;
}

bool Ball::DoWallCollision(const Rectf& wall)
{
	bool collided = false;

	Rectf rect = GetRect();

	if (wall.Left > rect.Left) {
		Pos.x += wall.Left - rect.Left;
		BounceX();
		collided = true;
	}
	if (wall.Right < rect.Right) {
		Pos.x -= rect.Right - wall.Right;
		BounceX();
		collided = true;
	}
	if (wall.Top > rect.Top) {
		Pos.y += wall.Top - rect.Top;
		BounceY();
		collided = true;
	}
	if (wall.Bottom < rect.Bottom) {
		Pos.y -= rect.Bottom - wall.Bottom;
		BounceY();
		collided = true;
	}

	return collided;
}

void Ball::BounceX()
{
	Vel.x = -Vel.x;
}

void Ball::BounceY()
{
	Vel.y = -Vel.y;
}
