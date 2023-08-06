#ifndef VECTOR2INT_H
#define VECTOR2INT_H

/**

    @class   Vector2Int
    @brief   2차원 좌표계를 이용하는데 사용할 클래스이다.
    @details ~

**/
class Vector2Int
{
public :
 /**
     @brief Vector2Int 생성자.
 **/
	Vector2Int();	
 /**
     @brief Vector2Int  생성자.
     @param x - x 좌표의 초기화 값
     @param y - y 좌표의 초기화 값
 **/
	Vector2Int(const int& x, const int& y);

 /**
     @brief Vector2Int object 소멸자.
 **/
	~Vector2Int();

	//getter and setter
 /**
     @brief  x의 값을 가져온다.
     @retval  x의 값을 리턴한다.
 **/
	int GetX() const;
 /**
     @brief 멤버 변수 x의 값을 지정한다.
     @param value - 변경할 x값
 **/
	void SetX(const int& value);
 /**
     @brief 멤버 변수 x를 amount만큼 변화시킨다.
     @param amount - 멤버 변수 x를 얼마만큼 변화시킬지에 대한 값
 **/
	void AddX(const int& amount);
 /**
     @brief  멤버 변수 Y를 가져온다.
     @retval  -멤버 변수 Y를 리턴
 **/
	int GetY() const;
 /**
     @brief 멤버 변수 Y의 값을 지정한다.
     @param value - 멤버 변수 Y에 지정할 값
 **/
	void SetY(const int& value);
 /**
     @brief 멤버 변수 Y의 값을 변화량 만큼 변화 시킨다.
     @param amount - 변화량
 **/
	void AddY(const int& amount);


	//operator overloading
 /**
     @brief  operator* 정수와의 곱셈을 정의한다.
     @param  source - 곱할 정수
     @retval        - 연산의 결과 값을 가진 새로운 Vector2Int를 리턴한다.
 **/
	Vector2Int operator*(const int& source);
 /**
     @brief  operator/ 정수와의 나눗셈을 정의한다.
     @param  source -  나눌 정수
     @retval        -  연산의 결과 값을 가진 새로운 Vector2Int를 리턴한다.
 **/
	Vector2Int operator/(const int& source);
 /**
     @brief  operator+ Vector2Int와의 덧셈을 정의한다, 각요소의 합을 구한다.
     @param  source -  더할 vector2Int 값을 넣어준다.
     @retval        - source가 더해진 새로운 Vector2Int를 리턴한다.
 **/
	Vector2Int operator+(const Vector2Int& source);
 /**
     @brief  operator- Vector2Int와의 뺄셈을 정의한다, 각 요소의 차를 구한다.
     @param  source -  뺄 vector2Int 값을 넣어준다.
     @retval        - source가 차감된 새로운 Vector2Int를 리턴한다.
 **/
	Vector2Int operator-(const Vector2Int& source); 
 /**
     @brief  operator+= 다른 Vector2Int와의 += 연산을 정의 한다.
     @param  source - 더할 vector2int 값을 넣어준다.
     @retval        - 더해진 새로운 Vector2를 리턴한다.
 **/
	Vector2Int operator+=(const Vector2Int& source);

private:
	int x; //!< x요소를 표현하는 멤버 변수
	int y; //!< y요소를 표현하는 멤버 변수
};

#endif // !VECTOR2INT_H