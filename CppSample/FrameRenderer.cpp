#include "Const.h"
#include "FrameRenderer.h"
#include "Console.h"

#include <iostream>

FrameRenderer::FrameRenderer()
	: Renderer()
{
}

void FrameRenderer::Render()
{
	for (int x = Const::FRAME_MIN_X; x <= Const::FRAME_MAX_X; x++)
	{
		auto y = Const::FRAME_MIN_Y;
		Console::GetInstance()->SetPixel(x, y, what);
	}

	for (int x = Const::FRAME_MIN_X; x <= Const::FRAME_MAX_X; x++)
	{
		auto y = Const::FRAME_MAX_Y;
		Console::GetInstance()->SetPixel(x, y, what);
	}

	for (int y = Const::FRAME_MIN_Y; y <= Const::FRAME_MAX_Y; y++)
	{
		auto x = Const::FRAME_MIN_X;
		Console::GetInstance()->SetPixel(x, y, what);
	}

	for (int y = Const::FRAME_MIN_Y; y <= Const::FRAME_MAX_Y; y++)
	{
		auto x = Const::FRAME_MAX_X;
		Console::GetInstance()->SetPixel(x, y, what);
	}
}
