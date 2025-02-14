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

void Paddle::DoWallCollision(const Rectf& wall)
{
	if (wall.Left > GetRect().Left) {
		Pos.x += wall.Left - GetRect().Left;
	}
	if (wall.Right < GetRect().Right) {
		Pos.x -= GetRect().Right - wall.Right;
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

void Paddle::Draw(Graphics& gfx) const
{
	gfx.DrawRect(GetRect(), InnerColor);
}

Rectf Paddle::GetRect() const
{
	return Rectf::CenterRectf(Pos, HalfWidth, HalfHeight);
}
