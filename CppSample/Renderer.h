#ifndef RENDERER_H
#define RENDERER_H

#include <string>

#include "Component.h"
#include "Vector2Int.h"
#include "GetterSetterDefine.h"

/**
    @class   Renderer
    @brief   콘솔화면에 무언가를 그리는 컴포넌트이다.
    @details ~
**/

class Renderer : public Component
{
public :
	Renderer();
	Renderer(const std::string& character);
	virtual ~Renderer();
	
	virtual void Render();

	GETTER_SETTER(What, what, std::string);

	/*
	* 상속받은 함수들의 구현을 하기위해 선언
	*/
	virtual void OnUpdate();
	virtual void OnEvent(const EventType& eventType, EventParameter& parameter);

	virtual void Serialize(rapidjson::Value& parent, rapidjson::Document& document);
	virtual void Deserialize(const rapidjson::Value& source, rapidjson::Document& document);	

protected :
	Vector2Int renderPosition;		//!< 그릴 때의 위치가 여기에 저장되어있다.
	std::string what;				//!< 무언가를 그릴지 여기에 저장되어있다.
};

#endif // !RENDERER_H
