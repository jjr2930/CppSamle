#include "Console.h"
#include "Renderer.h"
#include "TransformEventParameter.h"

#include <iostream>

void Renderer::Serialize(rapidjson::Value& parent, rapidjson::Document& document)
{
}
void Renderer::Deserialize(const rapidjson::Value& source, rapidjson::Document& document)
{
	if (source.HasMember("what"))
		what = source["what"].GetString();

	if (source.HasMember("x"))
		renderPosition.SetX(source["x"].GetInt());

	if (source.HasMember("y"))
		renderPosition.SetY(source["y"].GetInt());
}
Renderer::Renderer()
	: Component()
	, renderPosition(0, 0)
	, what("")
{
}

Renderer::Renderer(const std::string& character)
	: Component()
	, renderPosition(0, 0)
	, what(character)
{
}

Renderer::~Renderer()
{
}

void Renderer::Render()
{
	Console::GetInstance()->SetPixel(renderPosition.GetX(), renderPosition.GetY(), what);
}

void Renderer::OnUpdate()
{
	Render();
}

void Renderer::OnEvent(const EventType& eventType, EventParameter& parameter)
{
	switch (eventType)
	{
	case EventType::TransformChanged:
		{
			auto castedParameter = static_cast<TransformEventParameter&>(parameter);
			if (ownerId != castedParameter.entity)
				return;

			renderPosition = castedParameter.position;
		}
		break;

	default:
		break;
	}
}