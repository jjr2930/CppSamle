#include "ColliderChecker.h"
#include "Collider.h"
#include "ObjectManager.h"
#include "CollisionEvent.h"

void ColliderChecker::OnUpdate()
{	
	auto ownerCollider = objectManager->GetComponent<Collider>(ownerId);
	auto colliders = objectManager->GetComponents<Collider>();
	for (auto iter = colliders.begin(); iter != colliders.end(); iter++)
	{
		auto otherCollider = (*iter);
		if (otherCollider->GetOwnerId() == ownerId)
			continue;

		auto otherPosition = otherCollider->GetPosition();
		auto ownerPosition = ownerCollider->GetPosition();

		if (otherPosition.GetX() == ownerPosition.GetX()
			&& otherPosition.GetY() == ownerPosition.GetY())
		{
			CollisionEvent newEvent;
			newEvent.colliderA = ownerCollider;
			newEvent.colliderB = otherCollider;
			newEvent.collisionPosition = otherPosition;

			objectManager->OnEvent(EventType::Collided, newEvent);
		}
	}
}
