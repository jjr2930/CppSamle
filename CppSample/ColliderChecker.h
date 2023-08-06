#ifndef COLLIDER_CHECKER_H
#define COLLIDER_CHECKER_H

#include "Component.h"

/**

    @class   ColliderChecker
    @brief   collider�� �浹�ߴ��� �˻��ϴ� ������Ʈ�̴�, Collider���� ���� �˻����� �ʴ� ������
    ��� Collider���� �浹 �˻縦 �ϸ� �Ʒ��� ���� ������ �Ǿ� O(n^2)�� ���⵵�� �������� 
    for(auto col : colliders){
        for(auto otherCol : collider{
            //what to do 
        }
    }
    ColliderChecker������ �˻縦 �Ѵٸ� �˻簡 �ʿ��� (���⼱ Player �ϳ�) m���� �ǰ� �ð� ���⵵��
    m * O(n)�� ���⵵�� ������. �־��� ��쿡�� O(n^2)�� �� �� ������ m�� �ּ������� ���α׷��Ӱ� ������ �� 
    �ֱ� ������ ����Ͽ���.
    @details ~

**/
class ColliderChecker : public Component
{
public:

	virtual void OnUpdate();
};

#endif