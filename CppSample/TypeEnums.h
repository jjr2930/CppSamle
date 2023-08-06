#ifndef TYPE_ENUMS_H
#define TYPE_ENUMS_H

#include <string>
#include <unordered_map>

#include "CommonDefineMethod.h"
#include <stdexcept>

/**
    @enum		Types
    @brief		������ȭ�� �� �������� ��ȯ ���Ѿ����� ��Ȯ�� �ϱ� ����, Ÿ���� enum���� �����Ѵ�. game.json�� �� �̸����� �����ְ�, �̰��� �̿��ؼ� ������ȭ�� ���δ�.
**/
enum class Types
{
	Error = -1,
	Entity,
	Transform,
	Renderer,
	Collider,
	PlayerTransform,
	PooTransform,
	PooSpawner,
	ScoreCounter,
	ScoreRenderer,
	ColliderChecker,
	FrameRenderer,
	GameStateController,
};

/**
    @namespace TypesUtils
    @brief     ������Ǹ� ���� �̷��� �����Ѵ�.
	@details	Types�� ���õ� ��ƿ��Ƽ �Լ����� ����ִ�, enum -> string, string -> enum �� ���� unordered map 2���� ���ǵǾ� ������, enum -> string, string -> enum �� ���ִ� �Լ� 2���� �ִ�.
**/
namespace TypesUtils
{
	std::unordered_map<Types, std::string> typeToString			 //!< enum�� value���� string�� �����Ѵ�.
	{
		ENUM_TO_STRING_MAP(Types, Entity)
		ENUM_TO_STRING_MAP(Types, Transform)
		ENUM_TO_STRING_MAP(Types, Renderer)
		ENUM_TO_STRING_MAP(Types, Collider)
		ENUM_TO_STRING_MAP(Types, PlayerTransform)
		ENUM_TO_STRING_MAP(Types, PooTransform)
		ENUM_TO_STRING_MAP(Types, PooSpawner)
		ENUM_TO_STRING_MAP(Types, ScoreCounter)
		ENUM_TO_STRING_MAP(Types, ScoreRenderer)
		ENUM_TO_STRING_MAP(Types, ColliderChecker)
		ENUM_TO_STRING_MAP(Types, FrameRenderer)
		ENUM_TO_STRING_MAP(Types, GameStateController)
	};

	std::unordered_map<std::string, Types> stringToType			 //!< string�� �´� enum�� �����Ѵ�.
	{
		STRING_TO_ENUM_MAP(Types, Entity)
		STRING_TO_ENUM_MAP(Types, Transform)
		STRING_TO_ENUM_MAP(Types, Renderer)
		STRING_TO_ENUM_MAP(Types, Collider)
		STRING_TO_ENUM_MAP(Types, PlayerTransform)
		STRING_TO_ENUM_MAP(Types, PooTransform)
		STRING_TO_ENUM_MAP(Types, PooSpawner)
		STRING_TO_ENUM_MAP(Types, ScoreCounter)
		STRING_TO_ENUM_MAP(Types, ScoreRenderer)
		STRING_TO_ENUM_MAP(Types, ColliderChecker)
		STRING_TO_ENUM_MAP(Types, FrameRenderer)
		STRING_TO_ENUM_MAP(Types, GameStateController)
	};

 /**
     @brief  �־��� source�� �̿��ؼ� enum�� �´� string�� ã�� �����Ѵ�. ������ ������ ������ ���ܸ� ������.
     @param  source - string�� ã����� enum
     @retval        - ã�� string�� �����Ѵ�.
 **/
	std::string ToString(const Types& source)
	{
		auto found = typeToString.find(source);
		if (found == typeToString.end())
		{
			std::string message;
			message.append(std::to_string((int)source));
			message.append("not in string to type map");
			throw std::invalid_argument(message);
		}

		return found->second;
	}

 /**
     @brief  �־��� ���ڿ��� source�� �̿��Ͽ� �׿� �´� Types�� enum value�� ã�� �����Ѵ�. ������ � source�� ����ߴ��� ���ܷ� �˷��ش�.
     @param  source - ã����� ���ڿ�
     @retval        - ã�Ҵٸ� ã�� Types�� ���� �����Ѵ�.
 **/
	Types ToTypes(const std::string& source) 
	{
		auto found = stringToType.find(source);
		if (found == stringToType.end())
		{
			std::string message;
			message.append(source);
			message.append(" not in string to type map");
			throw std::invalid_argument(message);
		}

		return found->second;
	}
}
#endif // !TYPE_ENUMS

