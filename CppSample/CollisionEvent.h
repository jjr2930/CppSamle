#ifndef COLLISION_EVENT_H
#define COLLISION_EVENT_H

#include "EventParameter.h"
#include "Collider.h"
#include "Vector2Int.h"

/**

    @class   CollisionEvent
    @brief   �浹�ߴٴ� �̺�Ʈ ���޿� ���� �̺�Ʈ ������(�Ķ����)
    @details ~

**/
class CollisionEvent : public EventParameter
{
public:
	Vector2Int collisionPosition;	 //!< �浹�� ��ġ
	Collider* colliderA;	 //!< �浹�� ��ü a
	Collider* colliderB;	 //!< �浹�� ��ü b
};
#endif // !COLLISION_EVENT

