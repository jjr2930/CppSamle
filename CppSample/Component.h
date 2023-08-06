#ifndef COMPONENT_H
#define COMPONENT_H

#include "SerialiazableObject.h"
#include "GetterSetterDefine.h"

/**

    @class   Component
    @brief   ��� ������Ʈ���� �θ� Ŭ����, ��� ������Ʈ���� �̰��� ��ӹ޾ƾ� �Ѵ�.
    @details ~

**/
class Component : public SerialiazableObject
{
public:
	Component();
	virtual ~Component();

	//inherited functions
 /**
     @brief ������Ʈ �ϱ� �� �� �� �� �� �����Ѵ�.
 **/
	virtual void OnStart();
 /**
     @brief �� ������ ����Ǵ� �Լ�, �ڽ��� ���� ������Ʈ �ϱ� ���� ���ȴ�.
 **/
	virtual void OnUpdate();

	virtual void Serialize(rapidjson::Value& parent, rapidjson::Document& document);
	virtual void Deserialize(const rapidjson::Value& source, rapidjson::Document& document);

	//getter setter
	GETTER_SETTER(OwnerId, ownerId, int);

protected :
	int ownerId;	 //!< �� ������Ʈ�� ���� ��ƼƼ�� ���̵�
	bool isInit;	 //!< OnStart �Լ��� �� �� ȣ�� �Ǿ����� ���ΰ� �� ������ �ִ�.
};

#endif // !COPONENT