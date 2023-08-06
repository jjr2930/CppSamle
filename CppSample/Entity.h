#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>

#include "SerialiazableObject.h"

/**
    @class   Entity
    @brief   게임을 구성하는 개념적인 요소(캐릭터, 장면 등등), 컴포넌트들의 소속을 구분하기 위해 존재한다.
    @details ~
**/
class Entity : public SerialiazableObject
{
public:
	Entity();
	virtual ~Entity();

	virtual void Serialize(rapidjson::Value& parent, rapidjson::Document& document);
	virtual void Deserialize(const rapidjson::Value& source, rapidjson::Document& document);

private:
	std::string name;	//!< 	  이 엔티티의 이름
};

#endif // !ENTITY