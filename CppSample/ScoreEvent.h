#ifndef SCORE_EVENT_H
#define SCORE_EVENT_H

#include "EventParameter.h"

/**

    @class   ScoreEvent
    @brief   ������ ����Ǿ��ٴ� �̺�Ʈ ���޿� ���� �Ķ����
    @details ~

**/
class ScoreEvent : public EventParameter
{
public:
	int score;   //!< ����� ����
};
#endif // !SCORE_EVENT_H