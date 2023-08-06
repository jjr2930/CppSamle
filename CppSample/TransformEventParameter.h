#ifndef TRANSFORM_EVENT_PARAMETER_H
#define TRANSFORM_EVENT_PARAMETER_H

#include "EventParameter.h"
#include "Vector2Int.h"

/**

    @class   TransformEventParameter
    @brief   Transform이 변경되었다는 이벤트를 발생시킬 때 필요한 정보가 정의되어있다.
    @details ~

**/
class TransformEventParameter : public EventParameter
{
public:
	int entity;  //!< 이 이벤트를 발생시킨 Transform의 owner의 아이디가 들어있다.
	Vector2Int position;  //!< 변경된 위치를 이 멤버 변수에 담는다.
};

#endif // !TRANSFORM_EVENT_PARAMETER_H