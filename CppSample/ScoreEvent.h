#ifndef SCORE_EVENT_H
#define SCORE_EVENT_H

#include "EventParameter.h"

/**

    @class   ScoreEvent
    @brief   점수가 변경되었다는 이벤트 전달에 쓰일 파라미터
    @details ~

**/
class ScoreEvent : public EventParameter
{
public:
	int score;   //!< 변경된 점수
};
#endif // !SCORE_EVENT_H