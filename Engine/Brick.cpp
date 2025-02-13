#include "Brick.h"

Brick::Brick(Rectf& rect, Color c) :
	rect(rect),
	color(c)
{

}

void Brick::Draw(Graphics& gfx) const
{
	gfx.DrawRect(rect, color);
}
