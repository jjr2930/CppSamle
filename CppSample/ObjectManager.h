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
    @brief   생성되는 모든 오브젝트를 관리하는 크래스이다.
    @details ~이 클래스의 역할은 
	1. 오브젝트(엔티티, 컴포넌트)가 생성한 이벤트를 다른 오브젝트들에게 전달하는 역할
	2. 오브젝트의 생성과 추가와 관련된 인터페이스 제공
	3. game json을 읽어 Prefab(완성된 조각)과 gameScene을 구성하는 오브젝트를 생성한다.
**/
class ObjectManager
{
public :
	ObjectManager();
	~ObjectManager();
	
 /**
     @brief game.json을 읽어 게임화면을 구성한다.
 **/
	void Start();
 /**
     @brief 모든 오브젝트들의 update문을 호출한다.
 **/
	void Update();	
 /**
     @brief 오브젝트 맵에 손쉽게 추가하기 위한 메소드
     @param newObject - 새로 추가할 오브젝트
 **/
	void AddObject(Object* newObject);
 /**
     @brief 아이디를 이용하여 오브젝트를 지운다.
     @param id - 지울 오브젝트의 아이디
 **/
	void RemoveObject(const int id);
 /**
     @brief  ObjectMap의 Iterator를 통해 오브젝트를 지운다.
     @param  iterator - 지울 위치를 가르키는 Iterator
     @retval          - 지웠으면 다음 Iterator, 지우는데 실패했으면 objectMap.end() Iterator를 리턴한다.
 **/
	ObjectMapIterator RemoveObject(ObjectMapIterator iterator);
 /**
     @brief 엔티티의 아이디를 통해 엔티티와 엔티티를 가르키는 컴포넌트를 모두 지운다.
     @param entityId - 지울 엔티티의 아이디
 **/
	void DestroyEntity(const int& entityId);
 /**
     @brief Update 종료 후 지울 엔티티 아이디를 등록한다.
     @param ownerId - 엔티티 아이디
 **/
	void ReserveDestroy(const int& ownerId);
 /**
     @brief 어떠한 Object로부터 전달받은 이벤트를 다른 모든 오브젝트들에게 전달한다.
     @param event     - 전달하는 이벤트 타입
     @param parameter - 이벤트 타입과 짝을 이루는 이벤트의 자세한 내용이 담긴 데이터
 **/
	void OnEvent(const EventType event, EventParameter& parameter);
 /**
     @brief  새로운 엔티티를 만들고 그것의 포인터를 얻어온다.
     @retval  - 새로 만들어진 엔티티의 포인터
 **/
	Entity* GetNewEntity();	
 /**
     @brief 컴포넌트가 엔티티를 가르키도록 한다.
     @param entity       - 가르키게 하고 싶은 엔티티
     @param newComponent - 지정해줄 컴포넌트
 **/
	void AddComponent(Entity* entity, Component* newComponent);		
 /**
     @brief 컴포넌트가 어느 엔티티도 가르키지 않도록 한다.
     @param entity       - 가르키는 것을 취소할 엔티티.(엔티티가 있는지 확인을 위해 필요하다.)
     @param oldComponent - 지정할 컴포넌트
 **/
	void RemoveComopnent(Entity* entity, Component* oldComponent);	
 /**
     @brief  rapidjson::Value 를 이용해서 엔티티와 엔티티를 가르키는 컴포넌트를 생성한다.
     @param  jsonValue - 생성하는데 사용할 rapidjson::Value 객체
     @retval           - 생성된 엔티티의 아이디
 **/
	int BuildEntityFromJson(const Value& jsonValue);
 /**
     @brief  프리팹(미리 정의된 게임 구성요소 객체)정보를 이름으로 얻어온다.
     @param  name - 얻어오고 싶은 프리팹의 이름
     @retval      - 찾은 rapidjson::Value 객체
 **/
	Value& GetPrefab(const std::string& name);

 /**
     @brief 엔티티를 가르키는 컴포넌트 하나를 얻어온다.
     @tparam T      - Component를 상속받은 타입
     @param  entity - 엔티티
     @retval        - 찾았다면 찾은 Component를 리턴 찾지 못하면 nullptr
 **/
	template <class T>
	T* GetComponent(Entity* entity)
	{
		return GetComponent(entity->GetId());
	}

 /**
     @brief 엔티티의 아이디를 이용해서 컴포넌트 하나를 얻어온다.
     @tparam T  - 가져오길 원하는 Component 타입
     @param  id - 찾고싶은 컴포넌트가 가르키는 엔티티의 아이디
     @retval    - 찾았다면 Component를 리턴, 그렇지 않으면 nullptr
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
     @brief  게임내에 존재하는 모든 T타입의 컴포넌트들을 얻어온다.
     @tparam T - Component를 상속받은 타입
     @retval   - 찾은 모든 Component들이 들어있는 벡터를 리턴한다.
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
     @brief  새로운 컴포넌트를 만들고 그것을 objectMap에 등록한후 리턴한다.
     @tparam T - Component를 상속받은 타입 T
     @retval   - 새로 만들어진 컴포넌트를 리턴한다.
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
	Document doc;	 //!< game.json을 파싱한 json document, getprefab에 쓰인다.
	std::unordered_map<int, Object*> objectMaps;	 //!< 등록된 오브젝트들을 아이디를 이용하여 가지고 있다.
	std::vector<int> willBeDestroyedEntities; //!< update후 지울 엔티티들이 들어있다.
	int nextId;	 //!< Object에 아이디를 부여할 때, 이 숫자를 사용한다.
};


#endif //!OBJECT_MANAGER_H