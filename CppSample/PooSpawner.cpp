#include "PooSpawner.h"
#include "Time.h"
#include "Const.h"
#include "PooTransform.h"
#include "Renderer.h"
#include "Collider.h"
#include "ObjectManager.h"

#include <iostream>


PooSpawner::PooSpawner()
{
	lastSpawnTime = 0;
	spawnDelayTime = 0;
}

PooSpawner::~PooSpawner()
{
}

/**
    @brief 일정시간마다 똥을 생성하며, object manager에서 Poo라는 프리팹을 가져와 생성한다.
**/
void PooSpawner::OnUpdate()
{
	auto now = Time::GetInstance()->GetTime();
	if (now - lastSpawnTime >= Const::SPAWN_DELAY_TIME) 
	{
		lastSpawnTime = now;

		//랜덤한 위치
		auto randomX = random.GetRandom(Const::MIN_X, Const::MAX_X);
		auto y = 0;

		//프리팹 Poo의 json Value객체를 얻어온다.
		Value& v = objectManager->GetPrefab("Poo");
		
		//위에서 얻어온 JSON Value를 이용해 엔티티를 생성한다.
		int entityId = objectManager->BuildEntityFromJson(v);
		
		auto pooTransform = objectManager->GetComponent<PooTransform>(entityId);

		//똥에게 랜덤한 위치와, 내려가는 속도를 지정한다.
		pooTransform->SetPosition((int)randomX, (int)y);
		pooTransform->SetSecondOfOneUnit(Const::POO_DOWN_SPEED);
	}
}
