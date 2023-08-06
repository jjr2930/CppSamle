#include <thread>
#include <chrono>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
#include <iostream>

#include "Const.h"
#include "CommonDefineMethod.h"
#include "InputEventParameter.h"
#include "Time.h"
#include "Console.h"
#include "Game.h"

/*
* 싱글톤 멤버들의 정의
*/
SINGLETON_IMPLIMETATION(Game){}

void Game::Input()
{
	while (true) 
	{
		auto key = _getch();
		if (key == 0x00 || key == 0xE0) 
		{
			key = _getch();
			//nothing to do extension key(like f1,f2)
		}
		else
		{
			EnqueueKey(key);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(inputSleepTime));
	}
}

void Game::Start()
{
	objectManager.Start();
	inputThread = std::thread(&Game::Input, this);
}

void Game::Update()
{
	while (false == isFinished) 
	{
		Time::GetInstance()->Update();

		//콘솔화면의 모든 것을 지운다.
		Console::GetInstance()->Clear();
		
		//update 와 update사이에 유저가 입력한 모든 키를 가져온다.
		auto keys = FlushInputQueue();
		//모든 객체들에게 입력한 키가 있다고 알려준다.
		for (auto key = keys.begin(); key != keys.end(); key++)
		{
			InputEventParameter inputParameter;
			inputParameter.key = *key;

			objectManager.OnEvent(EventType::KeyInputted, inputParameter);
		}
		//모든 객체들을 업데이트 한다.
		objectManager.Update();

		Console::GetInstance()->DrawConsole();
		//cpu의 과도한 사용 방지를 위해 쉬어줌
		std::this_thread::sleep_for(std::chrono::milliseconds(updateSleepTime));
	}

	Console::GetInstance()->SetPixel(0, Const::LOSE_TEXT_POSITION_Y, "you lose!!");
	Console::GetInstance()->DrawConsole();
	_getch();
}

void Game::EnqueueKey(const char& key)
{
	std::lock_guard<std::mutex> guard(enqueueMutex);
	inputKeyQueue.push(key);
}

std::vector<char> Game::FlushInputQueue()
{
	std::lock_guard<std::mutex> guard(enqueueMutex);
	std::vector<char> result;

	while (false == inputKeyQueue.empty())
	{
		auto poped = DEQUEUE(inputKeyQueue);
		result.push_back(poped);
	}

	return result;
}
