#include "Brick.h"

Brick::Brick(const Rectf& rect, const Color& c) :
	rect(rect),
	color(c)
{

}

bool Brick::CheckBallCollision(const Ball& ball) const
{
	return !IsDestroyed && rect.IsOverlappingWith(ball.GetRect());
}

void Brick::ExecuteBallCollision(Ball& ball)
{
	// get ball position to check if it is colliding with bottom-top or left-right
	const Vec2 ballPos = ball.GetPos();
	if (std::signbit(ball.GetVel().x) == std::signbit((ballPos - GetCenter()).x))
	{
		ball.BounceY();
	}
	else if (ballPos.x >= rect.Left && ballPos.x <= rect.Right)
	{
		ball.BounceY();
	}
	else
	{
		ball.BounceX();
	}
	IsDestroyed = true;
}

void Brick::Draw(Graphics& gfx) const
{
	if(!IsDestroyed)
		gfx.DrawRect(rect.GetExpanded(padding), color);
}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}

void Brick::RestoreBrick()
{
	IsDestroyed = false;
}
