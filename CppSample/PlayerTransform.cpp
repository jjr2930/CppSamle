#include "PlayerTransform.h"
#include "InputEventParameter.h"
#include "Const.h"

void PlayerTransform::OnStart()
{
	ClampPosition();
	Transform::OnStart();
}

/**
    @brief 키 입력을 받아들여 플레이어의 위치를 이동하고, 이동된 위치에 관한 이벤트를 방출한다.
    @param eventType - 이 클래스는 KeyInputted 이벤트를 듣는다.
    @param parameter - 무엇을 눌렀는지에 대한 정보가 들어있다.
**/
void PlayerTransform::OnEvent(const EventType& eventType, EventParameter& parameter)
{
	switch (eventType)
	{
		case EventType::KeyInputted:
			{
				auto inputEventParameter = static_cast<InputEventParameter&>(parameter);
				switch (inputEventParameter.key)
				{
					case 'a':
					case 'A':
						{
							this->position.AddX(Const::LEFT_DIRECTION);
							ClampPosition();
							EmitEvent();
						}
						break;

					case 'd':
					case 'D':
						{
							this->position.AddX(Const::RIGHT_DIRECTION);
							ClampPosition();
							EmitEvent();
						}
						break;
				}
			}
			break;
		default:
			break;
	}
}

void PlayerTransform::ClampPosition()
{
	if (position.GetX() < Const::MIN_X)
		position.SetX(Const::MIN_X);

	else if (position.GetX() > Const::MAX_X)
		position.SetX(Const::MAX_X);

	if (position.GetY() < Const::MIN_Y)
		position.SetY(Const::MIN_Y);

	else if (position.GetY() > Const::MAX_Y)
		position.SetY(Const::MAX_Y);
}
