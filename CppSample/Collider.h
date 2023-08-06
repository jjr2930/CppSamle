#ifndef COLLIDER_H
#define COLLIDER_H

#include "Component.h"
#include "Vector2Int.h"
#include "GetterSetterDefine.h"

class Collider : public Component
{
public : 
	Collider();
			
 /**
     @brief Owner의 위치 이동 이벤트를 듣고 이를 본인에게 반영하도록 하였다.
     @param eventType - 전달 받는 이벤트
     @param parameter - 이벤트와 짝을 이루는 데이타
 **/
	virtual void OnEvent(const EventType& eventType, EventParameter& parameter);

	//getter setter
	GETTER_SETTER(Position, position, Vector2Int);

protected:
	Vector2Int position;
};


#endif // !COLLIDER_H