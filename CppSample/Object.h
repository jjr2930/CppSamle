#ifndef OBJECT_H
#define OBJECT_H

#include "EventType.h"
#include "EventParameter.h"
#include "GetterSetterDefine.h"

//프로토 타입 선언
class ObjectManager;

/**

    @class   Object
    @brief   Time과 Console을 제외한 모든 오브젝트들은 이 클래스를 상속받는다.
    @details ~

**/
class Object
{
public:
	virtual ~Object();

	virtual void OnEvent(const EventType& eventType, EventParameter& parameter);

 /**
     @brief  매니저를 할당해준다.
     @param manager - 
 **/
	void SetObjectManager(ObjectManager* manager);
	
	//getter setter
	GETTER_SETTER(Id, id, int);

protected:
	int id;	 //!< 이 객체가 가질 아이디 objectManager에 의해 관리된다.
	ObjectManager* objectManager;  //!< 오브젝트 매니저 포인터
};
#endif // !OBJECT_H