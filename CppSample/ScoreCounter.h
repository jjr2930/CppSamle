#ifndef SCORE_COUNTER_H
#define SCORE_COUNTER_H

#include "Component.h"

/**
    @class   ScoreCounter
    @brief   스코어를 계산하는 컴포넌트
    @details ~
**/
class ScoreCounter : public Component
{
public :
	ScoreCounter();

 /**
     @brief 똥이 파괴되었다는 이벤트가 들어오면 스코어를 올리는 행위를 하며, 스코어가 변경되면 이벤트를 방출한다.
     @param eventType - 전달된 이벤트 타입
     @param parameter - 이벤트 타입과 작지어진 파라미터
 **/
	virtual void OnEvent(const EventType& eventType, EventParameter& parameter);

private:
	int score;  //!< 현재 스코어를 이곳에 저장한다.
};

#endif // !SCORE_COUNTER