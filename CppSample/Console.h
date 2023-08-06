#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

#include "SingletonDefine.h"
/**

    @class   Console
    @brief   �ܼ�ȭ�� ��Ʈ���� ���� Ŭ����
    @details ~

**/
class Console
{
	/*
	* �̱��� ������� ����
	*/
	SINGLETON_DECLARE(Console)

public:

 /**
     @brief �ܼ�ȭ���� ��� �����.
 **/
    void Clear();

    /**
        @brief �ܼ��� �� ĭ �� ĭ�� �ȼ��� �ٷ��, ���� �ȼ��������� � ���ڸ� ������� ���Ѵ�.
        @param x     - �ȼ��� ��ǥ x��, 0������
        @param y     - �ȼ��� ��ǥ y��, 0�ֻ�� 
        @param value - ����� ����
    **/
    void SetPixel(const int& x, const int& y, const std::string value);
    /**
        @brief �ֿܼ� pixels�� ����� ������ �׸���.
        ���� ���������� �̷��� �׸��� ȭ���� �����Ÿ��� �ʴ´�.
    **/
    void DrawConsole();
private:
    size_t consoleWidth;     //!< ������ �� �ܼ��� ���� ĭ ����
    size_t consoleHeight;    //!< ������ �� �ܼ��� ���� ĭ ����
    char* pixels;            //!< ��ǥ���� ȭ�鿡 ��� �׸����� ���� ������ ������ �ִ�.
};


#endif // !CONSOLE_H

