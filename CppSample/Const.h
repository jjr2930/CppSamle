#ifndef CONST_H
#define CONST_H

/**
    @namespace Const
    @brief     ���ӿ��� ���Ǵ� �ڵ� ������� �� ���� �����Ѵ�.
**/
namespace Const 
{
	const int FRAME_MIN_X = 0;	 //!< �׵θ� x�ּ� �� ����
	const int FRAME_MAX_X = 40;	 //!< �׵θ� x�ִ� �� ����
	const int FRAME_MIN_Y = 0;	 //!< �׵θ� y�ּ� �� ����
	const int FRAME_MAX_Y = 20;	 //!< �׵θ� y�ִ� �� ����

	const int MIN_X = FRAME_MIN_X + 1;	 //!< ������Ʈ���� ������ �� �ִ� x ������ �ּ� ��
	const int MIN_Y = FRAME_MIN_Y + 1;	 //!< ������Ʈ���� ������ �� �ִ� x ������ �ִ� ��
	const int MAX_X = FRAME_MAX_X - 1;	 //!< ������Ʈ���� ������ �� �ִ� y ������ �ּ� ��
	const int MAX_Y = FRAME_MAX_Y - 1;	 //!< ������Ʈ���� ������ �� �ִ� y ������ �ִ� ��

	const int RIGHT_DIRECTION = 1;	 //!< ������ ���� ���� ���� ����
	const int LEFT_DIRECTION = -1;	 //!< ���� ���� ���� ���� ����
	const int DOWN_DIRECTION = 1;	 //!< �Ʒ� ���� ���� ���� ����
	const int UP_DIRECTION = -1;	 //!< �� ���� ���� ���� ����

	const int SCORE_EACH_POO = 1;	 //!< �Ҹ��ϴ� �� �ϳ� �� ����

	const int SCORE_POSITION_X = (MAX_X - MIN_X) / 2;	 //!< ���ھ ����� ��ġ x���� ���� ����
	const int SCORE_POSITION_Y = FRAME_MAX_Y + 1;		 //!< ũ�Ҿ ����� ��ġ y���� ���� ����

	const int LOSE_TEXT_POSITION_Y = FRAME_MAX_Y + 2;	 //!< �й� ǥ�ø� ����� ��ġ y���� ���� ����

	const float SPAWN_DELAY_TIME = 0.1f;	 //!< ���� ���� �Ǵ� ������ �ð�
	const float POO_DOWN_SPEED = 0.5f;	 //!< ���� �������� �ӵ�

	const char GAME_SCENE_OBJECTS_KEY[] = "gameSceneObjects";	 //!< game.json���� ���� ȭ���� �����ϴ� ����� ����̴� �ʵ��� �̸�
}
#endif // ! COMMON_CONST