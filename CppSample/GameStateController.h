#ifndef GAME_STATE_CONTROLLER_H
#define GAME_STATE_CONTROLLER_H

#include "Component.h"

/**

    @class   GameStateController
    @brief   ���� ���¸� �����Ѵ�. ����� �������� ������ ���� ���°� �ִ�.
    @details ~

**/
class GameStateController : public Component
{
public:

	/*
    * ��ӹ��� �Լ�
    */

 /**
     @brief Collided �̺�Ʈ�� �޾Ƽ� �÷��̾ �˰� �浹�� ���̸� ������ �����Ű�� ���·� ��ȯ�Ѵ�.
     @param eventType - ���� ���� �̺�Ʈ Ÿ��
     @param parameter - �̺�Ʈ Ÿ�԰� ¦�� �̷�� �̺�Ʈ�� ������
 **/
	virtual void OnEvent(const EventType& eventType, EventParameter& parameter);
};


#endif // !GAME_STATE_CONTROLLER