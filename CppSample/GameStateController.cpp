#include "GameStateController.h"
#include "CollisionEvent.h"
#include "ObjectManager.h"
#include "PlayerTransform.h"
#include "Game.h"

void GameStateController::OnEvent(const EventType& eventType, EventParameter& parameter)
{
	switch (eventType)
	{
		case EventType::Collided:
			{
				auto collisionEvent = static_cast<CollisionEvent&>(parameter);
				auto playerTransform = objectManager->GetComponents<PlayerTransform>();
				auto playerId = playerTransform[0]->GetOwnerId();
				if (collisionEvent.colliderA->GetOwnerId() == playerId
					|| collisionEvent.colliderB->GetOwnerId() == playerId)
				{
					Game::GetInstance()->SetIsFinished(true);
				}
			}
			break;
		default:
			break;
	}
}
