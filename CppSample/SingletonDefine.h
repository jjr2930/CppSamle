#ifndef SINGLETON_DEFINE_H
#define SINGLETON_DEFINE
/*
* �̱����� �����ϱ� ���� define ������� �ۼ��Ǿ��ִ�. cocos2d�� �ҽ��ڵ带 �����Դ�.
*/

/**
    @def   SINGLETON_MAKE_NO_COPY
    @brief ���� �����ڸ� �ٸ� ������ ȣ���� �� ������ private���� ���Ѵ�.
    @param CLASSNAME - �̱������� ����� ���� Ŭ���� �̸��� �ۼ��Ѵ�.
**/
#define SINGLETON_MAKE_NO_COPY(CLASSNAME)  \
private:\
    CLASSNAME(const CLASSNAME&);\
    CLASSNAME& operator=(const CLASSNAME&);\

/**
    @def   SINGLETON_DECLARE
    @brief �̱���� ���õ� �Լ��� ��������� �����Ѵ�. �ܺο��� ������ �� ������ �����ڸ� private���� �д�.
    @param CLASSNAME - �̱������� ����� ���� Ŭ������ �̸��� �ۼ��Ѵ�.
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
    @brief SINGLETON_DECLARE�� ���� ������ ������� �����ϴ� define�̴�. ��Ƽ�����忡 ���� ����� ���� ����.
    @param CLASSNAME - �̱������� ����� ���� Ŭ���� �̸��� �ۼ��Ѵ�.
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

