#pragma once

#include "Rectf.h"
#include "Graphics.h"

class Brick {
public:

	Brick(Rectf& rect, Color c);

	void Draw(Graphics& gfx) const;

public:
	Color color;
	Rectf rect;
	bool IsDestroyed = false;
};