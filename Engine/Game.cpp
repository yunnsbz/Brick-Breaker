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
	Ball(Vec2(600.0f, 400.0f), Vec2(40.0f, -35.0f)),
	Walls(Rectf(Vec2(0, 0), gfx.ScreenWidth, gfx.ScreenHeight)),
	BallSound(L"Sounds\\arkpad.wav"),
	BrickSound(L"Sounds\\arkbrick.wav"),
	Paddle(Vec2(150,500),50,20)
{
	const Color BrickColors[BrickCountY] = { Colors::White, Colors::Blue ,Colors::Green, Colors::Red };
	const Vec2 TopLeft(100, 50);
	const float Width = 50;
	const float Height = 20;

	int i = 0;
	for (int y = 0; y < BrickCountY; y++)
	{
		const Color c = BrickColors[y];
		for (int x = 0; x < BrickCountX; x++)
		{
			Rectf brickRect = Rectf(TopLeft + Vec2(Width * x, Height * y), Width, Height);
			Bricks[i] = Brick(brickRect, c);
			i++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	

	float elapsedTime = ft.Mark();
	while (elapsedTime > 0) {
		float dt = std::min(elapsedTime, 0.0025f);
		UpdateModel(elapsedTime);
		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel( float dt)
{
	if (gameState == Playing) {

		Paddle.Update(wnd.kbd, dt);
		Paddle.DoWallCollision(Walls);

		Ball.Update(dt);

		bool collisionHapened = false;
		float curColDist;
		int curColIndex;

		for (int i = 0; i < TotalBrickCount; i++) {
			if (Bricks[i].CheckBallCollision(Ball)) {
				const Vec2 ballPos = Ball.GetPos();
				const Vec2 brickCenter = Bricks[i].GetCenter();
				const Vec2 diff = ballPos - brickCenter;
				const float diffLen = diff.GetLength();
				if (!collisionHapened) {
					collisionHapened = true;
					curColDist = diffLen;
					curColIndex = i;
				}
				else if (diffLen < curColDist) {
					curColDist = diffLen;
					curColIndex = i;
				}
			}
		}
		if (collisionHapened) {
			Bricks[curColIndex].ExecuteBallCollision(Ball);
			BrickSound.Play();
			Paddle.ResetCoolDown();
		}


		if (Paddle.DoBallCollision(Ball))
		{
			BallSound.Play();
		}

		// game over if ball touches the ground
		if (Ball.DoGroundCollision(Walls)) {
			gameState = GameOver;
		}


		// ball bounces off the wall
		if (Ball.DoWallCollision(Walls))
		{
			BallSound.Play();
			Paddle.ResetCoolDown();
		}
	}
	else if (gameState == GameOver) {
		if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
			RestartGame();
		}
	}
	else if (gameState == Win) {
		if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
			RestartGame();
		}
	}
}

void Game::ComposeFrame()
{
	if (gameState == Playing) {
		for (const Brick& B : Bricks) {
			B.Draw(gfx);
		}
		Ball.Draw(gfx);
		Paddle.Draw(gfx);
	}
	else if (gameState == GameOver) {

	}
	else if (gameState == Win) {

	}
}

void Game::RestartGame()
{
	for (Brick& B : Bricks) {
		B.RestoreBrick();
	}
	Ball.RestoreBall();

	gameState = Playing;
}
