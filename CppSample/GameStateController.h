#ifndef GAME_STATE_CONTROLLER_H
#define GAME_STATE_CONTROLLER_H

#include "Component.h"

/**

    @class   GameStateController
    @brief   게임 상태를 제어한다. 현재는 종료할지 말지에 대한 상태가 있다.
    @details ~

**/
class GameStateController : public Component
{
public:

	/*
    * 상속받은 함수
    */

 /**
     @brief Collided 이벤트를 받아서 플레이어가 똥과 충돌한 것이면 게임을 종료시키는 상태로 전환한다.
     @param eventType - 전달 받은 이벤트 타입
     @param parameter - 이벤트 타입과 짝을 이루는 이벤트의 데이터
 **/
	virtual void OnEvent(const EventType& eventType, EventParameter& parameter);
};


#endif // !GAME_STATE_CONTROLLER