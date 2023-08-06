#ifndef TYPE_ENUMS_H
#define TYPE_ENUMS_H

#include <string>
#include <unordered_map>

#include "CommonDefineMethod.h"
#include <stdexcept>

/**
    @enum		Types
    @brief		역직렬화할 때 무엇으로 변환 시켜야할지 명확히 하기 위해, 타입을 enum으로 정의한다. game.json에 이 이름들이 적혀있고, 이것을 이용해서 역직렬화에 쓰인다.
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
    @brief     사용편의를 위해 이렇게 정의한다.
	@details	Types와 관련된 유틸리티 함수들이 들어있다, enum -> string, string -> enum 을 위한 unordered map 2개가 정의되어 있으며, enum -> string, string -> enum 을 해주는 함수 2개가 있다.
**/
namespace TypesUtils
{
	std::unordered_map<Types, std::string> typeToString			 //!< enum의 value별로 string을 정의한다.
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

	std::unordered_map<std::string, Types> stringToType			 //!< string에 맞는 enum을 정의한다.
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
     @brief  주어진 source를 이용해서 enum에 맞는 string을 찾고 리턴한다. 없으면 무엇이 없는지 예외를 던진다.
     @param  source - string을 찾고싶은 enum
     @retval        - 찾은 string을 리턴한다.
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
     @brief  주어진 문자열인 source을 이용하여 그에 맞는 Types의 enum value를 찾아 리턴한다. 없으면 어떤 source를 사용했는지 예외로 알려준다.
     @param  source - 찾고싶은 문자열
     @retval        - 찾았다면 찾은 Types의 값을 리턴한다.
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

