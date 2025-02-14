#include "Brick.h"

Brick::Brick(const Rectf& rect, const Color& c) :
	rect(rect),
	color(c)
{

}

bool Brick::DoBallCollision(Ball& ball)
{
	if (!IsDestroyed && rect.IsOverlappingWith(ball.GetRect())) {
		ball.BounceY();
		IsDestroyed = true;
		return true;
	}
	else {
		return false;
	}
}

void Brick::Draw(Graphics& gfx) const
{
	if(!IsDestroyed)
		gfx.DrawRect(rect, color);
}
