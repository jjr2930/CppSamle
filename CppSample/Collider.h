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
     @brief Owner�� ��ġ �̵� �̺�Ʈ�� ��� �̸� ���ο��� �ݿ��ϵ��� �Ͽ���.
     @param eventType - ���� �޴� �̺�Ʈ
     @param parameter - �̺�Ʈ�� ¦�� �̷�� ����Ÿ
 **/
	virtual void OnEvent(const EventType& eventType, EventParameter& parameter);

	//getter setter
	GETTER_SETTER(Position, position, Vector2Int);

protected:
	Vector2Int position;
};


#endif // !COLLIDER_H