#ifndef TRANSFORM_EVENT_PARAMETER_H
#define TRANSFORM_EVENT_PARAMETER_H

#include "EventParameter.h"
#include "Vector2Int.h"

/**

    @class   TransformEventParameter
    @brief   Transform�� ����Ǿ��ٴ� �̺�Ʈ�� �߻���ų �� �ʿ��� ������ ���ǵǾ��ִ�.
    @details ~

**/
class TransformEventParameter : public EventParameter
{
public:
	int entity;  //!< �� �̺�Ʈ�� �߻���Ų Transform�� owner�� ���̵� ����ִ�.
	Vector2Int position;  //!< ����� ��ġ�� �� ��� ������ ��´�.
};

#endif // !TRANSFORM_EVENT_PARAMETER_H