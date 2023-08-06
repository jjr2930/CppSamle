#ifndef GAME_H
#define GAME_H

#include <queue>
#include <mutex>

#include "ObjectManager.h"
#include "SingletonDefine.h"
#include "GetterSetterDefine.h"

/**

    @class   Game
    @brief   게임 루프를 돌리는 객체
    @details ~

**/
class Game
{
	/*
	* 싱글톤에 필요한 멤버들을 선언한다.
	*/
	SINGLETON_DECLARE(Game)

public:
 /**
     @brief 사용자의 키보드 입력을 받아온다. 메인스레드가 아닌 별도에 스레드에서 작동한다.
	 사용자가 무언가 버튼을 누르면 inputKeyQueue에 해당 키가 enqueue된다.
	 Update에서 눌린 키들을 ObjectManager를 통하여 전달한다.
 **/
	void Input();

 /**
     @brief 게임 초기화를 위한 함수
 **/
	void Start();

 /**
     @brief 게임 업데이트를 위한 함수
 **/
	void Update();

 /**
     @brief inputKeyQueue 에 키를 넣는다.
     @param key - 유저가 입력한 키
 **/
	void EnqueueKey(const char& key);

 /**
     @brief  inputKeyQueue를 Dequeue통하여 vector로 변환하고 그것을 리턴한다.
     @retval  - Dequeue된 키 값들이 들어있다. 입력된 키가 없다면 size가 0인 vector가 리턴된다.
 **/
	std::vector<char> FlushInputQueue();

	//getter setter
	GETTER_SETTER(IsFinished, isFinished, bool)

private:
	std::queue<char> inputKeyQueue;		 //!< 사용자가 누른 키를 순서대로 저장한다.
	std::mutex enqueueMutex;			 //!< EnqueueKey 함수에 사용되는 뮤텍스 lock을 위해 사용된다.
	int inputSleepTime = 1;				 //!< 무한 반복문을 돌릴 때 약간의 sleep시간을 주어 cpu의 과도한 사용을 막는다.
	int updateSleepTime = 1000/30;		 //!< 업데이트가 쉬는 시간은 얼마로 할지 약 30fps으로 업데이트 되도록한다.
	ObjectManager objectManager;		 //!< 게임내 거의 모든 객체를 관리하는 객체를 가지고 있는다.
	bool isFinished;					 //!< 게임이 끝났는지 체크할 변수
	std::thread inputThread;			 //!< Input 함수가 돌아가는 스레드
};

#endif // !GAME_H

