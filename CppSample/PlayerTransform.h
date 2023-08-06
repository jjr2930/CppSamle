#ifndef PLAYER_TRANSFORM_H
#define PLAYER_TRANSFORM_H

#include "Transform.h"

/**
    @class   PlayerTransform
    @brief   �÷��̾��� ��ġ�� ��Ʈ���ϱ� ���� Ŭ�����̴�.
    @details ~
**/

class PlayerTransform : public Transform
{
public:	
	//inherited functions
	virtual void OnStart() override;
	virtual void OnEvent(const EventType& eventType, EventParameter& parameter) override;

 /**
     @brief ��ǥ�� ���� ���� �ȿ� ���д�.
 **/
	void ClampPosition();
};

#endif // !PLAYER_TRANSFORM_H
