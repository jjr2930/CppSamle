#ifndef EVENT_TYPE_H
#define EVENT_TYPE_H

/**
    @enum  EventType
    @brief 게임에 사용되는 모든 이벤트를 정의한다.
**/
enum class EventType
{
	TransformChanged,
	KeyInputted,
	Collided,
	PooDestroyed,
	ScoreChanged,
};
#endif

