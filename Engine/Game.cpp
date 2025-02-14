/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	Ball(Vec2(100.0f, 100.0f), Vec2(280.0f, 270.0f)),
	Walls(Rectf(Vec2(0, 0), gfx.ScreenWidth, gfx.ScreenHeight)),
	BallSound(L"Sounds\\arkpad.wav"),
	BrickSound(L"Sounds\\arkbrick.wav"),
	Brick(Rectf(Vec2(300,400),Vec2(550,440)),Color(120,200,200)),
	Paddle(Vec2(320,500),100,10)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark();

	Paddle.Update(wnd.kbd, dt);
	Paddle.DoWallCollision(Walls);

	Ball.Update(dt);
	
	if (Paddle.DoBallCollision(Ball)) 
	{
		BrickSound.Play();
	}

	if (Ball.DoWallCollision(Walls))
	{
		BallSound.Play();
	}

}

void Game::ComposeFrame()
{
	Ball.Draw(gfx);
	Paddle.Draw(gfx);
}
