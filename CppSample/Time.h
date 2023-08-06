#ifndef TIME_H
#define TIME_H

#include <ctime>
#include "SingletonDefine.h"

/**

    @class   Time
    @brief   ���� �ð��� �� �� ����ϱ� ���� �� �� ���� Ŭ����, ������ ���̴�. 1500ms -> 1.5f
    @details ~

**/
class Time
{
	SINGLETON_DECLARE(Time);

public:
 /**
     @brief  ���α׷� ���� �� �ð��� �󸶳� �귶���� ���´�. ������ ��.
     @retval  - �Ҽ������� ǥ���� �ʸ� �����Ѵ�. 2�� -> 120.0f, 1500����ũ���� -> 1.5f
 **/
	float GetTime();
 /**
     @brief  ���� �����ӿ��� ����� �ð��� �����Ѵ�.
     @retval  - ���� �����ӿ��� ����� �ð��� �����Ѵ�.
 **/
	float GetDeltaTime();
 /**
     @brief �ð��� ������Ʈ �Ѵ�.
 **/
	void Update();

private:
	std::clock_t currentTime;       //!< ���α׷��� ���� �� �󸶳� �귶���� �����Ѵ�. ms�� �����ȴ�.
	std::clock_t deltaTime;         //!< �� �����Ӱ� ���� �������� �ð� ������ ������ �����Ѵ�. ms�� �����ȴ�.
};

#endif // ! TIME_H