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
* �̱��� ������� ����
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

		//�ܼ�ȭ���� ��� ���� �����.
		Console::GetInstance()->Clear();
		
		//update �� update���̿� ������ �Է��� ��� Ű�� �����´�.
		auto keys = FlushInputQueue();
		//��� ��ü�鿡�� �Է��� Ű�� �ִٰ� �˷��ش�.
		for (auto key = keys.begin(); key != keys.end(); key++)
		{
			InputEventParameter inputParameter;
			inputParameter.key = *key;

			objectManager.OnEvent(EventType::KeyInputted, inputParameter);
		}
		//��� ��ü���� ������Ʈ �Ѵ�.
		objectManager.Update();

		Console::GetInstance()->DrawConsole();
		//cpu�� ������ ��� ������ ���� ������
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
