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
    @brief �����ð����� ���� �����ϸ�, object manager���� Poo��� �������� ������ �����Ѵ�.
**/
void PooSpawner::OnUpdate()
{
	auto now = Time::GetInstance()->GetTime();
	if (now - lastSpawnTime >= Const::SPAWN_DELAY_TIME) 
	{
		lastSpawnTime = now;

		//������ ��ġ
		auto randomX = random.GetRandom(Const::MIN_X, Const::MAX_X);
		auto y = 0;

		//������ Poo�� json Value��ü�� ���´�.
		Value& v = objectManager->GetPrefab("Poo");
		
		//������ ���� JSON Value�� �̿��� ��ƼƼ�� �����Ѵ�.
		int entityId = objectManager->BuildEntityFromJson(v);
		
		auto pooTransform = objectManager->GetComponent<PooTransform>(entityId);

		//�˿��� ������ ��ġ��, �������� �ӵ��� �����Ѵ�.
		pooTransform->SetPosition((int)randomX, (int)y);
		pooTransform->SetSecondOfOneUnit(Const::POO_DOWN_SPEED);
	}
}
