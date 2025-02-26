#include "Brick.h"

Brick::Brick(const Rectf& rect, int BreakPoint) :
	rect(rect),
	BreakPointMax(BreakPoint),
	BreakPoint(BreakPoint)
	
{
	
}

bool Brick::CheckBallCollision(const Ball& ball) const
{
	// ball should collide with something else before colliding the brick again:
	if (IsCoolDown) return false;

	// check if the ball is colliding with the brick
	else return !IsDestroyed && rect.IsOverlappingWith(ball.GetRect());
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
	--BreakPoint;
	if (BreakPoint <= 0)
		IsDestroyed = true;

	IsCoolDown = true;
}

void Brick::Draw(Graphics& gfx) const
{
	if(!IsDestroyed)
		gfx.DrawRect(rect.GetExpanded(padding), BrickColors[BreakPoint-1]);
}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}

void Brick::RestoreBrick()
{
	IsDestroyed = false;
	BreakPoint = BreakPointMax;
}

bool Brick::IsBrickDestroyed() const
{
	return IsDestroyed;
}

void Brick::ResetCoolDown()
{
	IsCoolDown = false;
}
