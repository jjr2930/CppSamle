#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"
#include "Vector2Int.h"

/**

    @class   Transform	엔티티의 위치를 제어하기 위한, 컴포넌트이다.
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
     @brief 위치가 변경되었다는 이벤트를 방출한다. 이벤트 타입은 TransformChanged, 사용할 파라미터는 TransformEventParameter
 **/
	void EmitEvent();
	
 /**
     @brief 위치를 변경한다.
     @param x - 변경할 x의 값
     @param y - 변경할 y의 값
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
