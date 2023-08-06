#ifndef RENDERER_H
#define RENDERER_H

#include <string>

#include "Component.h"
#include "Vector2Int.h"
#include "GetterSetterDefine.h"

/**
    @class   Renderer
    @brief   �ܼ�ȭ�鿡 ���𰡸� �׸��� ������Ʈ�̴�.
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
	* ��ӹ��� �Լ����� ������ �ϱ����� ����
	*/
	virtual void OnUpdate();
	virtual void OnEvent(const EventType& eventType, EventParameter& parameter);

	virtual void Serialize(rapidjson::Value& parent, rapidjson::Document& document);
	virtual void Deserialize(const rapidjson::Value& source, rapidjson::Document& document);	

protected :
	Vector2Int renderPosition;		//!< �׸� ���� ��ġ�� ���⿡ ����Ǿ��ִ�.
	std::string what;				//!< ���𰡸� �׸��� ���⿡ ����Ǿ��ִ�.
};

#endif // !RENDERER_H
