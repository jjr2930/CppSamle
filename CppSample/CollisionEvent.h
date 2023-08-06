#ifndef COLLISION_EVENT_H
#define COLLISION_EVENT_H

#include "EventParameter.h"
#include "Collider.h"
#include "Vector2Int.h"

/**

    @class   CollisionEvent
    @brief   충돌했다는 이벤트 전달에 쓰일 이벤트 데이터(파라미터)
    @details ~

**/
class CollisionEvent : public EventParameter
{
public:
	Vector2Int collisionPosition;	 //!< 충돌된 위치
	Collider* colliderA;	 //!< 충돌한 물체 a
	Collider* colliderB;	 //!< 충돌한 물체 b
};
#endif // !COLLISION_EVENT

