#ifndef TIME_H
#define TIME_H

#include <ctime>
#include "SingletonDefine.h"

/**

    @class   Time
    @brief   사용될 시간을 좀 더 사용하기 쉽게 한 번 감싼 클래스, 단위는 초이다. 1500ms -> 1.5f
    @details ~

**/
class Time
{
	SINGLETON_DECLARE(Time);

public:
 /**
     @brief  프로그램 실행 후 시간이 얼마나 흘렀는지 얻어온다. 단위는 초.
     @retval  - 소수점으로 표현된 초를 리턴한다. 2분 -> 120.0f, 1500마이크로초 -> 1.5f
 **/
	float GetTime();
 /**
     @brief  이전 프레임에서 경과된 시간을 리턴한다.
     @retval  - 이전 프레임에서 경과된 시간을 리턴한다.
 **/
	float GetDeltaTime();
 /**
     @brief 시간을 업데이트 한다.
 **/
	void Update();

private:
	std::clock_t currentTime;       //!< 프로그램이 실행 후 얼마나 흘렀는지 저장한다. ms로 측정된다.
	std::clock_t deltaTime;         //!< 전 프레임과 지금 프레임의 시간 간경이 얼마인지 저장한다. ms로 측정된다.
};

#endif // ! TIME_H