#ifndef OBJECT_MANAGER_H
#define OBJECT_MANAGER_H

#include <string>
#include <unordered_map>

#include "EventParameter.h"
#include "Entity.h"
#include "Component.h"
#include "EventType.h"

using namespace rapidjson;
using ObjectMapIterator = std::unordered_map<int, Object*>::iterator;

/**

    @class   ObjectManager
    @brief   �����Ǵ� ��� ������Ʈ�� �����ϴ� ũ�����̴�.
    @details ~�� Ŭ������ ������ 
	1. ������Ʈ(��ƼƼ, ������Ʈ)�� ������ �̺�Ʈ�� �ٸ� ������Ʈ�鿡�� �����ϴ� ����
	2. ������Ʈ�� ������ �߰��� ���õ� �������̽� ����
	3. game json�� �о� Prefab(�ϼ��� ����)�� gameScene�� �����ϴ� ������Ʈ�� �����Ѵ�.
**/
class ObjectManager
{
public :
	ObjectManager();
	~ObjectManager();
	
 /**
     @brief game.json�� �о� ����ȭ���� �����Ѵ�.
 **/
	void Start();
 /**
     @brief ��� ������Ʈ���� update���� ȣ���Ѵ�.
 **/
	void Update();	
 /**
     @brief ������Ʈ �ʿ� �ս��� �߰��ϱ� ���� �޼ҵ�
     @param newObject - ���� �߰��� ������Ʈ
 **/
	void AddObject(Object* newObject);
 /**
     @brief ���̵� �̿��Ͽ� ������Ʈ�� �����.
     @param id - ���� ������Ʈ�� ���̵�
 **/
	void RemoveObject(const int id);
 /**
     @brief  ObjectMap�� Iterator�� ���� ������Ʈ�� �����.
     @param  iterator - ���� ��ġ�� ����Ű�� Iterator
     @retval          - �������� ���� Iterator, ����µ� ���������� objectMap.end() Iterator�� �����Ѵ�.
 **/
	ObjectMapIterator RemoveObject(ObjectMapIterator iterator);
 /**
     @brief ��ƼƼ�� ���̵� ���� ��ƼƼ�� ��ƼƼ�� ����Ű�� ������Ʈ�� ��� �����.
     @param entityId - ���� ��ƼƼ�� ���̵�
 **/
	void DestroyEntity(const int& entityId);
 /**
     @brief Update ���� �� ���� ��ƼƼ ���̵� ����Ѵ�.
     @param ownerId - ��ƼƼ ���̵�
 **/
	void ReserveDestroy(const int& ownerId);
 /**
     @brief ��� Object�κ��� ���޹��� �̺�Ʈ�� �ٸ� ��� ������Ʈ�鿡�� �����Ѵ�.
     @param event     - �����ϴ� �̺�Ʈ Ÿ��
     @param parameter - �̺�Ʈ Ÿ�԰� ¦�� �̷�� �̺�Ʈ�� �ڼ��� ������ ��� ������
 **/
	void OnEvent(const EventType event, EventParameter& parameter);
 /**
     @brief  ���ο� ��ƼƼ�� ����� �װ��� �����͸� ���´�.
     @retval  - ���� ������� ��ƼƼ�� ������
 **/
	Entity* GetNewEntity();	
 /**
     @brief ������Ʈ�� ��ƼƼ�� ����Ű���� �Ѵ�.
     @param entity       - ����Ű�� �ϰ� ���� ��ƼƼ
     @param newComponent - �������� ������Ʈ
 **/
	void AddComponent(Entity* entity, Component* newComponent);		
 /**
     @brief ������Ʈ�� ��� ��ƼƼ�� ����Ű�� �ʵ��� �Ѵ�.
     @param entity       - ����Ű�� ���� ����� ��ƼƼ.(��ƼƼ�� �ִ��� Ȯ���� ���� �ʿ��ϴ�.)
     @param oldComponent - ������ ������Ʈ
 **/
	void RemoveComopnent(Entity* entity, Component* oldComponent);	
 /**
     @brief  rapidjson::Value �� �̿��ؼ� ��ƼƼ�� ��ƼƼ�� ����Ű�� ������Ʈ�� �����Ѵ�.
     @param  jsonValue - �����ϴµ� ����� rapidjson::Value ��ü
     @retval           - ������ ��ƼƼ�� ���̵�
 **/
	int BuildEntityFromJson(const Value& jsonValue);
 /**
     @brief  ������(�̸� ���ǵ� ���� ������� ��ü)������ �̸����� ���´�.
     @param  name - ������ ���� �������� �̸�
     @retval      - ã�� rapidjson::Value ��ü
 **/
	Value& GetPrefab(const std::string& name);

 /**
     @brief ��ƼƼ�� ����Ű�� ������Ʈ �ϳ��� ���´�.
     @tparam T      - Component�� ��ӹ��� Ÿ��
     @param  entity - ��ƼƼ
     @retval        - ã�Ҵٸ� ã�� Component�� ���� ã�� ���ϸ� nullptr
 **/
	template <class T>
	T* GetComponent(Entity* entity)
	{
		return GetComponent(entity->GetId());
	}

 /**
     @brief ��ƼƼ�� ���̵� �̿��ؼ� ������Ʈ �ϳ��� ���´�.
     @tparam T  - �������� ���ϴ� Component Ÿ��
     @param  id - ã����� ������Ʈ�� ����Ű�� ��ƼƼ�� ���̵�
     @retval    - ã�Ҵٸ� Component�� ����, �׷��� ������ nullptr
 **/
	template<class T>
	T* GetComponent(const int& id) 
	{
		static_assert(std::is_base_of<Component, T>::value, "type parameter of this class must derive from Component");

		//found
		for (auto iter = objectMaps.begin(); iter != objectMaps.end(); iter++)
		{
			auto targetTypeCheck = dynamic_cast<T*>(iter->second);
			if (nullptr == targetTypeCheck)
				continue;

			auto componentCasted = dynamic_cast<Component*>(iter->second);
			if (id == componentCasted->GetOwnerId())
				return targetTypeCheck;
		}

		return nullptr;
	}

 /**
     @brief  ���ӳ��� �����ϴ� ��� TŸ���� ������Ʈ���� ���´�.
     @tparam T - Component�� ��ӹ��� Ÿ��
     @retval   - ã�� ��� Component���� ����ִ� ���͸� �����Ѵ�.
 **/
	template<class T>
	std::vector<T*> GetComponents() 
	{
		static_assert(std::is_base_of<Component, T>::value, "type parameter of this class must derive from Component");

		//get all entity's component
		std::vector<T*> components;

		//found
		for (auto iter = objectMaps.begin(); iter != objectMaps.end(); iter++)
		{
			auto targetTypeCheck = dynamic_cast<T*>(iter->second);
			if (nullptr == targetTypeCheck)
				continue;

			components.push_back(targetTypeCheck);
		}

		return components;
	}
	
 /**
     @brief  ���ο� ������Ʈ�� ����� �װ��� objectMap�� ������� �����Ѵ�.
     @tparam T - Component�� ��ӹ��� Ÿ�� T
     @retval   - ���� ������� ������Ʈ�� �����Ѵ�.
 **/
	template<class T>
	T* GetNewComponent()
	{

		static_assert(std::is_base_of<Component, T>::value, "type parameter of this class must derive from Component");

		auto newComponent = dynamic_cast<Component*>(new T());
		newComponent->SetId(nextId++);
		newComponent->SetObjectManager(this);
		objectMaps.insert({ newComponent->GetId(), newComponent });

		return dynamic_cast<T*>(newComponent);
	}
	

private:
	Document doc;	 //!< game.json�� �Ľ��� json document, getprefab�� ���δ�.
	std::unordered_map<int, Object*> objectMaps;	 //!< ��ϵ� ������Ʈ���� ���̵� �̿��Ͽ� ������ �ִ�.
	std::vector<int> willBeDestroyedEntities; //!< update�� ���� ��ƼƼ���� ����ִ�.
	int nextId;	 //!< Object�� ���̵� �ο��� ��, �� ���ڸ� ����Ѵ�.
};


#endif //!OBJECT_MANAGER_H