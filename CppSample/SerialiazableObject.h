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
    @brief   역직렬화, 직렬화 가능한 모든 클래스는 이 클래스를 상속받아 Serialize(직렬화 함수), Deserialize(역직렬화 함수)를 구현한다.
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