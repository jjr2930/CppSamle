#include <iostream>
#include "Entity.h"


Entity::Entity()
	: SerialiazableObject()
{
}

Entity::~Entity()
{
}

void Entity::Serialize(rapidjson::Value& parent, rapidjson::Document& document)
{
}

void Entity::Deserialize(const rapidjson::Value& source, rapidjson::Document& document)
{
	this->name = source["name"].GetString();
}