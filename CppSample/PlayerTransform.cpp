#include "PlayerTransform.h"
#include "InputEventParameter.h"
#include "Const.h"

void PlayerTransform::OnStart()
{
	ClampPosition();
	Transform::OnStart();
}

/**
    @brief Ű �Է��� �޾Ƶ鿩 �÷��̾��� ��ġ�� �̵��ϰ�, �̵��� ��ġ�� ���� �̺�Ʈ�� �����Ѵ�.
    @param eventType - �� Ŭ������ KeyInputted �̺�Ʈ�� ��´�.
    @param parameter - ������ ���������� ���� ������ ����ִ�.
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
