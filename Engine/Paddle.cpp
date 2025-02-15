#include "Paddle.h"

Paddle::Paddle(const Vec2& pos, float halfWidth, float halfHeight)
	:
	Pos(pos),
	HalfWidth(halfWidth),
	HalfHeight(halfHeight)
{
}

bool Paddle::DoBallCollision(Ball& ball) const
{
	if (ball.GetVel().y > 0 && GetRect().IsOverlappingWith(ball.GetRect())) {
		ball.BounceY();
		return true;
	}
	return false;
}

void Paddle::DoWallCollision(const Rectf& walls)
{
	const Rectf rect = GetRect();
	if (rect.Right > walls.Right)
	{
		Pos.x += walls.Right - rect.Right;
	}
	else if (rect.Left < walls.Left)
	{
		Pos.x -= rect.Left - walls.Left;
	}
}

void Paddle::Update(const Keyboard& kbd, float deltaTime)
{
	if (kbd.KeyIsPressed(VK_LEFT)) {
		Pos.x -= speed * deltaTime;
	}

	if (kbd.KeyIsPressed(VK_RIGHT)) {
		Pos.x += speed * deltaTime;
	}
}

void Paddle::Draw(Graphics& gfx)
{
	gfx.DrawRect(GetRect(), SideColor);
	HalfWidth -= SideWidth;
	gfx.DrawRect(GetRect(), InnerColor);
	HalfWidth += SideWidth;
}

Rectf Paddle::GetRect() const
{
	return Rectf::CenterRectf(Pos, HalfWidth, HalfHeight);
}
