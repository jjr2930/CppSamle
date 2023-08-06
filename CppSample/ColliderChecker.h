#ifndef COLLIDER_CHECKER_H
#define COLLIDER_CHECKER_H

#include "Component.h"

/**

    @class   ColliderChecker
    @brief   collider가 충돌했는지 검사하는 컴포넌트이다, Collider에서 직접 검사하지 않는 이유는
    모든 Collider에서 충돌 검사를 하면 아래와 같은 로직이 되어 O(n^2)의 복잡도를 가지지만 
    for(auto col : colliders){
        for(auto otherCol : collider{
            //what to do 
        }
    }
    ColliderChecker에서만 검사를 한다면 검사가 필요한 (여기선 Player 하나) m개가 되고 시간 복잡도는
    m * O(n)의 복잡도를 가진다. 최악의 경우에는 O(n^2)가 될 수 있지만 m을 최소한으로 프로그래머가 제어할 수 
    있기 때문에 사용하였다.
    @details ~

**/
class ColliderChecker : public Component
{
public:

	virtual void OnUpdate();
};

#endif