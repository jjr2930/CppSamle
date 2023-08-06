#include "ScoreCounter.h"
#include "Const.h"
#include "ObjectManager.h"
#include "ScoreEvent.h"

ScoreCounter::ScoreCounter()
	: Component()
	, score(0)
{
}

void ScoreCounter::OnEvent(const EventType& eventType, EventParameter& parameter)
{
	switch (eventType)
	{
		case EventType::PooDestroyed:
			{
				score += 1;

				ScoreEvent newEvent;
				newEvent.score = score;
				objectManager->OnEvent(EventType::ScoreChanged, newEvent);
			}
			break;
		default:
			break;
	}
}
