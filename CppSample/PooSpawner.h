#ifndef POO_SPANWER_H
#define POO_SPANWER_H

#include "Component.h"
#include "GetterSetterDefine.h"
#include "Random.h"

/**

    @class   PooSpawner
    @brief   ���� �����ϴ� Ŭ����
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
	float lastSpawnTime;	 //!< ���� �ֱٿ� ���� ������ �ð�.
	float spawnDelayTime;	 //!< ���� ������ ���� ������
	Random random;			 //!< ������ ��ġ�� ������ �� ���� ���� ��ü
};

#endif //!POO_SPANWER_H