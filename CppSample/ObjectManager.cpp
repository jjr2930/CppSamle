#include "ObjectManager.h"
#include "Entity.h"
#include "PooTransform.h"
#include "Renderer.h"
#include "PooSpawner.h"
#include "Const.h"
#include "PlayerTransform.h"
#include "FrameRenderer.h"
#include "ScoreCounter.h"
#include "ScoreRenderer.h"
#include "Collider.h"
#include "ColliderChecker.h"
#include "GameStateController.h"
#include "TypeEnums.h"


#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>

ObjectManager::ObjectManager()
	: objectMaps(128)
	, willBeDestroyedEntities(128)
	, nextId(0)
{
	willBeDestroyedEntities.clear();
}

ObjectManager::~ObjectManager()
{
	for (auto iter = objectMaps.begin(); iter != objectMaps.end();)
	{
		delete(iter->second);
		iter = objectMaps.erase(iter);
	}
}

void ObjectManager::Start()
{
	std::string filePath = "game.json";
	std::string json = "";
	// read File
	std::ifstream openFile(filePath.data());
	if( openFile.is_open() ){
		std::string line;
		while(std::getline(openFile, line)){
			json.append(line);
		}
		openFile.close();
	}
	else
	{
		std::cout << "can not open file : " << filePath << std::endl;
		_getch();
		exit(0);
	}

	doc.Parse(json.data());

	for (auto& sceneObjectJson : doc["gameSceneObjects"].GetArray())
	{
		auto& foundJson = GetPrefab(sceneObjectJson.GetString());
		BuildEntityFromJson(foundJson);
	}
}

void ObjectManager::Update()
{
	int* test = nullptr;
	delete test;
	

	for (auto iter = objectMaps.begin(); iter != objectMaps.end(); iter++)
	{
		auto component = dynamic_cast<Component*>(iter->second);
		if (nullptr == component)
			continue;

		component->OnUpdate();
	}

	for (auto iter = willBeDestroyedEntities.begin(); 
		iter != willBeDestroyedEntities.end();
		iter++)
	{
		DestroyEntity(*iter);
	}

	willBeDestroyedEntities.clear();
}

void ObjectManager::AddObject( Object* newObject)
{
	objectMaps.insert({ newObject->GetId(), newObject});
}

void ObjectManager::RemoveObject(const int id)
{
	auto found = objectMaps.find(id);
	if (found != objectMaps.end())
	{
		delete found->second;
		objectMaps.erase(found);
	}
}

ObjectMapIterator ObjectManager::RemoveObject(ObjectMapIterator iterator)
{
	if (iterator != objectMaps.end())
	{
		delete iterator->second;
		return objectMaps.erase(iterator);
	}

	return objectMaps.end();
}

void ObjectManager::DestroyEntity(const int& entityId)
{
	//remove entity
	RemoveObject(entityId);

	for (auto iter = objectMaps.begin(); iter != objectMaps.end(); ) 
	{
		auto castedComponent = dynamic_cast<Component*>(iter->second);
		if (nullptr == castedComponent)
		{
			iter++;
			continue;
		}

		if (entityId == castedComponent->GetOwnerId())
		{
			auto isPoo = dynamic_cast<PooTransform*>(castedComponent);
			if (nullptr != isPoo)
			{
				auto emptyEvent = EventParameter();
				OnEvent(EventType::PooDestroyed, emptyEvent);
			}

			iter = RemoveObject(iter);
		}
		else
			iter++;
	}
}

void ObjectManager::ReserveDestroy(const int& ownerId)
{
	willBeDestroyedEntities.push_back(ownerId);
}

void ObjectManager::OnEvent(const EventType event, EventParameter& parameter)
{
	for (auto iter = objectMaps.begin(); iter != objectMaps.end(); iter++)
	{
		iter->second->OnEvent(event, parameter);
	}
}

Entity* ObjectManager::GetNewEntity()
{
	Entity* newEntity = new Entity();
	newEntity->SetId(nextId++);
	newEntity->SetObjectManager(this);
	AddObject(newEntity);
	return newEntity;
}

void ObjectManager::AddComponent(Entity* entity, Component* newComponent)
{
	newComponent->SetOwnerId(entity->GetId());
}

void ObjectManager::RemoveComopnent(Entity* entity, Component* oldComponent) 
{
	// Compile-time check
	//static_assert(std::is_base_of<Component, T>::value, "type parameter of this class must derive from Component");
	
	//checking has
	auto id = oldComponent->GetId();
	auto found = objectMaps.find(id);
	if (found == objectMaps.end()) //not found
	{
		std::string errorMessage = "there is no ";
		errorMessage.append(std::to_string(id));
		throw std::out_of_range(errorMessage);
	}

	RemoveObject(id);
}

int ObjectManager::BuildEntityFromJson(const Value& jsonValue)
{
	auto newEntity = GetNewEntity();
	newEntity->Deserialize(jsonValue, doc);

	auto elements = jsonValue.FindMember("elements");
	for (auto& item : elements->value.GetArray()) 
	{
		std::string typeString(item.FindMember("type")->value.GetString());
		Types componentType = TypesUtils::ToTypes(typeString);

		Component* component = nullptr;

		switch (componentType)
		{
			case Types::Transform: component = GetNewComponent<Transform>(); break;
			case Types::Renderer: component = GetNewComponent<Renderer>(); break;
			case Types::Collider: component = GetNewComponent<Collider>(); break;
			case Types::PlayerTransform: component = GetNewComponent<PlayerTransform>(); break;
			case Types::PooTransform: component = GetNewComponent<PooTransform>(); break;
			case Types::PooSpawner:	component = GetNewComponent<PooSpawner>(); break;
			case Types::ScoreCounter: component = GetNewComponent<ScoreCounter>(); break;
			case Types::ScoreRenderer: component = GetNewComponent<ScoreRenderer>(); break;
			case Types::ColliderChecker: component = GetNewComponent<ColliderChecker>(); break;
			case Types::FrameRenderer: component = GetNewComponent<FrameRenderer>(); break;
			case Types::GameStateController: component = GetNewComponent<GameStateController>(); break;
			default:
				{
					std::string message = typeString;
					message.append(" is not supported");
					throw message;
				}
		}

		component->Deserialize(item, doc);
		AddComponent(newEntity, component);
	}

	return newEntity->GetId();
}

Value& ObjectManager::GetPrefab(const std::string& name)
{
	auto& prefabs = doc["prefabs"];
	for (auto& member : prefabs.GetArray())
	{
		if (0 == strcmp(member["name"].GetString(), name.c_str())) 
		{
			return member;
		}
	}
	
	throw "not found " + name;
}