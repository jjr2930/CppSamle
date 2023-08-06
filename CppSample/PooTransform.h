#ifndef POO_TRANSFORM_H
#define POO_TRANSFORM_H

#include "Transform.h"
#include "GetterSetterDefine.h"

#include <ctime>

/**

    @class   PooTransform
    @brief   똥의 위치 조정을 위해 고안된 컴포넌트
    @details ~

**/
class PooTransform : public Transform
{
public :
	virtual void OnUpdate();

	//setter
	SETTER(SecondOfOneUnit, secondOfOneUnit, float);

private:
	float lastMovingTime;	 //!< 이전에 움직인 시간이 언제인가.
	float secondOfOneUnit;	 //!< 한칸을 움직이는데 필요한 시간은 얼마인가.
};
#endif // !POO_TRANSFORM_H

