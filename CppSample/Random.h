#ifndef RANDOM_H
#define RANDOM_H

#include <random>

/**

    @class   Random
    @brief   ������ ���ڸ� ���� �����ϱ� ���� ���� Ŭ����
    @details ~

**/
class Random
{
public:
	Random();

 /**
     @brief  �� �Լ��� �̿��� ������ ���ڸ� ���´�.
     @param  min - ���� ���� ������ �ּ� ��
     @param  max - ���� ���� ������ �ִ� ��
     @retval     - min, max ���� �ȿ��� ������ ������ ����
 **/
	int GetRandom(const int& min, const int& max);

private:
	std::random_device randomDevice;             //!< generator�� �õ�� ����ϱ� ���� ����
	std::mt19937 generator;                      //!< ���� ������ rand���� �� �Ǹ��� �������� ������
	std::uniform_int_distribution<int> dist;     //!< generator�� ������ �̿��Ͽ� �յ� ������ ���� �ϳ��� ������
};


#endif // !RANDOM_H

