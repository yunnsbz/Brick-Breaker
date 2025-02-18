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

/// <summary>
/// only returns true if the ball collides with the wall except the ground
/// </summary>
bool Ball::DoWallCollision(const Rectf& wall)
{
	bool collided = false;

	Rectf rect = GetRect();

	if (wall.Right < rect.Right) {
		Pos.x += wall.Right - rect.Right;
		BounceX();
		collided = true;
	}
	if (wall.Left > rect.Left) {
		Pos.x -= rect.Left - wall.Left;
		BounceX();
		collided = true;
	}
	if (wall.Top > rect.Top) {
		Pos.y += wall.Top - rect.Top;
		BounceY();
		collided = true;
	}

	return collided;
}

bool Ball::DoGroundCollision(const Rectf& wall)
{
	Rectf rect = GetRect();
	if (wall.Bottom < rect.Bottom) {
		Pos.y -= rect.Bottom - wall.Bottom;
		return true;
	}
	else return false;
}

void Ball::BounceX()
{
	Vel.x = -Vel.x;
}

void Ball::BounceY()
{
	Vel.y = -Vel.y;
}

Vec2 Ball::GetPos() const
{
	return Pos;
}

void Ball::RestoreBall()
{
	Pos = Vec2(200.0f, 300.0f);
}
