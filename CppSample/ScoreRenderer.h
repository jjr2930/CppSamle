#ifndef SCORE_RENDERER_H
#define SCORE_RENDERER_H

#include "Renderer.h"

/**

    @class   ScoreRenderer
    @brief   ���ھ ȭ�鿡 �׸��� ������Ʈ.
    @details ~

**/
class ScoreRenderer : public Renderer
{
public:
	ScoreRenderer();

	/*
	* ��ӹ��� �Լ���	
	*/
	virtual void OnEvent(const EventType& eventType, EventParameter& parameter);
	virtual void Render();
};

#endif // ! SCORE_DRAWER_H