#ifndef SCORE_RENDERER_H
#define SCORE_RENDERER_H

#include "Renderer.h"

/**

    @class   ScoreRenderer
    @brief   스코어를 화면에 그리는 컴포넌트.
    @details ~

**/
class ScoreRenderer : public Renderer
{
public:
	ScoreRenderer();

	/*
	* 상속받은 함수들	
	*/
	virtual void OnEvent(const EventType& eventType, EventParameter& parameter);
	virtual void Render();
};

#endif // ! SCORE_DRAWER_H