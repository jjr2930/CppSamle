#ifndef SERIALIZABLE_OBJECT_H
#define SERIALIZABLE_OBJECT_H

#ifdef max
#undef max
#undef min	
#endif // max

#include "rapidjson/document.h"
#include "Object.h"

/**

    @class   SerialiazableObject
    @brief   ������ȭ, ����ȭ ������ ��� Ŭ������ �� Ŭ������ ��ӹ޾� Serialize(����ȭ �Լ�), Deserialize(������ȭ �Լ�)�� �����Ѵ�.
    @details ~

**/
class SerialiazableObject : public Object
{
public:
	SerialiazableObject();
	virtual ~SerialiazableObject();

	//these functions will be inherited
	virtual void Serialize(rapidjson::Value& parent, rapidjson::Document& document);
	virtual void Deserialize(const rapidjson::Value& source, rapidjson::Document& document);
};

#endif // !SERIALIZABLE_OBJECT_H