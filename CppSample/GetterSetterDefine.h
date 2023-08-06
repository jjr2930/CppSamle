#ifndef GETTER_SETTER_DEFINE_H
#define GETTER_SETTER_DEFINE_H

/*
* 간단한 getter와 setter를 만들기 위해 선언한 define 함수들
*/

/**
    @def   GETTER
    @brief 간단한 getter를 만들어준다.
    @param FUNCTION_NAME - getter가 사용할 함수의 이름 GetFUNCTION_NAME 로 지어진다.
    @param MEMBER_NAME   - getter함수에 쓰일 멤버 변수 이름 
    @param TYPE          - 멤버변수의 타입이름
**/
#define GETTER(FUNCTION_NAME, MEMBER_NAME,TYPE) \
TYPE Get ##FUNCTION_NAME() const { return MEMBER_NAME; }

/**
    @def   SETTER
    @brief 간단한 setter를 만들어준다.
    @param FUNCTION_NAME - setter가 사용할 함수의 이름 SetFUNCTION_NAME 로 지어진다.
    @param MEMBER_NAME   - setter함수에 쓰일 멤버 변수 이름 
    @param TYPE          - 멤버변수의 타입이름
**/
#define SETTER(FUNCTION_NAME, MEMBER_NAME,TYPE) \
void Set ##FUNCTION_NAME(const TYPE& value) { MEMBER_NAME = value;}

/**
    @def   GETTER_SETTER
    @brief 앞서 정의된 GETTER와 SETTER define을 통해 getter 와 setter를 만들어 준다.
    @param FUNCTION_NAME - getter와 setter에 사용할 함수 이름, GETTER, SETTER 참고,
    @param MEMBER_NAME   - 함수에 쓰일 멤버 변수의 이름
    @param TYPE          - 멤버 변수의 타입 이름
**/
#define GETTER_SETTER(FUNCTION_NAME, MEMBER_NAME, TYPE)\
GETTER(FUNCTION_NAME, MEMBER_NAME, TYPE)\
SETTER(FUNCTION_NAME, MEMBER_NAME, TYPE)\

#endif // ! GETTER_SETTER_DEFINE_H
