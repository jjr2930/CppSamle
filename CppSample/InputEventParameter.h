#ifndef INPUT_EVENT_PARAMETER_H
#define INPUT_EVENT_PARAMETER_H

#include "EventParameter.h"

/**

    @class   InputEventParameter
    @brief   �Է°� ���õ� �̺�Ʈ�� �Ķ����
    @details ~

**/
class InputEventParameter : public EventParameter
{
public:
	char key;    //!< � Ű�� ���ȴ����� ���� ����
};
#endif // !INPUT_EVENT_PARAMETER_H