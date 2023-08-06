#ifndef POO_SPANWER_H
#define POO_SPANWER_H

#include "Component.h"
#include "GetterSetterDefine.h"
#include "Random.h"

/**

    @class   PooSpawner
    @brief   똥을 생성하는 클래스
    @details ~

**/
class PooSpawner : public Component
{
public:
	PooSpawner();
	virtual ~PooSpawner();

	//getter setter
	virtual void OnUpdate();

	//getter setter
	GETTER_SETTER(SpawnDelayTime, spawnDelayTime, float);

private:
	float lastSpawnTime;	 //!< 가장 최근에 똥을 생성한 시간.
	float spawnDelayTime;	 //!< 똥을 생산할 때의 딜레이
	Random random;			 //!< 랜덤한 위치를 추출할 때 쓰일 랜덤 객체
};

#endif //!POO_SPANWER_H