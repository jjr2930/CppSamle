#ifndef COMPONENT_H
#define COMPONENT_H

#include "SerialiazableObject.h"
#include "GetterSetterDefine.h"

/**

    @class   Component
    @brief   모든 컴포넌트들의 부모 클래스, 모든 컴포넌트들은 이것을 상속받아야 한다.
    @details ~

**/
class Component : public SerialiazableObject
{
public:
	Component();
	virtual ~Component();

	//inherited functions
 /**
     @brief 업데이트 하기 전 딱 한 번 만 실행한다.
 **/
	virtual void OnStart();
 /**
     @brief 매 프레임 실행되는 함수, 자신의 값을 업데이트 하기 위해 사용된다.
 **/
	virtual void OnUpdate();

	virtual void Serialize(rapidjson::Value& parent, rapidjson::Document& document);
	virtual void Deserialize(const rapidjson::Value& source, rapidjson::Document& document);

	//getter setter
	GETTER_SETTER(OwnerId, ownerId, int);

protected :
	int ownerId;	 //!< 이 컴포넌트의 소유 엔티티의 아이디
	bool isInit;	 //!< OnStart 함수가 한 번 호출 되었는지 여부가 이 변수에 있다.
};

#endif // !COPONENT