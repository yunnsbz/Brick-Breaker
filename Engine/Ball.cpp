#include "Ball.h"

Ball::Ball(const Vec2& pos)
	: 
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
	VelConst.x = -VelConst.x;
}

void Ball::BounceY()
{
	Vel.y = -Vel.y;
	VelConst.y = -VelConst.y;
}

void Ball::ChangeAngle(float dx)
{
	Vel.x = VelConst.x + dx;

	int sign = std::signbit(Vel.y) ? -1 : 1;

	float VelSquared = VelConst.GetLengthSq();
	Vel.y = sqrtf(abs(VelSquared - Vel.x * Vel.x));
	Vel.y *= sign;
}

Vec2 Ball::GetPos() const
{
	return Pos;
}

void Ball::RestoreBall()
{
	Pos = Vec2(200.0f, 300.0f);
	Vel = VelConst;
}
