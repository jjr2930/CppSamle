#ifndef CONST_H
#define CONST_H

/**
    @namespace Const
    @brief     게임에서 사용되는 코든 상수들을 이 곳에 정의한다.
**/
namespace Const 
{
	const int FRAME_MIN_X = 0;	 //!< 테두리 x최소 값 정의
	const int FRAME_MAX_X = 40;	 //!< 테두리 x최대 값 정의
	const int FRAME_MIN_Y = 0;	 //!< 테두리 y최소 값 정의
	const int FRAME_MAX_Y = 20;	 //!< 테두리 y최대 값 정의

	const int MIN_X = FRAME_MIN_X + 1;	 //!< 오브젝트들이 움직일 수 있는 x 범위의 최소 값
	const int MIN_Y = FRAME_MIN_Y + 1;	 //!< 오브젝트들이 움직일 수 있는 x 범위의 최대 값
	const int MAX_X = FRAME_MAX_X - 1;	 //!< 오브젝트들이 움직일 수 있는 y 범위의 최소 값
	const int MAX_Y = FRAME_MAX_Y - 1;	 //!< 오브젝트들이 움직일 수 있는 y 범위의 최대 값

	const int RIGHT_DIRECTION = 1;	 //!< 오른쪽 방향 값에 대한 정의
	const int LEFT_DIRECTION = -1;	 //!< 왼쪽 방향 값에 대한 정의
	const int DOWN_DIRECTION = 1;	 //!< 아래 방향 값에 대한 정의
	const int UP_DIRECTION = -1;	 //!< 위 방향 값에 대한 정의

	const int SCORE_EACH_POO = 1;	 //!< 소멸하는 똥 하나 당 점수

	const int SCORE_POSITION_X = (MAX_X - MIN_X) / 2;	 //!< 스코어를 출력할 위치 x값에 대한 정의
	const int SCORE_POSITION_Y = FRAME_MAX_Y + 1;		 //!< 크소어를 출력할 위치 y값에 대한 정의

	const int LOSE_TEXT_POSITION_Y = FRAME_MAX_Y + 2;	 //!< 패배 표시를 출력할 위치 y값에 대한 정의

	const float SPAWN_DELAY_TIME = 0.1f;	 //!< 똥이 생성 되는 딜레이 시간
	const float POO_DOWN_SPEED = 0.5f;	 //!< 똥이 내려가는 속도

	const char GAME_SCENE_OBJECTS_KEY[] = "gameSceneObjects";	 //!< game.json에서 게임 화면을 구성하는 목록을 담고이는 필드의 이름
}
#endif // ! COMMON_CONST