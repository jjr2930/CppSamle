#ifndef PLAYER_TRANSFORM_H
#define PLAYER_TRANSFORM_H

#include "Transform.h"

/**
    @class   PlayerTransform
    @brief   플레이어의 위치를 컨트롤하기 위한 클래스이다.
    @details ~
**/

class PlayerTransform : public Transform
{
public:	
	//inherited functions
	virtual void OnStart() override;
	virtual void OnEvent(const EventType& eventType, EventParameter& parameter) override;

 /**
     @brief 좌표를 제한 범위 안에 가둔다.
 **/
	void ClampPosition();
};

#endif // !PLAYER_TRANSFORM_H
