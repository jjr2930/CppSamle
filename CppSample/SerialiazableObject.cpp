#include "SerialiazableObject.h"


SerialiazableObject::SerialiazableObject()
	: Object()
{
}

SerialiazableObject::~SerialiazableObject()
{
}

void SerialiazableObject::Serialize(rapidjson::Value& parent, rapidjson::Document& document)
{
}

void SerialiazableObject::Deserialize(const rapidjson::Value& source, rapidjson::Document & document)
{
}
