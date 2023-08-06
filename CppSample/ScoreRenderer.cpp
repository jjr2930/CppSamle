#include "ScoreRenderer.h"
#include "ScoreEvent.h"
#include "Const.h"
#include "Console.h"

#include <iostream>
#include <math.h>
#include <Windows.h>
#include <string>

ScoreRenderer::ScoreRenderer()
	: Renderer("0")
{
}

void ScoreRenderer::Render()
{
	Console::GetInstance()->SetPixel(Const::SCORE_POSITION_X, Const::SCORE_POSITION_Y, what);
}

void ScoreRenderer::OnEvent(const EventType& eventType, EventParameter& parameter)
{
	switch (eventType)
	{
		case EventType::ScoreChanged:
			auto scoreEvent = static_cast<ScoreEvent&>(parameter);
			what = std::to_string(scoreEvent.score);
			break;
		default:
			break;
	}
}
