#ifndef SCORE_COUNTER_H
#define SCORE_COUNTER_H

#include "Component.h"

/**
    @class   ScoreCounter
    @brief   ���ھ ����ϴ� ������Ʈ
    @details ~
**/
class ScoreCounter : public Component
{
public :
	ScoreCounter();

 /**
     @brief ���� �ı��Ǿ��ٴ� �̺�Ʈ�� ������ ���ھ �ø��� ������ �ϸ�, ���ھ ����Ǹ� �̺�Ʈ�� �����Ѵ�.
     @param eventType - ���޵� �̺�Ʈ Ÿ��
     @param parameter - �̺�Ʈ Ÿ�԰� �������� �Ķ����
 **/
	virtual void OnEvent(const EventType& eventType, EventParameter& parameter);

private:
	int score;  //!< ���� ���ھ �̰��� �����Ѵ�.
};

#endif // !SCORE_COUNTER