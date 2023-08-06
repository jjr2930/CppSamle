#ifndef POO_TRANSFORM_H
#define POO_TRANSFORM_H

#include "Transform.h"
#include "GetterSetterDefine.h"

#include <ctime>

/**

    @class   PooTransform
    @brief   ���� ��ġ ������ ���� ��ȵ� ������Ʈ
    @details ~

**/
class PooTransform : public Transform
{
public :
	virtual void OnUpdate();

	//setter
	SETTER(SecondOfOneUnit, secondOfOneUnit, float);

private:
	float lastMovingTime;	 //!< ������ ������ �ð��� �����ΰ�.
	float secondOfOneUnit;	 //!< ��ĭ�� �����̴µ� �ʿ��� �ð��� ���ΰ�.
};
#endif // !POO_TRANSFORM_H

