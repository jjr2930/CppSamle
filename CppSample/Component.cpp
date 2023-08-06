#include "Component.h"

Component::Component()
	: SerialiazableObject()
	, ownerId(0)
{
	isInit = false;
}

Component::~Component()
{
}

void Component::OnStart()
{
}

void Component::OnUpdate()
{
	if (false == isInit)
	{
		OnStart();
		isInit = true;
		return;
	}
}

void Component::Serialize(rapidjson::Value& parent, rapidjson::Document& document)
{
	SerialiazableObject::Serialize(parent, document);
}

void Component::Deserialize(const rapidjson::Value& source, rapidjson::Document& document)
{
	SerialiazableObject::Deserialize(source, document);
}
