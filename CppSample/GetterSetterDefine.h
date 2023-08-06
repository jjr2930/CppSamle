#ifndef GETTER_SETTER_DEFINE_H
#define GETTER_SETTER_DEFINE_H

/*
* ������ getter�� setter�� ����� ���� ������ define �Լ���
*/

/**
    @def   GETTER
    @brief ������ getter�� ������ش�.
    @param FUNCTION_NAME - getter�� ����� �Լ��� �̸� GetFUNCTION_NAME �� ��������.
    @param MEMBER_NAME   - getter�Լ��� ���� ��� ���� �̸� 
    @param TYPE          - ��������� Ÿ���̸�
**/
#define GETTER(FUNCTION_NAME, MEMBER_NAME,TYPE) \
TYPE Get ##FUNCTION_NAME() const { return MEMBER_NAME; }

/**
    @def   SETTER
    @brief ������ setter�� ������ش�.
    @param FUNCTION_NAME - setter�� ����� �Լ��� �̸� SetFUNCTION_NAME �� ��������.
    @param MEMBER_NAME   - setter�Լ��� ���� ��� ���� �̸� 
    @param TYPE          - ��������� Ÿ���̸�
**/
#define SETTER(FUNCTION_NAME, MEMBER_NAME,TYPE) \
void Set ##FUNCTION_NAME(const TYPE& value) { MEMBER_NAME = value;}

/**
    @def   GETTER_SETTER
    @brief �ռ� ���ǵ� GETTER�� SETTER define�� ���� getter �� setter�� ����� �ش�.
    @param FUNCTION_NAME - getter�� setter�� ����� �Լ� �̸�, GETTER, SETTER ����,
    @param MEMBER_NAME   - �Լ��� ���� ��� ������ �̸�
    @param TYPE          - ��� ������ Ÿ�� �̸�
**/
#define GETTER_SETTER(FUNCTION_NAME, MEMBER_NAME, TYPE)\
GETTER(FUNCTION_NAME, MEMBER_NAME, TYPE)\
SETTER(FUNCTION_NAME, MEMBER_NAME, TYPE)\

#endif // ! GETTER_SETTER_DEFINE_H
