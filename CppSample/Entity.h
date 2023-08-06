#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>

#include "SerialiazableObject.h"

/**
    @class   Entity
    @brief   ������ �����ϴ� �������� ���(ĳ����, ��� ���), ������Ʈ���� �Ҽ��� �����ϱ� ���� �����Ѵ�.
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
	std::string name;	//!< 	  �� ��ƼƼ�� �̸�
};

#endif // !ENTITY