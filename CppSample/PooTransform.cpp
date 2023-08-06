#include "PooTransform.h"
#include "Time.h"
#include "Const.h"
#include "ObjectManager.h"

void PooTransform::OnUpdate()
{
	auto now = Time::GetInstance()->GetTime();
	if (now - lastMovingTime >= secondOfOneUnit)
	{
		lastMovingTime = now;
		position.AddY(Const::DOWN_DIRECTION);
		EmitEvent();
		if (position.GetY() >= Const::FRAME_MAX_Y)
			objectManager->ReserveDestroy(ownerId);
	}
}