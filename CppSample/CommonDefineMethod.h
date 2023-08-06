#ifndef COMMON_DEFINE_METHOD_H
#define COMMON_DEFINE_METHOD_H

/*
* ���� ��� �ξ�� �� �� ������ ���� define���� �̰��� �д�.
*/

/**
    @def   DEQUEUE
    @brief ť���� front�� ����Ű�� �κ��� ���� �������� pop�Ѵ�. C# Queue.Dequeue�� �䳻������.
    @param QUEUE - Dequeue�� ť ��ü
**/
#define DEQUEUE(QUEUE) QUEUE.front(); QUEUE.pop();

/**
    @def   ENUM_TO_STRING_MAP
    @brief {enum::value, string} pair�� map�� �ִ� define �Լ��̴�.
    @param ENUM       - enum Ÿ��
    @param ENUM_VALUE - enum ��
**/
#define ENUM_TO_STRING_MAP(ENUM,ENUM_VALUE) {ENUM::ENUM_VALUE,#ENUM_VALUE},

/**
    @def   STRING_TO_ENUM_MAP
    @brief {string, enum::value} pair�� map�� �ִ� define �Լ��̴�.
    @param ENUM       - enum Ÿ��
    @param ENUM_VALUE - enum ��
**/
#define STRING_TO_ENUM_MAP(ENUM,ENUM_VALUE) {#ENUM_VALUE,ENUM::ENUM_VALUE},

#endif // !COMMON_DEFINE_METHOD_H