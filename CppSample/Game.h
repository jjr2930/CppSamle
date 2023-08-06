#ifndef GAME_H
#define GAME_H

#include <queue>
#include <mutex>

#include "ObjectManager.h"
#include "SingletonDefine.h"
#include "GetterSetterDefine.h"

/**

    @class   Game
    @brief   ���� ������ ������ ��ü
    @details ~

**/
class Game
{
	/*
	* �̱��濡 �ʿ��� ������� �����Ѵ�.
	*/
	SINGLETON_DECLARE(Game)

public:
 /**
     @brief ������� Ű���� �Է��� �޾ƿ´�. ���ν����尡 �ƴ� ������ �����忡�� �۵��Ѵ�.
	 ����ڰ� ���� ��ư�� ������ inputKeyQueue�� �ش� Ű�� enqueue�ȴ�.
	 Update���� ���� Ű���� ObjectManager�� ���Ͽ� �����Ѵ�.
 **/
	void Input();

 /**
     @brief ���� �ʱ�ȭ�� ���� �Լ�
 **/
	void Start();

 /**
     @brief ���� ������Ʈ�� ���� �Լ�
 **/
	void Update();

 /**
     @brief inputKeyQueue �� Ű�� �ִ´�.
     @param key - ������ �Է��� Ű
 **/
	void EnqueueKey(const char& key);

 /**
     @brief  inputKeyQueue�� Dequeue���Ͽ� vector�� ��ȯ�ϰ� �װ��� �����Ѵ�.
     @retval  - Dequeue�� Ű ������ ����ִ�. �Էµ� Ű�� ���ٸ� size�� 0�� vector�� ���ϵȴ�.
 **/
	std::vector<char> FlushInputQueue();

	//getter setter
	GETTER_SETTER(IsFinished, isFinished, bool)

private:
	std::queue<char> inputKeyQueue;		 //!< ����ڰ� ���� Ű�� ������� �����Ѵ�.
	std::mutex enqueueMutex;			 //!< EnqueueKey �Լ��� ���Ǵ� ���ؽ� lock�� ���� ���ȴ�.
	int inputSleepTime = 1;				 //!< ���� �ݺ����� ���� �� �ణ�� sleep�ð��� �־� cpu�� ������ ����� ���´�.
	int updateSleepTime = 1000/30;		 //!< ������Ʈ�� ���� �ð��� �󸶷� ���� �� 30fps���� ������Ʈ �ǵ����Ѵ�.
	ObjectManager objectManager;		 //!< ���ӳ� ���� ��� ��ü�� �����ϴ� ��ü�� ������ �ִ´�.
	bool isFinished;					 //!< ������ �������� üũ�� ����
	std::thread inputThread;			 //!< Input �Լ��� ���ư��� ������
};

#endif // !GAME_H

