#ifndef COMMON_DEFINE_METHOD_H
#define COMMON_DEFINE_METHOD_H

/*
* 딱히 어디에 두어야 할 지 정하지 못한 define들을 이곳에 둔다.
*/

/**
    @def   DEQUEUE
    @brief 큐에서 front가 가르키는 부분의 값을 가져오고 pop한다. C# Queue.Dequeue를 흉내내었다.
    @param QUEUE - Dequeue할 큐 객체
**/
#define DEQUEUE(QUEUE) QUEUE.front(); QUEUE.pop();

/**
    @def   ENUM_TO_STRING_MAP
    @brief {enum::value, string} pair를 map에 넣는 define 함수이다.
    @param ENUM       - enum 타입
    @param ENUM_VALUE - enum 값
**/
#define ENUM_TO_STRING_MAP(ENUM,ENUM_VALUE) {ENUM::ENUM_VALUE,#ENUM_VALUE},

/**
    @def   STRING_TO_ENUM_MAP
    @brief {string, enum::value} pair를 map에 넣는 define 함수이다.
    @param ENUM       - enum 타입
    @param ENUM_VALUE - enum 값
**/
#define STRING_TO_ENUM_MAP(ENUM,ENUM_VALUE) {#ENUM_VALUE,ENUM::ENUM_VALUE},

#endif // !COMMON_DEFINE_METHOD_H