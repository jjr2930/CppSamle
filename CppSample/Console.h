#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

#include "SingletonDefine.h"
/**

    @class   Console
    @brief   콘솔화면 컨트롤을 위한 클래스
    @details ~

**/
class Console
{
	/*
	* 싱글톤 멤버변수 선언
	*/
	SINGLETON_DECLARE(Console)

public:

 /**
     @brief 콘솔화면을 모두 지운다.
 **/
    void Clear();

    /**
        @brief 콘솔의 한 칸 한 칸을 픽셀로 다루고, 시작 픽셀에서부터 어떤 문자를 적어둘지 정한다.
        @param x     - 픽셀의 좌표 x값, 0최좌측
        @param y     - 픽셀의 좌표 y값, 0최상단 
        @param value - 적어둘 문자
    **/
    void SetPixel(const int& x, const int& y, const std::string value);
    /**
        @brief 콘솔에 pixels에 저장된 내용을 그린다.
        조금 복잡하지만 이렇게 그리면 화면이 깜빡거리지 않는다.
    **/
    void DrawConsole();
private:
    size_t consoleWidth;     //!< 시작할 때 콘솔의 가로 칸 갯수
    size_t consoleHeight;    //!< 시작할 때 콘솔의 세로 칸 갯수
    char* pixels;            //!< 좌표별로 화면에 어떻게 그릴지에 대한 정보를 가지고 있다.
};


#endif // !CONSOLE_H

