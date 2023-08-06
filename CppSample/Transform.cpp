#include "Transform.h"
#include "TransformEventParameter.h"
#include "InputEventParameter.h"
#include "ObjectManager.h"

void Transform::OnStart()
{
	EmitEvent();
}

void Transform::Serialize(rapidjson::Value& parent, rapidjson::Document& document)
{
}

void Transform::Deserialize(const rapidjson::Value& source, rapidjson::Document& document)
{
	if(source.HasMember("x"))
		position.SetX(source["x"].GetInt());

	if (source.HasMember("y"))
		position.SetY(source["y"].GetInt());
}

Transform::Transform()
	:Component()
{
}

Transform::~Transform()
{
}

void Transform::SetPosition(const int& x, const int& y)
{
	position.SetX(x);
	position.SetY(y);

	EmitEvent();
}

void Transform::EmitEvent()
{
	TransformEventParameter eventParameter;
	eventParameter.entity = ownerId;
	eventParameter.position = position;

	objectManager->OnEvent(EventType::TransformChanged, eventParameter);
}
