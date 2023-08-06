#ifndef OBJECT_H
#define OBJECT_H

#include "EventType.h"
#include "EventParameter.h"
#include "GetterSetterDefine.h"

//������ Ÿ�� ����
class ObjectManager;

/**

    @class   Object
    @brief   Time�� Console�� ������ ��� ������Ʈ���� �� Ŭ������ ��ӹ޴´�.
    @details ~

**/
class Object
{
public:
	virtual ~Object();

	virtual void OnEvent(const EventType& eventType, EventParameter& parameter);

 /**
     @brief  �Ŵ����� �Ҵ����ش�.
     @param manager - 
 **/
	void SetObjectManager(ObjectManager* manager);
	
	//getter setter
	GETTER_SETTER(Id, id, int);

protected:
	int id;	 //!< �� ��ü�� ���� ���̵� objectManager�� ���� �����ȴ�.
	ObjectManager* objectManager;  //!< ������Ʈ �Ŵ��� ������
};
#endif // !OBJECT_H