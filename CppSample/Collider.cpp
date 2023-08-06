#include "Collider.h"
#include "TransformEventParameter.h"

Collider::Collider()
	: Component()
{
}

void Collider::OnEvent(const EventType& eventType, EventParameter& parameter)
{
	switch (eventType)
	{
		case EventType::TransformChanged:
			{
				auto transformEvent = static_cast<TransformEventParameter&>(parameter);
				if (transformEvent.entity != ownerId)
					return;

				position = transformEvent.position;
			}
			break;
		default:
			break;
	}
}
