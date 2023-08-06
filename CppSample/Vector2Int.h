#ifndef VECTOR2INT_H
#define VECTOR2INT_H

/**

    @class   Vector2Int
    @brief   2���� ��ǥ�踦 �̿��ϴµ� ����� Ŭ�����̴�.
    @details ~

**/
class Vector2Int
{
public :
 /**
     @brief Vector2Int ������.
 **/
	Vector2Int();	
 /**
     @brief Vector2Int  ������.
     @param x - x ��ǥ�� �ʱ�ȭ ��
     @param y - y ��ǥ�� �ʱ�ȭ ��
 **/
	Vector2Int(const int& x, const int& y);

 /**
     @brief Vector2Int object �Ҹ���.
 **/
	~Vector2Int();

	//getter and setter
 /**
     @brief  x�� ���� �����´�.
     @retval  x�� ���� �����Ѵ�.
 **/
	int GetX() const;
 /**
     @brief ��� ���� x�� ���� �����Ѵ�.
     @param value - ������ x��
 **/
	void SetX(const int& value);
 /**
     @brief ��� ���� x�� amount��ŭ ��ȭ��Ų��.
     @param amount - ��� ���� x�� �󸶸�ŭ ��ȭ��ų���� ���� ��
 **/
	void AddX(const int& amount);
 /**
     @brief  ��� ���� Y�� �����´�.
     @retval  -��� ���� Y�� ����
 **/
	int GetY() const;
 /**
     @brief ��� ���� Y�� ���� �����Ѵ�.
     @param value - ��� ���� Y�� ������ ��
 **/
	void SetY(const int& value);
 /**
     @brief ��� ���� Y�� ���� ��ȭ�� ��ŭ ��ȭ ��Ų��.
     @param amount - ��ȭ��
 **/
	void AddY(const int& amount);


	//operator overloading
 /**
     @brief  operator* �������� ������ �����Ѵ�.
     @param  source - ���� ����
     @retval        - ������ ��� ���� ���� ���ο� Vector2Int�� �����Ѵ�.
 **/
	Vector2Int operator*(const int& source);
 /**
     @brief  operator/ �������� �������� �����Ѵ�.
     @param  source -  ���� ����
     @retval        -  ������ ��� ���� ���� ���ο� Vector2Int�� �����Ѵ�.
 **/
	Vector2Int operator/(const int& source);
 /**
     @brief  operator+ Vector2Int���� ������ �����Ѵ�, ������� ���� ���Ѵ�.
     @param  source -  ���� vector2Int ���� �־��ش�.
     @retval        - source�� ������ ���ο� Vector2Int�� �����Ѵ�.
 **/
	Vector2Int operator+(const Vector2Int& source);
 /**
     @brief  operator- Vector2Int���� ������ �����Ѵ�, �� ����� ���� ���Ѵ�.
     @param  source -  �� vector2Int ���� �־��ش�.
     @retval        - source�� ������ ���ο� Vector2Int�� �����Ѵ�.
 **/
	Vector2Int operator-(const Vector2Int& source); 
 /**
     @brief  operator+= �ٸ� Vector2Int���� += ������ ���� �Ѵ�.
     @param  source - ���� vector2int ���� �־��ش�.
     @retval        - ������ ���ο� Vector2�� �����Ѵ�.
 **/
	Vector2Int operator+=(const Vector2Int& source);

private:
	int x; //!< x��Ҹ� ǥ���ϴ� ��� ����
	int y; //!< y��Ҹ� ǥ���ϴ� ��� ����
};

#endif // !VECTOR2INT_H