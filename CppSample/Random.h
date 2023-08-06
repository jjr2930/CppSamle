#ifndef RANDOM_H
#define RANDOM_H

#include <random>

/**

    @class   Random
    @brief   랜덤한 숫자를 쉽게 추출하기 위해 만든 클래스
    @details ~

**/
class Random
{
public:
	Random();

 /**
     @brief  이 함수를 이용해 랜덤한 숫자를 얻어온다.
     @param  min - 랜덤 숫자 범위의 최소 값
     @param  max - 랜덤 숫자 범위의 최대 값
     @retval     - min, max 범위 안에서 생성된 랜덤한 숫자
 **/
	int GetRandom(const int& min, const int& max);

private:
	std::random_device randomDevice;             //!< generator의 시드로 사용하기 위해 쓰임
	std::mt19937 generator;                      //!< 더욱 예전의 rand보다 더 훌륭한 난수들을 생성함
	std::uniform_int_distribution<int> dist;     //!< generator의 난수를 이용하여 균등 분포로 정수 하나를 추출함
};


#endif // !RANDOM_H

