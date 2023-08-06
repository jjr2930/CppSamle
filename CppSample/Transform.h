#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"
#include "Vector2Int.h"

/**

    @class   Transform	��ƼƼ�� ��ġ�� �����ϱ� ����, ������Ʈ�̴�.
    @brief   
    @details ~

**/
class Transform : public Component
{

public:
 /**
     @brief Transform object constructor
 **/
	Transform();
 /**
     @brief Transform object destructor
 **/
	virtual ~Transform();

 /**
     @brief ��ġ�� ����Ǿ��ٴ� �̺�Ʈ�� �����Ѵ�. �̺�Ʈ Ÿ���� TransformChanged, ����� �Ķ���ʹ� TransformEventParameter
 **/
	void EmitEvent();
	
 /**
     @brief ��ġ�� �����Ѵ�.
     @param x - ������ x�� ��
     @param y - ������ y�� ��
 **/
	void SetPosition(const int& x, const int& y);


	/*
	* inherited functions
	*/
	virtual void OnStart();
	virtual void Serialize(rapidjson::Value& parent, rapidjson::Document& document);
	virtual void Deserialize(const rapidjson::Value& source, rapidjson::Document& document);
	
protected:
	Vector2Int position;
};

#endif // !TRANSFORM_H
