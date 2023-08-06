#ifndef SINGLETON_DEFINE_H
#define SINGLETON_DEFINE
/*
* 싱글톤을 구현하기 위한 define 선언들이 작성되어있다. cocos2d의 소스코드를 가져왔다.
*/

/**
    @def   SINGLETON_MAKE_NO_COPY
    @brief 복사 생성자를 다른 곳에서 호출할 수 없도록 private으로 감싼다.
    @param CLASSNAME - 싱글톤으로 만들고 싶은 클래스 이름을 작성한다.
**/
#define SINGLETON_MAKE_NO_COPY(CLASSNAME)  \
private:\
    CLASSNAME(const CLASSNAME&);\
    CLASSNAME& operator=(const CLASSNAME&);\

/**
    @def   SINGLETON_DECLARE
    @brief 싱글톤과 관련된 함수와 멤버변수를 선언한다. 외부에서 생성할 수 없도록 생성자를 private으로 둔다.
    @param CLASSNAME - 싱글톤으로 만들고 싶은 클래스의 이름을 작성한다.
**/
#define SINGLETON_DECLARE(CLASSNAME)    \
SINGLETON_MAKE_NO_COPY(CLASSNAME)  \
public:\
	static CLASSNAME* GetInstance();\
private:\
	static CLASSNAME* instance;\
	CLASSNAME();\
    void Init();\

/**
    @def   SINGLETON_IMPLIMETATION
    @brief SINGLETON_DECLARE를 통해 선언한 멤버들을 정의하는 define이다. 멀티스레드에 대한 고려는 현재 없다.
    @param CLASSNAME - 싱글톤으로 만들고 싶은 클래스 이름을 작성한다.
**/
#define SINGLETON_IMPLIMETATION(CLASSNAME)\
CLASSNAME* CLASSNAME::instance = nullptr;\
CLASSNAME* CLASSNAME::GetInstance() {\
    if(instance == nullptr)\
        instance = new CLASSNAME();\
    return instance;\
}\
CLASSNAME::CLASSNAME(){\
    Init();\
}\
void CLASSNAME::Init()\

#endif // ! SINGLETON_DEFINE_H

