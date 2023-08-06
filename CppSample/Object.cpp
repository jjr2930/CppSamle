#include "Object.h"

Object::~Object()
{
}

void Object::OnEvent(const EventType& eventType, EventParameter& parameter)
{
}

void Object::SetObjectManager(ObjectManager* manager)
{
	objectManager = manager;
}
